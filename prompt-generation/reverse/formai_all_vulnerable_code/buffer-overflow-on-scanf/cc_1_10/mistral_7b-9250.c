//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ELEMENTS 100
#define BUCKET_SIZE 5

typedef struct Bucket {
    int count;
    int *elements;
} Bucket;

void bucketSort(int *arr, int size) {
    int i, j, index;
    Bucket buckets[BUCKET_SIZE];

    for (i = 0; i < BUCKET_SIZE; i++) {
        buckets[i].count = 0;
        buckets[i].elements = malloc(sizeof(int) * MAX_ELEMENTS);
    }

    for (i = 0; i < size; i++) {
        index = arr[i] / BUCKET_SIZE;
        buckets[index].count++;
    }

    for (i = 0; i < BUCKET_SIZE; i++) {
        if (buckets[i].count == 0) continue;

        for (j = 0; j < size; j++) {
            if (arr[j] / BUCKET_SIZE != i) continue;

            buckets[i].elements[buckets[i].count - 1] = arr[j];
            arr[j] = buckets[i].elements[buckets[i].count - 1];
            buckets[i].count--;

            if (buckets[i].count == 0) break;
        }
    }

    for (i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }

    for (i = 0; i < BUCKET_SIZE; i++) {
        free(buckets[i].elements);
    }
}

int main() {
    int arr[MAX_ELEMENTS];
    int i, size;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    printf("Enter %d integers: ", size);

    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    srand(time(NULL));

    printf("\nOriginal array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nAfter bucket sort:\n");
    bucketSort(arr, size);

    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}