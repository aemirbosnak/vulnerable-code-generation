//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000
#define BUCKET_SIZE 10

void generate_array(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

void bucket_sort(int arr[], int size) {
    int *buckets[BUCKET_SIZE];
    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = (int *)malloc(size * sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        int bucket_index = arr[i] / 10;
        buckets[bucket_index][i / BUCKET_SIZE] = arr[i];
    }

    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        int j = 0;
        while (j < size / BUCKET_SIZE) {
            arr[index++] = buckets[i][j++];
        }
    }

    for (int i = 0; i < BUCKET_SIZE; i++) {
        free(buckets[i]);
    }
}

int main() {
    int arr[MAX_SIZE];
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size > MAX_SIZE) {
        printf("Array size too large!\n");
        return 1;
    }

    generate_array(arr, size);
    printf("Unsorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucket_sort(arr, size);
    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}