//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int *array;
    int size;
} Bucket;

Bucket *initialize_buckets(int n) {
    Bucket *buckets = (Bucket *)malloc(n * sizeof(Bucket));
    for (int i = 0; i < n; i++) {
        buckets[i].array = (int *)malloc(MAX_SIZE * sizeof(int));
        buckets[i].size = 0;
    }
    return buckets;
}

void insert_element(int *array, int size, int element) {
    if (size == MAX_SIZE) {
        printf("Error: Bucket is full\n");
        return;
    }
    array[size++] = element;
}

void bucket_sort(int *array, int size) {
    int max_element = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max_element) {
            max_element = array[i];
        }
    }
    int bucket_size = max_element / MAX_SIZE + 1;
    Bucket *buckets = initialize_buckets(bucket_size);
    for (int i = 0; i < size; i++) {
        int bucket_index = array[i] / MAX_SIZE;
        insert_element(buckets[bucket_index].array, buckets[bucket_index].size, array[i]);
    }
    int j = 0;
    for (int i = 0; i < bucket_size; i++) {
        int k = 0;
        while (k < buckets[i].size) {
            array[j++] = buckets[i].array[k++];
        }
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *array = (int *)malloc(size * sizeof(int));
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    bucket_sort(array, size);
    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}