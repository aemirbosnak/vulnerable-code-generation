//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<stdbool.h>

#define MAX_SIZE 1000000
#define BUCKET_SIZE 10

int **create_bucket(int size) {
    int **bucket = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        bucket[i] = (int *)malloc(MAX_SIZE * sizeof(int));
    }
    return bucket;
}

void delete_bucket(int **bucket, int size) {
    for (int i = 0; i < size; i++) {
        free(bucket[i]);
    }
    free(bucket);
}

void populate_bucket(int **bucket, int size, int *arr, int n) {
    for (int i = 0; i < n; i++) {
        int index = arr[i] / BUCKET_SIZE;
        if (index >= size) {
            index = size - 1;
        }
        bucket[index][arr[i]]++;
    }
}

void insert_in_sorted_array(int *arr, int n, int index, int value) {
    for (int i = n - 1; i >= index; i--) {
        arr[i + 1] = arr[i];
    }
    arr[index] = value;
}

void sort_bucket(int **bucket, int size, int *arr, int n) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < BUCKET_SIZE; j++) {
            if (bucket[i][j] > 0) {
                int value = j * BUCKET_SIZE + rand() % BUCKET_SIZE;
                insert_in_sorted_array(arr, n, i * BUCKET_SIZE + value, value);
                bucket[i][j]--;
            }
        }
    }
}

void bucket_sort(int *arr, int n) {
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    int range = max_val / BUCKET_SIZE;
    if (max_val % BUCKET_SIZE!= 0) {
        range++;
    }
    int **bucket = create_bucket(range);
    populate_bucket(bucket, range, arr, n);
    sort_bucket(bucket, range, arr, n);
    delete_bucket(bucket, range);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    srand(time(NULL));
    bucket_sort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}