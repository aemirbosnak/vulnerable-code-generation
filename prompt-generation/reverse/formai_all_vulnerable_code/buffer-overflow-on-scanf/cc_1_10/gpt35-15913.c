//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

void bucket_sort(int arr[], int n) {
    int i, j;
    int *buckets, *bucket_pos;

    buckets = malloc(sizeof(int) * (n + 1));
    bucket_pos = malloc(sizeof(int) * (n + 1));

    for (i = 0; i <= n; i++) {
        buckets[i] = 0;
    }

    for (i = 0; i < n; i++) {
        ++buckets[arr[i]];
    }

    for (i = 1; i <= n; i++) {
        bucket_pos[i] = bucket_pos[i - 1] + buckets[i - 1];
    }

    int *output = malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        output[bucket_pos[arr[i]]++] = arr[i];
    }

    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    free(output);
    free(buckets);
    free(bucket_pos);
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bucket_sort(arr, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}