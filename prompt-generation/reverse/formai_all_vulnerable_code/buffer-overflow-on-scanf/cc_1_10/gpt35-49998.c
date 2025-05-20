//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000 //Number of elements in the array

/*
 * This program demonstrates a performance-critical component written in C.
 * It sorts a large array of integers using a sorting algorithm called quicksort.
 * Quicksort has an average case time complexity of O(n log n), which makes it an efficient algorithm for sorting large arrays.
 * In this implementation, we also use a partitioning algorithm called Hoare's partition scheme, which further improves performance.
 */

//Swap function used by quicksort to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

//Partition function used within quicksort to partition the array into two sub-arrays
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low - 1, j = high + 1;
    while (1) {
        do {
            i++;
        } while (arr[i] < pivot);
        do {
            j--;
        } while (arr[j] > pivot);
        if (i >= j) {
            return j;
        }
        swap(&arr[i], &arr[j]);
    }
}

//Quicksort function to sort an array
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quicksort(arr, low, p);
        quicksort(arr, p + 1, high);
    }
}

int main() {
    int arr[MAX_SIZE];
    int n, i;

    //Get the array size and elements from the user
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    //Sort the array using quicksort
    quicksort(arr, 0, n - 1);

    //Print the sorted array
    printf("The sorted array is:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}