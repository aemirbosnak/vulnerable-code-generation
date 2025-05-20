//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define RANGE_SIZE 1000
#define BUCKET_SIZE 10

void create_array(int *arr, int size) {
    int i;
    for (i = 0; i < size; i++) {
        arr[i] = rand() % RANGE_SIZE;
    }
}

void print_array(int *arr, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int *arr, int size) {
    int i, j;
    int *buckets[BUCKET_SIZE];
    for (i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = (int *) malloc(sizeof(int) * size);
    }

    for (i = 0; i < size; i++) {
        int bucket_index = arr[i] / (RANGE_SIZE / BUCKET_SIZE);
        buckets[bucket_index][j++] = arr[i];
    }

    int k = 0;
    for (i = 0; i < BUCKET_SIZE; i++) {
        for (j = 0; j < j; j++) {
            arr[k++] = buckets[i][j];
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = (int *) malloc(sizeof(int) * size);

    srand(time(NULL));
    create_array(arr, size);
    printf("Unsorted array:\n");
    print_array(arr, size);

    bucket_sort(arr, size);
    printf("Sorted array:\n");
    print_array(arr, size);

    free(arr);
    return 0;
}