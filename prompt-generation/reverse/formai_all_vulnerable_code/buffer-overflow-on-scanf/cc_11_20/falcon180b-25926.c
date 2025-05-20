//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int main() {
    int arr[SIZE];
    int i, n, max, min, range;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    max = arr[0];
    min = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    range = max - min + 1;

    int *bucket = (int *) malloc(range * sizeof(int));
    if (bucket == NULL) {
        printf("Memory error\n");
        exit(0);
    }

    for (i = 0; i < range; i++) {
        bucket[i] = 0;
    }

    for (i = 0; i < n; i++) {
        bucket[arr[i] - min]++;
    }

    for (i = 0; i < range; i++) {
        bucket[i] += bucket[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        arr[--bucket[arr[i] - min]] = arr[i];
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(bucket);
    return 0;
}