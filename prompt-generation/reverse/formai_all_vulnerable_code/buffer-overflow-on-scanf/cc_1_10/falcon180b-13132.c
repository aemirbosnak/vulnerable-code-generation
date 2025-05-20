//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int bucket[MAX_SIZE] = {0};
    int max = arr[0];
    int min = arr[0];

    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        else if (arr[i] < min) {
            min = arr[i];
        }
    }

    int range = max - min + 1;
    int bucketSize = range / n;

    for (int i = 0; i < n; i++) {
        bucket[arr[i] - min]++;
    }

    int index = 0;
    for (int i = 0; i < range; i++) {
        while (bucket[i] > 0) {
            arr[index++] = i + min;
            bucket[i]--;
        }
    }
}

// Function to recursively sort the array
void recursiveBucketSort(int arr[], int low, int high) {
    if (low == high) {
        return;
    }

    int mid = (low + high) / 2;
    recursiveBucketSort(arr, low, mid);
    recursiveBucketSort(arr, mid + 1, high);
    bucketSort(arr, high - low + 1);
}

// Main function
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    recursiveBucketSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}