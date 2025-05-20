//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 100000
#define MAX_VALUE 100000
#define BUCKET_SIZE 10

int *array;
int *bucket;
int *sorted_array;

void initialize_array(int size) {
    srand(time(NULL));
    array = (int *) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % MAX_VALUE;
    }
}

void initialize_bucket(int size) {
    bucket = (int *) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        bucket[i] = 0;
    }
}

void initialize_sorted_array(int size) {
    sorted_array = (int *) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        sorted_array[i] = 0;
    }
}

void bucket_sort(int size) {
    int max_value = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max_value) {
            max_value = array[i];
        }
    }

    int range = max_value / BUCKET_SIZE + 1;
    initialize_bucket(range);

    for (int i = 0; i < size; i++) {
        int index = array[i] / BUCKET_SIZE;
        bucket[index]++;
    }

    for (int i = 1; i < range; i++) {
        bucket[i] += bucket[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        int index = array[i] / BUCKET_SIZE;
        sorted_array[--bucket[index]] = array[i];
    }

    for (int i = 0; i < size; i++) {
        array[i] = sorted_array[i];
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    initialize_array(size);
    initialize_sorted_array(size);
    bucket_sort(size);

    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", sorted_array[i]);
    }

    return 0;
}