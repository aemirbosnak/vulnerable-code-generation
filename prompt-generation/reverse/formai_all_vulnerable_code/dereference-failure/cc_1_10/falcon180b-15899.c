//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define MAX_VALUE 100

typedef struct {
    int *arr;
    int size;
} Bucket;

void init_bucket(Bucket *b, int size) {
    b->arr = (int *)malloc(size * sizeof(int));
    b->size = size;
    for (int i = 0; i < size; i++) {
        b->arr[i] = -1;
    }
}

void print_bucket(Bucket b) {
    for (int i = 0; i < b.size; i++) {
        if (b.arr[i]!= -1) {
            printf("%d ", b.arr[i]);
        } else {
            printf("-1 ");
        }
    }
    printf("\n");
}

void insert_into_bucket(Bucket *b, int elem) {
    int index = elem % b->size;
    if (b->arr[index] == -1) {
        b->arr[index] = elem;
    } else {
        printf("Bucket is full!\n");
    }
}

void sort(int *arr, int size) {
    Bucket buckets[MAX_VALUE];
    for (int i = 0; i < MAX_VALUE; i++) {
        init_bucket(&buckets[i], MAX_SIZE);
    }

    for (int i = 0; i < size; i++) {
        int elem = arr[i];
        int index = elem % MAX_VALUE;
        insert_into_bucket(&buckets[index], elem);
    }

    int j = 0;
    for (int i = 0; i < MAX_VALUE; i++) {
        if (buckets[i].arr[0]!= -1) {
            while (buckets[i].arr[0]!= -1) {
                arr[j++] = buckets[i].arr[0];
                buckets[i].arr[0] = -1;
            }
        }
    }
}

int main() {
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    sort(arr, size);

    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}