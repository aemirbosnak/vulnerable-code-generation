//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

// Function to compare two integers
int compare(const void* a, const void* b) {
    int x = *(int*)a;
    int y = *(int*)b;
    
    if(x < y) {
        return -1;
    } else if(x == y) {
        return 0;
    } else {
        return 1;
    }
}

// Function to perform the bucket sort
void bucketSort(int arr[], int n) {
    int i, j, count[MAX_SIZE] = {0};
    int* bucket[MAX_SIZE];

    // Initialize the buckets
    for(i = 0; i < MAX_SIZE; i++) {
        bucket[i] = (int*)malloc(sizeof(int));
    }

    // Place the elements into the buckets
    for(i = 0; i < n; i++) {
        j = arr[i] * MAX_SIZE / n;
        count[j]++;
        bucket[j] = (int*)realloc(bucket[j], sizeof(int) * (count[j] + 1));
        bucket[j][count[j]] = arr[i];
    }

    // Merge the buckets
    int k = 0;
    for(i = 0; i < MAX_SIZE; i++) {
        for(j = 0; j < count[i]; j++) {
            arr[k++] = bucket[i][j];
        }
    }

    // Free the memory allocated for the buckets
    for(i = 0; i < MAX_SIZE; i++) {
        free(bucket[i]);
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);
    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}