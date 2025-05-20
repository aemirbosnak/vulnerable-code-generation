//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int *ia = (int *) a;
    int *ib = (int *) b;
    if (*ia < *ib) {
        return -1;
    } else if (*ia > *ib) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int n, i, j;
    int *arr;
    int max_val, min_val, *bucket;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    arr = (int *) malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    max_val = arr[0];
    min_val = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }

    printf("Minimum value: %d\n", min_val);
    printf("Maximum value: %d\n", max_val);

    bucket = (int *) malloc((max_val - min_val + 1) * sizeof(int));
    if (bucket == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    for (i = 0; i < (max_val - min_val + 1); i++) {
        bucket[i] = 0;
    }

    for (i = 0; i < n; i++) {
        j = (arr[i] - min_val);
        bucket[j]++;
    }

    for (i = 0; i < (max_val - min_val + 1); i++) {
        bucket[i] += bucket[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        j = (arr[i] - min_val);
        bucket[j]--;
        arr[bucket[j]] = arr[i];
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    free(bucket);

    return 0;
}