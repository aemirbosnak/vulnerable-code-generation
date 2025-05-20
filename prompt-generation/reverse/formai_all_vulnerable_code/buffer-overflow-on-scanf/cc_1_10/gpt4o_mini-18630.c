//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

void generateArray(int arr[], int n);
void printArray(int arr[], int n);
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);

int main() {
    int arr[MAX_SIZE];
    int n;

    printf("Enter the number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    if(n > MAX_SIZE || n <= 0) {
        printf("Invalid number of elements. Please enter a value between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    generateArray(arr, n);

    printf("\nOriginal Array:\n");
    printArray(arr, n);

    // Bubble Sort
    int bubbleArr[MAX_SIZE];
    for (int i = 0; i < n; i++)
        bubbleArr[i] = arr[i];
    bubbleSort(bubbleArr, n);
    printf("\nBubble Sorted Array:\n");
    printArray(bubbleArr, n);

    // Selection Sort
    int selectionArr[MAX_SIZE];
    for (int i = 0; i < n; i++)
        selectionArr[i] = arr[i];
    selectionSort(selectionArr, n);
    printf("\nSelection Sorted Array:\n");
    printArray(selectionArr, n);

    // Insertion Sort
    int insertionArr[MAX_SIZE];
    for (int i = 0; i < n; i++)
        insertionArr[i] = arr[i];
    insertionSort(insertionArr, n);
    printf("\nInsertion Sorted Array:\n");
    printArray(insertionArr, n);

    // Merge Sort
    int mergeArr[MAX_SIZE];
    for (int i = 0; i < n; i++)
        mergeArr[i] = arr[i];
    mergeSort(mergeArr, 0, n - 1);
    printf("\nMerge Sorted Array:\n");
    printArray(mergeArr, n);

    // Quick Sort
    int quickArr[MAX_SIZE];
    for (int i = 0; i < n; i++)
        quickArr[i] = arr[i];
    quickSort(quickArr, 0, n - 1);
    printf("\nQuick Sorted Array:\n");
    printArray(quickArr, n);

    // Heap Sort
    int heapArr[MAX_SIZE];
    for (int i = 0; i < n; i++)
        heapArr[i] = arr[i];
    heapSort(heapArr, n);
    printf("\nHeap Sorted Array:\n");
    printArray(heapArr, n);

    return 0;
}

void generateArray(int arr[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;  // Generate random numbers between 0 and 99
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}