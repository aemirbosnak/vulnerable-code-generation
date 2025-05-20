//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void print_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucket_sort(int* arr, int size) {
    int* buckets = (int*) calloc(MAX, sizeof(int));
    int bucket_size = MAX / size;

    for (int i = 0; i < size; i++) {
        int index = arr[i] / bucket_size;
        buckets[index]++;
    }

    int index = 0;
    for (int i = 0; i < MAX; i++) {
        if (buckets[i] > 0) {
            for (int j = 0; j < buckets[i]; j++) {
                arr[index++] = i * bucket_size + rand_int(0, bucket_size - 1);
            }
        }
    }

    free(buckets);
}

int main() {
    int size = MAX;
    int* arr = (int*) calloc(size, sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand_int(0, MAX);
    }

    printf("Before sorting:\n");
    print_array(arr, size);

    bucket_sort(arr, size);

    printf("After sorting:\n");
    print_array(arr, size);

    free(arr);
    return 0;
}