//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

// Function to generate random numbers within a range
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort an array using bucket sort
void bucket_sort(int arr[], int size, int n) {
    int i, j, count[MAX_SIZE] = { 0 };

    // Create n empty buckets
    for (i = 0; i < n; i++) {
        count[i] = 0;
    }

    // Count the number of elements in each bucket
    for (i = 0; i < size; i++) {
        count[arr[i] / n]++;
    }

    // Place the elements in the correct bucket
    for (i = 0; i < size; i++) {
        count[arr[i] / n]--;
        arr[count[arr[i] / n]] = arr[i];
    }
}

// Function to print an array
void print_array(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int size, i;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Generate random numbers and store them in an array
    int arr[size];
    srand(time(NULL));
    for (i = 0; i < size; i++) {
        arr[i] = rand_num(1, 100);
    }

    // Print the unsorted array
    printf("Unsorted array: ");
    print_array(arr, size);

    // Sort the array using bucket sort
    int n = size / 10;
    bucket_sort(arr, size, n);

    // Print the sorted array
    printf("Sorted array: ");
    print_array(arr, size);

    return 0;
}