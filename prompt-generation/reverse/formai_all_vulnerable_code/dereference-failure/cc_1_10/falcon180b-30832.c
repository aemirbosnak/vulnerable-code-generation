//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_VAL 100

void generate_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_VAL;
    }
}

void bucket_sort(int arr[], int size) {
    int bucket_size = MAX_VAL / size;
    int *buckets[size];

    for (int i = 0; i < size; i++) {
        buckets[i] = malloc(MAX_SIZE * sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            buckets[i][j] = -1;
        }
    }

    for (int i = 0; i < size; i++) {
        int val = arr[i];
        int index = val / bucket_size;
        buckets[index][val % bucket_size] = i;
    }

    int index = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            if (buckets[i][j]!= -1) {
                arr[index++] = buckets[i][j];
            }
        }
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int arr[MAX_SIZE];
    int size = rand() % MAX_SIZE + 1;

    generate_array(arr, size);
    printf("Before sorting:\n");
    print_array(arr, size);

    bucket_sort(arr, size);
    printf("After sorting:\n");
    print_array(arr, size);

    return 0;
}