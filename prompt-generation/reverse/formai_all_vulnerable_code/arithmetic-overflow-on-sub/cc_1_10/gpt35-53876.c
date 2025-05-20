//FormAI DATASET v1.0 Category: Sorting ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

// Function to print the array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to bubble sort the array
void bubble_sort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function to selection sort the array
void selection_sort(int arr[], int n) {
    int min_idx, temp;
    for (int i = 0; i < n-1; i++) {
        min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

// Function to insertion sort the array
void insertion_sort(int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i-1;

        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {
    int arr[MAX], n;
    printf("Enter the number of elements (Max %d): ", MAX);
    scanf("%d", &n);

    // Generate random numbers for the array
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }

    printf("\n\nOriginal Array: ");
    print_array(arr, n);

    printf("\n\nBubble Sorted Array: ");
    bubble_sort(arr, n);
    print_array(arr, n);

    printf("\n\nSelection Sorted Array: ");
    selection_sort(arr, n);
    print_array(arr, n);

    printf("\n\nInsertion Sorted Array: ");
    insertion_sort(arr, n);
    print_array(arr, n);

    return 0;
}