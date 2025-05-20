//MISTRAL-7B DATASET v1.0 Category: Bucket Sort Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000
#define TABLE_SIZE 10

typedef struct Bucket {
    int capacity;
    int count;
    int *array;
} Bucket;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int get_index(int value, Bucket buckets[TABLE_SIZE]) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (buckets[i].count < buckets[i].capacity) {
            if (value <= buckets[i].capacity) {
                return i;
            }
        }
    }
    return -1;
}

void bucket_sort(int *arr, int size) {
    Bucket buckets[TABLE_SIZE];

    for (int i = 0; i < TABLE_SIZE; ++i) {
        buckets[i].capacity = i * 10 + 10;
        buckets[i].count = 0;
        buckets[i].array = malloc(buckets[i].capacity * sizeof(int));
    }

    for (int i = 0; i < size; ++i) {
        int index = get_index(arr[i], buckets);
        buckets[index].array[buckets[index].count++] = arr[i];
    }

    int index = 0;
    for (int i = 0; i < TABLE_SIZE; ++i) {
        for (int j = 0; j < buckets[i].count; ++j) {
            arr[index++] = buckets[i].array[j];
        }
        free(buckets[i].array);
    }
}

int main() {
    int arr[MAX_SIZE];
    int size;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    printf("Enter %d integers: ", size);
    for (int i = 0; i < size; ++i) {
        scanf("%d", &arr[i]);
    }

    bucket_sort(arr, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}