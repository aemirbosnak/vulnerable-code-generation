//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void bucketSort(int arr[], int n);

int main() {
    int arr[MAX_SIZE];
    int n;

    printf("Enter the number of elements in the array (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void bucketSort(int arr[], int n) {
    int buckets[MAX_SIZE];
    int i, j, count[MAX_SIZE] = {0};

    // Initialize buckets with -1
    for (i = 0; i < MAX_SIZE; i++) {
        buckets[i] = -1;
    }

    // Count the number of elements in each bucket
    for (i = 0; i < n; i++) {
        count[arr[i] % MAX_SIZE]++;
    }

    // Build the buckets
    for (i = 0; i < n; i++) {
        buckets[arr[i] % MAX_SIZE]++;
        arr[i] = buckets[arr[i] % MAX_SIZE] - 1;
    }

    // Sort the buckets
    for (i = 0; i < MAX_SIZE; i++) {
        if (buckets[i]!= -1) {
            for (j = buckets[i]; j < buckets[i] + count[i]; j++) {
                arr[j] = i;
            }
            buckets[i] += count[i];
        }
    }

    // Merge the buckets
    for (i = 0; i < n; i++) {
        for (j = arr[i] - 1; j >= 0; j--) {
            if (arr[j] == i) {
                break;
            }
            else {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}