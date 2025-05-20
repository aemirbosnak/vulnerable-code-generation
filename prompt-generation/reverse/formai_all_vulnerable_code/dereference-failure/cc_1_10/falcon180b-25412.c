//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000000
#define MAX_BUCKETS 1000

typedef struct {
    int *arr;
    int size;
    int bucket_size;
    int num_buckets;
} BucketSort;

void create_bucket(BucketSort *bs, int bucket_size) {
    bs->bucket_size = bucket_size;
    bs->num_buckets = ceil(MAX_SIZE / bucket_size);
    bs->arr = malloc(MAX_SIZE * sizeof(int));
    bs->size = 0;
}

void add_to_bucket(BucketSort *bs, int num) {
    if (bs->size == MAX_SIZE) {
        printf("Bucket overflow!\n");
        exit(1);
    }
    bs->arr[bs->size++] = num;
}

void sort_bucket(BucketSort *bs) {
    int i, j;
    for (i = 0; i < bs->num_buckets; i++) {
        for (j = 0; j < bs->size; j++) {
            if (bs->arr[j] >= i * bs->bucket_size && bs->arr[j] < (i + 1) * bs->bucket_size) {
                int k = j;
                while (k > 0 && bs->arr[k - 1] > bs->arr[k]) {
                    int temp = bs->arr[k - 1];
                    bs->arr[k - 1] = bs->arr[k];
                    bs->arr[k] = temp;
                    k--;
                }
                k++;
                while (k < bs->size && bs->arr[k] < bs->arr[j]) {
                    int temp = bs->arr[k];
                    bs->arr[k] = bs->arr[j];
                    bs->arr[j] = temp;
                    k++;
                    j--;
                }
            }
        }
    }
}

void print_bucket(BucketSort *bs) {
    int i;
    for (i = 0; i < bs->size; i++) {
        printf("%d ", bs->arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    BucketSort bs;
    create_bucket(&bs, 10);
    int i;
    for (i = 0; i < 1000; i++) {
        int num = rand() % MAX_SIZE;
        add_to_bucket(&bs, num);
    }
    printf("Before sorting:\n");
    print_bucket(&bs);
    sort_bucket(&bs);
    printf("After sorting:\n");
    print_bucket(&bs);
    return 0;
}