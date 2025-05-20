//FormAI DATASET v1.0 Category: Sorting ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to perform quicksort
void quicksort(int arr[], int low, int high) {
    int pivot, i, j, temp;
    if (low < high) {
        // select pivot
        pivot = low;
        i = low;
        j = high;
        while (i < j) {
            // find element greater than pivot
            while (arr[i] <= arr[pivot] && i <= high) {
                i++;
            }
            // find element less than or equal to pivot
            while (arr[j] > arr[pivot]) {
                j--;
            }
            // swap elements if i < j
            if (i < j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        // swap pivot and j
        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;
        // recursively perform quicksort on left and right subarrays
        quicksort(arr, low, j-1);
        quicksort(arr, j+1, high);
    }
}

// Driver function
int main() {
    int arr[100];
    int i, n;
    // Get size of array from user
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    // Generate random array of given size
    srand(time(0));
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    // Display original array
    printf("Original array: ");
    printArray(arr, n);
    // Sort array using quicksort
    quicksort(arr, 0, n-1);
    // Display sorted array
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}