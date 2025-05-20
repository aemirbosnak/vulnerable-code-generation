//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000

void sort_bucket(int arr[], int n, int min_val, int max_val, int bucket_size) {
    int i, j;
    int *buckets[MAX_SIZE];

    for (i = 0; i < MAX_SIZE; i++) {
        buckets[i] = malloc(sizeof(int) * n);
    }

    for (i = 0; i < n; i++) {
        int index = (int)((arr[i] - min_val) * (MAX_SIZE / (max_val - min_val)));
        if (index >= MAX_SIZE) {
            index = MAX_SIZE - 1;
        }
        buckets[index][buckets[index][0]++] = arr[i];
    }

    int pos = 0;
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < buckets[i][0]; j++) {
            arr[pos++] = buckets[i][j];
        }
    }

    for (i = 0; i < MAX_SIZE; i++) {
        free(buckets[i]);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int min_val = arr[0];
    int max_val = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        } else if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    int bucket_size = max_val - min_val + 1;

    sort_bucket(arr, n, min_val, max_val, bucket_size);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}