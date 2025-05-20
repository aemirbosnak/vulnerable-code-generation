//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000000
#define MAX_RANGE 1000000

typedef struct {
    int *data;
    int size;
    int capacity;
} Bucket;

void init_bucket(Bucket *b, int capacity) {
    b->data = (int *) malloc(capacity * sizeof(int));
    b->size = 0;
    b->capacity = capacity;
}

void free_bucket(Bucket *b) {
    free(b->data);
}

void insert_bucket(Bucket *b, int value) {
    if (b->size == b->capacity) {
        b->capacity *= 2;
        b->data = (int *) realloc(b->data, b->capacity * sizeof(int));
    }
    b->data[b->size++] = value;
}

void print_bucket(Bucket b) {
    int i;
    for (i = 0; i < b.size; i++) {
        printf("%d ", b.data[i]);
    }
    printf("\n");
}

void sort_bucket(Bucket *b) {
    int i, j;
    for (i = 0; i < b->size - 1; i++) {
        for (j = i + 1; j < b->size; j++) {
            if (b->data[i] > b->data[j]) {
                int temp = b->data[i];
                b->data[i] = b->data[j];
                b->data[j] = temp;
            }
        }
    }
}

void bucket_sort(int *data, int size, int range) {
    int i, j, k;
    Bucket *buckets = (Bucket *) malloc(range * sizeof(Bucket));
    for (i = 0; i < range; i++) {
        init_bucket(&buckets[i], 0);
    }

    for (i = 0; i < size; i++) {
        int bucket_index = data[i] / range;
        insert_bucket(&buckets[bucket_index], data[i]);
    }

    for (i = 0; i < range; i++) {
        sort_bucket(&buckets[i]);
    }

    for (i = 0, k = 0; i < range; i++) {
        for (j = 0; j < buckets[i].size; j++) {
            data[k++] = buckets[i].data[j];
        }
    }

    for (i = 0; i < range; i++) {
        free_bucket(&buckets[i]);
    }
    free(buckets);
}

int main() {
    int size, range;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *data = (int *) malloc(size * sizeof(int));

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &data[i]);
    }

    printf("Enter the range of the array: ");
    scanf("%d", &range);

    bucket_sort(data, size, range);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}