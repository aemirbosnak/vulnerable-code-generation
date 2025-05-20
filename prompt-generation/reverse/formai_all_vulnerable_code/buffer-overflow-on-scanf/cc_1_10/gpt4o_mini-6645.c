//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
void bubbleSort(int arr[], int n);
void quickSort(int arr[], int low, int high);
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void generateRandomArray(int arr[], int n);
void printArray(int arr[], int n);
void benchmarkSortingAlgorithms(int n);

int main() {
    int n;

    printf("Welcome to the C Sorting Benchmarking Program!\n");
    printf("Enter the number of elements you wish to sort: ");
    scanf("%d", &n);

    // Validate input
    if (n <= 0) {
        printf("Please enter a positive integer!\n");
        return 1;
    }

    // Perform benchmarking
    benchmarkSortingAlgorithms(n);

    return 0;
}

void benchmarkSortingAlgorithms(int n) {
    int *arr = (int *)malloc(n * sizeof(int));
    
    // Check for memory allocation
    if (!arr) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    generateRandomArray(arr, n);

    printf("\nBenchmarking Bubble Sort...\n");
    int *bubbleArr = (int *)malloc(n * sizeof(int));
    if (!bubbleArr) exit(1);
    for (int i = 0; i < n; i++) bubbleArr[i] = arr[i];

    clock_t start = clock();
    bubbleSort(bubbleArr, n);
    clock_t end = clock();
    printf("Bubble Sort took %lf seconds.\n", (double)(end - start) / CLOCKS_PER_SEC);
    free(bubbleArr);

    printf("\nBenchmarking Quick Sort...\n");
    int *quickArr = (int *)malloc(n * sizeof(int));
    if (!quickArr) exit(1);
    for (int i = 0; i < n; i++) quickArr[i] = arr[i];

    start = clock();
    quickSort(quickArr, 0, n - 1);
    end = clock();
    printf("Quick Sort took %lf seconds.\n", (double)(end - start) / CLOCKS_PER_SEC);
    free(quickArr);

    printf("\nBenchmarking Merge Sort...\n");
    int *mergeArr = (int *)malloc(n * sizeof(int));
    if (!mergeArr) exit(1);
    for (int i = 0; i < n; i++) mergeArr[i] = arr[i];

    start = clock();
    mergeSort(mergeArr, 0, n - 1);
    end = clock();
    printf("Merge Sort took %lf seconds.\n", (double)(end - start) / CLOCKS_PER_SEC);
    free(mergeArr);

    free(arr);
}

void generateRandomArray(int arr[], int n) {
    srand(time(NULL)); // Seed for randomness
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; // Random numbers between 0 and 9999
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                // Swap
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        // Swap pivot
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

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

    free(L);
    free(R);
}