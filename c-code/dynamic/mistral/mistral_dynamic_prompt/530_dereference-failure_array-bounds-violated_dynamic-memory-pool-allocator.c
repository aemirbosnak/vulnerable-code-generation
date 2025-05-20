#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define POOL_SIZE 10000

typedef struct {
    char *data;
    size_t size;
    size_t alloc;
    int ref_count;
} PoolItem;

PoolItem *pool;
size_t pool_len = 0;

void init() {
    pool = calloc(POOL_SIZE, sizeof(PoolItem));
    pool_len = POOL_SIZE;
}

PoolItem *allocate(size_t size) {
    for (int i = 0; i < pool_len; ++i) {
        if (!pool[i].alloc) {
            pool[i].size = size;
            pool[i].alloc = 1;
            pool[i].data = malloc(size);
            pool[i].ref_count = 1;
            return &pool[i];
        }
    }
    return NULL;
}

void deallocate(PoolItem *item) {
    item->alloc = 0;
    item->ref_count--;
}

void free_all() {
    for (int i = 0; i < pool_len; ++i) {
        if (!pool[i].ref_count) {
            free(pool[i].data);
            pool[i].alloc = 0;
        }
    }
}

int main() {
    init();
    PoolItem *ptr1 = allocate(20);
    PoolItem *ptr2 = allocate(50);
    char *my_string1 = strcpy(ptr1->data, "This is a dangerous string operation.");
    char *my_string2 = strcpy(ptr2->data, "This string is also dangerously long.");
    printf("%s\n", my_string1);
    printf("%s\n", my_string2);
    deallocate(ptr1);
    printf("%p\n", ptr1->data);
    free_all();
    return 0;
}
