//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMS 100000

void quicksort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int* a, int* b);

int main() {
    int nums[MAX_NUMS], n, i;
    srand(time(NULL));  // initialize random seed

    // Generate random numbers and fill array
    printf("How many numbers do you want to sort? (<= %d): ", MAX_NUMS);
    scanf("%d", &n);
    if (n <= 0 || n > MAX_NUMS) {
        printf("Invalid input\n");
        return 0;
    }
    printf("Randomly generated %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        nums[i] = rand() % 100;  // generate a random number between 0 and 99
        printf("%d ", nums[i]);
    }

    // Sort array using quicksort algorithm
    quicksort(nums, 0, n - 1);

    // Print sorted array
    printf("\n\nThe sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}

/**
 * Sorts an array in ascending order using quicksort algorithm
 *
 * @param arr the array to be sorted
 * @param low the starting index of the array
 * @param high the ending index of the array
 */
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

/**
 * Partitions the array and returns the index of the pivot element
 *
 * @param arr the array to be sorted
 * @param low the starting index of the array
 * @param high the ending index of the array
 * @return the index of the pivot element
 */
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1, j;
    for (j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

/**
 * Swaps two integers
 *
 * @param a pointer to the first integer
 * @param b pointer to the second integer
 */
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}