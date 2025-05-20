//GPT-4o-mini DATASET v1.0 Category: Benchmarking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = (int *)malloc(n1 * sizeof(int));
    int* R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

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

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
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
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Random numbers between 0-999
    }
}

void printElapsedTime(const char* algorithm, clock_t start, clock_t end) {
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%s took %f seconds\n", algorithm, time_taken);
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    int n;

    printf("Welcome to the Sorting Algorithm Benchmarking Program!\n");
    printf("Please enter the size of the array to sort: ");
    scanf("%d", &n);

    int* arr = (int *)malloc(n * sizeof(int));
    generateRandomArray(arr, n);

    printf("\nStarting benchmark for Bubble Sort...\n");
    clock_t start = clock();
    bubbleSort(arr, n);
    clock_t end = clock();
    printElapsedTime("Bubble Sort", start, end);

    generateRandomArray(arr, n); // Regenerate random array for fairness!

    printf("\nStarting benchmark for Merge Sort...\n");
    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();
    printElapsedTime("Merge Sort", start, end);

    generateRandomArray(arr, n); // Regenerate random array again!

    printf("\nStarting benchmark for Quick Sort...\n");
    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();
    printElapsedTime("Quick Sort", start, end);

    printf("\nAll Sorting Algorithms have been successfully benchmarked. 🎉\n");
    free(arr);
    return 0;
}