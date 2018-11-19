#include <vector>
#include <iostream>
using namespace std;

/*
*Merge sort
*Insertion Sort
*Bubble sort
*Quick Sort
*Heap sort
*Counting sort*/

/*Prints the array elements*/
void printArray(vector<int> elems) {
	for (unsigned int i = 0; i < elems.size(); i++) {
		cout << elems[i] << " ";
	}
	cout << endl;
}

//function to merge 2 halves together
void merge(vector<int> &nums, int mid, int low, int high) {
	// We have low to mid and mid+1 to high already sorted.
	vector<int> temp (nums.size());
	int i = low;
	int j = mid + 1;
	int t = low;

	//Merge the 2 parts into temp
	while (i <= mid && j <= high) {
		if (nums[i] < nums[j]) {
			temp[t] = nums[i];
			t++;
			i++;
		}
		else {
			temp[t] = nums[j];
			t++;
			j++;
		}
	}

	//Insert all the remaining values from i to mid into
	while (i <= mid) {
		temp[t] = nums[i];
		t++;
		i++;
	}

	//Insert all the remaining values from j to high int
	while (j <= high) {
		temp[t] = nums[j];
		t++;
		j++;
	}

	//Assign sorted data stored in temp[] to nums[]
	for (i = low; i < t; i++) {
		nums[i] = temp[i];
	}
}

//Create helper function merge - takes in a position or 2 sorted arrays and merges them in a sort order
void mergeSort(vector<int> &nums, int low, int high) {
	//base case, if there is only one element
	if (nums.size() <= 1) {
		cout << "Array has " << nums.size() << " elements." << endl;
	}
	//split the vector in half
	//use recursion to sort
	//merge the two results and return results
	if (low < high) {
		int mid = (low + high) / 2;

		mergeSort(nums, low, mid);
		mergeSort(nums, mid + 1, high);

		merge(nums, mid, low, high);
	}
}


vector<int> insertionSort(vector<int> elem) {
	/*Compare one element at a time*/
	int temp = 0;
	for (unsigned int i = 1; i < elem.size(); i++) {
		int key = elem[i];
		int j = i - 1;

		while(j >= 0 && elem[j] > key) {
			elem[j + 1] = elem[j];
			j--;
		}
		elem[j + 1] = key;
	}

	return elem;
}

//Bubble sort  & Quick sort helper function
void swap(int *elem1, int *elem2) {
	int temp = *elem1;
	*elem1 = *elem2;
	*elem2 = temp;
}

//compare each pair of elements in an array and swaps them
void bubbleSort(vector<int>& elem) {
	for (int i = 0; i < elem.size() - 1; i++) {
		for (int j = 0; j < elem.size() - i - 1; j++) {
			if (elem[j] > elem[j + 1])
				swap(&elem[j], &elem[j + 1]);
		}
	}
}


int partition(vector<int>& elem, int low, int high) {
	int pivot = elem[high]; //pivot
	int i = (low - 1); //Index of a smaller element

	for (int j = low; j <= high - 1; j++) {
		if (elem[j] <= pivot) {
			i++;
			swap(&elem[i], &elem[j]);
		}
	}

	swap(&elem[i + 1], &elem[high]);
	return(i + 1);
}

//Pick a pivot element
//Compare each element until one element is smaller than the pivot
//Then once swapped, get a new pivot by incrementing
void quickSort(vector<int>& elem, int low, int high) {
	if (low < high) {
		int pi = partition(elem, low, high);

		quickSort(elem, low, pi - 1);
		quickSort(elem, pi + 1, high);
	}
}


//Heap sort helper
void heapify(vector<int>& arr, int size, int root)
{
	int largest = root; // Initialize largest as root 
	int left = 2 * root + 1; // left = 2*i + 1 
	int right = 2 * root + 2; // right = 2*i + 2 

	// If left child is larger than root 
	if (left < size && arr[left] > arr[largest])
		largest = left;

	// If right child is larger than largest so far 
	if (right < size && arr[right] > arr[largest])
		largest = right;

	// If largest is not root 
	if (largest != root)
	{
		swap(arr[root], arr[largest]);

		// Recursively heapify the affected sub-tree 
		heapify(arr, size, largest);
	}

	//printArray(arr);
}

//Heap Sort
void heapSort(vector<int>& elem) {
	for (int i = elem.size()/2 - 1; i >= 0; i--) {
		heapify(elem, elem.size(), i);
	}

	for (int i = elem.size() - 1; i >= 0; i--) {
		//Move current root to end
		swap(elem[0], elem[i]);

		//call max heapify
		heapify(elem, i, 0);
	}
}


int main() {

	//Merge Sort tests
	cout << "Merge Sort" << endl;
	vector<int> elements = { 10, 3, 9, 2, 1,4, 6, 5, 7, 8 };
	mergeSort(elements, 0, elements.size() - 1);
	printArray(elements);
	cout << endl;

	//Insertion sort tests
	cout << "Insertion Sort" << endl;
	vector<int> insertElements = { 10, 3, 9, 2, 1,4, 6, 5, 7, 8 };
	vector<int> sorted;
	sorted = insertionSort(insertElements);
	printArray(sorted);
	cout << endl;

	//Bubble sort test
	cout << "Bubble Sort" << endl;
	vector<int> bubbleElements = { 10, 3, 9, 2, 1,4, 6, 5, 7, 8 };
	bubbleSort(bubbleElements);
	printArray(bubbleElements);
	cout << endl;

	//Quick sort test
	cout << "Quick Sort" << endl;
	vector<int> quickElements = { 10, 3, 9, 2, 1,4, 6, 5, 7, 8 };
	quickSort(quickElements, 0, quickElements.size() - 1);
	printArray(quickElements);
	cout << endl;

	//Heap sort test
	cout << "Heap sort" << endl;
	vector<int> heapElements = { 10, 3, 9, 2, 1,4, 6, 5, 7, 8 };
	heapSort(heapElements);
	printArray(heapElements);
	cout << endl;

	return 0;
}