//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Function to perform bucket sort
void bucket_sort(int arr[], int n) {
    int max_val = arr[0];
    int min_val = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }

    int range = max_val - min_val + 1;
    int bucket_size = range / (n - 1);

    int* bucket = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        bucket[(arr[i] - min_val) / bucket_size]++;
    }

    for (int i = 1; i < n; i++) {
        bucket[i] += bucket[i - 1];
    }

    int index = 0;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < bucket[i]; j++) {
            arr[index++] = min_val + i * bucket_size;
        }
    }
}

// Function to print the array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucket_sort(arr, n);

    print_array(arr, n);

    free(arr);
    return 0;
}