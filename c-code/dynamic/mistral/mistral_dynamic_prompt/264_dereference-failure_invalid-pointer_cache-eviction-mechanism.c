#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cache_line {
    void *data;
    size_t size;
} cache_line;

typedef struct cache {
    cache_line *lines;
    size_t capacity;
    size_t size;
} cache;

void cache_init(cache *c, size_t capacity, size_t line_size) {
    c->lines = calloc(capacity, sizeof(cache_line));
    c->capacity = capacity;
    c->size = 0;
    c->lines[0].size = line_size;
}

void cache_insert(cache *c, void *data, size_t size) {
    if (c->size >= c->capacity) {
        // Eviction logic (simplified for example)
        free(c->lines[c->size - 1].data);
        c->lines[c->size - 1].size = 0;
    }

    c->lines[c->size].data = data;
    c->lines[c->size].size = size;
    c->size++;
}

int main() {
    cache my_cache;
    cache_init(&my_cache, 10, 1024);

    // Allocate a large buffer and point to a small part of it
    void *large_buf = malloc(1024 * 1024 * 2); // 2MB
    char *small_data = (char *)large_buf + (1024 * 1024 * 2);

    // Simulate a cache insert
    cache_insert(&my_cache, small_data, 10);

    // Dereference an invalid pointer to cause a SEGMENTATION FAULT (invalid memory access)
    char *invalid_ptr = (char *)0xdeadbeef;
    *invalid_ptr = 42; // Unreachable memory address

    return 0;
}
