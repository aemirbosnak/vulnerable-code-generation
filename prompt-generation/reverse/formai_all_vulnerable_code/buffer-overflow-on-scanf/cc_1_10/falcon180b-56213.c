//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define RANGE 100

void bucket_sort(int arr[], int size) {
    int i, j, n;
    int *bucket[MAX_SIZE];

    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = (int *)malloc(sizeof(int));
    }

    for (i = 0; i < size; i++) {
        n = arr[i] / RANGE;
        bucket[n] = (int *)realloc(bucket[n], sizeof(int) * (i + 1));
        bucket[n][i] = arr[i];
    }

    for (i = 0; i < size; i++) {
        arr[i] = bucket[arr[i] / RANGE][i];
    }

    for (i = 0; i < MAX_SIZE; i++) {
        free(bucket[i]);
    }
}

void generate_array(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % RANGE;
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    generate_array(arr, size);
    printf("Unsorted array: ");
    print_array(arr, size);

    bucket_sort(arr, size);
    printf("Sorted array: ");
    print_array(arr, size);

    return 0;
}