//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to rearrange the array elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function for bucket sort
void bucketSort(int arr[], int n) {
    int i, j;
    int count[n];
    for (i = 0; i < n; i++) {
        count[i] = 0;
    }

    for (i = 0; i < n; i++) {
        (count[arr[i]])++;
    }

    for (i = 0, j = 0; i < n; i++) {
        for (; count[i] > 0; (count[i])--) {
            arr[j++] = i;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements you want to sort: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Unsorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    clock_t t;
    t = clock();
    bucketSort(arr, n);
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nBucket sort algorithm took %f seconds to execute.", time_taken);
    return 0;
}