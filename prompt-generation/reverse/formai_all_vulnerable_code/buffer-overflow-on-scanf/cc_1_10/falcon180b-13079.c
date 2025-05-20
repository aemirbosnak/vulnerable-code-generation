//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array into buckets
void partition(int arr[], int n, int max_value) {
    int i, j;
    for (i = 0; i < n; i++) {
        if (arr[i] > max_value) {
            printf("Error: Element %d is greater than the maximum value of %d\n", arr[i], max_value);
            exit(1);
        }
    }
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

// Function to perform bucket sort
void bucket_sort(int arr[], int n) {
    int i, j, max_value = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }
    int bucket_size = max_value / n;
    int* buckets[MAX_SIZE];
    for (i = 0; i < n; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            if (arr[i] == (j * bucket_size)) {
                buckets[j] = &arr[i];
                break;
            }
        }
    }
    int k = 0;
    for (i = 0; i < MAX_SIZE; i++) {
        if (buckets[i]!= NULL) {
            arr[k++] = *buckets[i];
        }
    }
}

// Function to print the sorted array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    partition(arr, n, MAX_SIZE);
    bucket_sort(arr, n);
    printf("Sorted array:\n");
    print_array(arr, n);
    return 0;
}