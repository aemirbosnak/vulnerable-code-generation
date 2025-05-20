//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000
#define MAX_VALUE 1000

typedef struct {
    int *bucket;
    int max_size;
    int size;
} Bucket;

void create_bucket(Bucket *b, int max_size) {
    b->bucket = (int *)malloc(max_size * sizeof(int));
    b->max_size = max_size;
    b->size = 0;
}

void destroy_bucket(Bucket *b) {
    free(b->bucket);
}

void insert_element(Bucket *b, int value) {
    if (b->size == b->max_size) {
        printf("Bucket is full!\n");
        return;
    }
    b->bucket[b->size++] = value;
}

void sort_bucket(Bucket *b) {
    int i, j, temp;
    for (i = 0; i < b->size - 1; i++) {
        for (j = 0; j < b->size - i - 1; j++) {
            if (b->bucket[j] > b->bucket[j + 1]) {
                temp = b->bucket[j];
                b->bucket[j] = b->bucket[j + 1];
                b->bucket[j + 1] = temp;
            }
        }
    }
}

void print_bucket(Bucket *b) {
    int i;
    printf("Bucket: ");
    for (i = 0; i < b->size; i++) {
        printf("%d ", b->bucket[i]);
    }
    printf("\n");
}

int main() {
    int i, n, max_value, max_size, value;
    Bucket b;

    printf("Enter the maximum number of elements in the bucket: ");
    scanf("%d", &n);

    printf("Enter the maximum value of the elements: ");
    scanf("%d", &max_value);

    max_size = max_value * 2;

    create_bucket(&b, max_size);

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        insert_element(&b, value);
    }

    printf("Bucket before sorting:\n");
    print_bucket(&b);

    sort_bucket(&b);

    printf("Bucket after sorting:\n");
    print_bucket(&b);

    destroy_bucket(&b);

    return 0;
}