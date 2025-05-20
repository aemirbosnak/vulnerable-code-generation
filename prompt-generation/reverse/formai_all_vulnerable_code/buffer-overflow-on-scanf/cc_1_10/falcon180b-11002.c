//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    int *array;
    int size;
} Bucket;

void init_array(int array[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
}

void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void bucket_sort(Bucket *buckets, int num_buckets, int array[], int size) {
    for (int i = 0; i < size; i++) {
        int bucket_index = (array[i] * num_buckets) / 100;
        buckets[bucket_index].array[buckets[bucket_index].size++] = array[i];
    }

    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < buckets[i].size; j++) {
            array[index++] = buckets[i].array[j];
        }
    }
}

int main() {
    int array[MAX_SIZE];
    int size;

    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    Bucket buckets[10];
    for (int i = 0; i < 10; i++) {
        buckets[i].array = malloc(size * sizeof(int));
        buckets[i].size = 0;
    }

    bucket_sort(buckets, 10, array, size);

    printf("Sorted array:\n");
    print_array(array, size);

    return 0;
}