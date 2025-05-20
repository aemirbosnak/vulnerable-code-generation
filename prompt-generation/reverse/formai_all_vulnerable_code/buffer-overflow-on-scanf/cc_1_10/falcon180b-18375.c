//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void bucket_sort(int arr[], int n) {
    int i, j, max, min, range, bucket[MAX_SIZE];

    // Calculate the range of the array
    max = arr[0];
    min = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    range = max - min + 1;

    // Create empty buckets
    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = -1;
    }

    // Distribute elements into buckets
    for (i = 0; i < n; i++) {
        j = (arr[i] - min) * MAX_SIZE / range;
        if (bucket[j] == -1) {
            bucket[j] = i;
        } else {
            printf("Error: Duplicate element found.\n");
            exit(0);
        }
    }

    // Sort each bucket using insertion sort
    for (i = 0; i < MAX_SIZE; i++) {
        if (bucket[i]!= -1) {
            for (j = bucket[i]; j < n - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    // Merge the sorted buckets back into the original array
    i = 0;
    for (j = 0; j < MAX_SIZE; j++) {
        if (bucket[j]!= -1) {
            for (int k = bucket[j]; k < n; k++) {
                arr[i++] = arr[k];
            }
        }
    }
}

int main() {
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[MAX_SIZE];

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucket_sort(arr, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}