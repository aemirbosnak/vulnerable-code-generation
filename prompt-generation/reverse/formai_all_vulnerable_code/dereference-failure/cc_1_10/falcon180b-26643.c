//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000
#define MAX_NUM 1000000

typedef struct {
    int *arr;
    int size;
} Bucket;

void init_bucket(Bucket *b) {
    b->arr = (int *)malloc(MAX_SIZE * sizeof(int));
    b->size = 0;
}

void free_bucket(Bucket *b) {
    free(b->arr);
}

void insert_bucket(Bucket *b, int num) {
    if (b->size == MAX_SIZE) {
        printf("Bucket is full\n");
        return;
    }
    b->arr[b->size++] = num;
}

void print_bucket(Bucket *b) {
    for (int i = 0; i < b->size; i++) {
        printf("%d ", b->arr[i]);
    }
    printf("\n");
}

void bucket_sort(int *arr, int n) {
    Bucket *buckets = (Bucket *)malloc(MAX_NUM * sizeof(Bucket));
    for (int i = 0; i < MAX_NUM; i++) {
        init_bucket(&buckets[i]);
    }

    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int index = num * MAX_NUM / MAX_SIZE;
        insert_bucket(&buckets[index], num);
    }

    for (int i = 0; i < MAX_NUM; i++) {
        print_bucket(&buckets[i]);
    }

    free(buckets);
}

int main() {
    int arr[] = {10, 5, 20, 15, 30, 25};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucket_sort(arr, n);

    printf("After sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}