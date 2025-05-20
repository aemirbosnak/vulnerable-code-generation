//Falcon-180B DATASET v1.0 Category: Data mining ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ITEMS 10
#define NUM_BUCKETS 5

typedef struct {
    int *items;
    int num_items;
    int bucket_size;
} Bucket;

void initialize_bucket(Bucket *b, int size) {
    b->items = (int *)malloc(size * sizeof(int));
    b->num_items = 0;
    b->bucket_size = size;
}

void add_item(Bucket *b, int item) {
    if (b->num_items == b->bucket_size) {
        printf("Bucket is full!\n");
        return;
    }
    b->items[b->num_items++] = item;
}

void print_bucket(Bucket *b) {
    for (int i = 0; i < b->num_items; i++) {
        printf("%d ", b->items[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Bucket buckets[NUM_BUCKETS];
    for (int i = 0; i < NUM_BUCKETS; i++) {
        initialize_bucket(&buckets[i], NUM_ITEMS);
    }

    // Add random items to each bucket
    for (int i = 0; i < NUM_BUCKETS; i++) {
        for (int j = 0; j < NUM_ITEMS; j++) {
            int item = rand() % 100;
            add_item(&buckets[i], item);
        }
    }

    // Print the contents of each bucket
    for (int i = 0; i < NUM_BUCKETS; i++) {
        printf("Bucket %d: ", i + 1);
        print_bucket(&buckets[i]);
    }

    return 0;
}