//FormAI DATASET v1.0 Category: Sorting ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

void bubble_sort(int arr[], int n);
void selection_sort(int arr[], int n);
void insertion_sort(int arr[], int n);
void merge_sort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

int main() {
    int arr[MAX_SIZE], n, choice;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input the array elements
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Choose the sorting algorithm:\n");
    printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Sorting based on user's choice
    switch (choice) {
        case 1: 
            bubble_sort(arr, n);
            break;
        case 2:
            selection_sort(arr, n);
            break;
        case 3:
            insertion_sort(arr, n);
            break;
        case 4:
            merge_sort(arr, 0, n-1);
            break;
        default:
            printf("Invalid choice!\n");
            exit(EXIT_SUCCESS);
    }

    // Display the sorted array
    printf("The sorted array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void bubble_sort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n-1; i++) {
        swapped = false;
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if (swapped == false) {
            // If no swapping is done in a pass, the array is already sorted
            break;
        }
    }
}

void selection_sort(int arr[], int n) {
    int min_idx;
    for (int i = 0; i < n-1; i++) {
        min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[min_idx] > arr[j]) {
                min_idx = j;
            }
        }
        // Swap the elements
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

void insertion_sort(int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i-1;

        while (j >= 0 && arr[j] > key) {
            // Shift the elements to the right
            arr[j+1] = arr[j];
            j--;
        }

        // Insert the key at the correct position
        arr[j+1] = key;
    }
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right-left)/2;
        // Divide the array into two parts
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        // Merge the two sorted halves
        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int left_len = mid - left + 1;
    int right_len = right - mid;
    int left_arr[left_len], right_arr[right_len];

    // Copy the elements into left and right arrays
    for (int i = 0; i < left_len; i++) {
        left_arr[i] = arr[left+i];
    }
    for (int j = 0; j < right_len; j++) {
        right_arr[j] = arr[mid+j+1];
    }

    int i = 0, j = 0, k = left;
    while (i < left_len && j < right_len) {
        if (left_arr[i] <= right_arr[j]) {
            arr[k] = left_arr[i];
            i++;
        } else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left array
    while (i < left_len) {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right array
    while (j < right_len) {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}