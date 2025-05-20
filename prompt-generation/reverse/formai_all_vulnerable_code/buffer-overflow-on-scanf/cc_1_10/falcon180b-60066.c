//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10000
#define MAX_VALUE 10000
#define BUCKET_SIZE 10

void bucket_sort(int arr[], int n) {
    int i, j, k, index;
    int *bucket[MAX_VALUE / BUCKET_SIZE + 1];

    // Initialize the buckets as empty lists
    for (i = 0; i <= MAX_VALUE / BUCKET_SIZE; i++)
        bucket[i] = NULL;

    // Insert each element into its corresponding bucket
    for (i = 0; i < n; i++) {
        index = arr[i] / BUCKET_SIZE;
        if (bucket[index] == NULL) {
            bucket[index] = (int *)malloc(BUCKET_SIZE * sizeof(int));
        }
        bucket[index][k++] = arr[i];
    }

    // Sort each bucket using insertion sort
    for (i = 0; i <= MAX_VALUE / BUCKET_SIZE; i++) {
        if (bucket[i]!= NULL) {
            for (j = 1; j < k; j++) {
                int key = bucket[i][j];
                int pos = j - 1;

                while (pos >= 0 && bucket[i][pos] > key) {
                    bucket[i][pos + 1] = bucket[i][pos];
                    pos--;
                }
                bucket[i][pos + 1] = key;
            }
        }
    }

    // Merge the sorted buckets back into the original array
    i = 0;
    for (j = 0; j <= MAX_VALUE / BUCKET_SIZE; j++) {
        if (bucket[j]!= NULL) {
            for (k = 0; k < k; k++) {
                arr[i++] = bucket[j][k];
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Sorted array using bucket sort:\n");
    bucket_sort(arr, n);
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}