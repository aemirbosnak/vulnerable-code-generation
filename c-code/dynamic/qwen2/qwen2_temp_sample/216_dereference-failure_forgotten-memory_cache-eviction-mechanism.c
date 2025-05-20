#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 10

typedef struct {
    int data;
    int valid;
} CacheEntry;

CacheEntry cache[CACHE_SIZE];
int cache_index = 0;

void simulate_cache_access(int address) {
    if (cache_index >= CACHE_SIZE) {
        cache_index = 0; // Reset index to simulate circular buffer
    }

    CacheEntry *entry = &cache[cache_index];
    if (!entry->valid || entry->data != address) {
        entry->data = address;
        entry->valid = 1;
    } else {
        printf("Hit: %d\n", address);
    }
}

void trigger_dereference_failure() {
    printf("Triggering dereference failure...\n");
    CacheEntry *null_entry = NULL;
    null_entry->valid = 0; // Dereferencing a null pointer
}

int main() {
    for (int i = 0; i < 20; i++) {
        simulate_cache_access(i);
    }

    trigger_dereference_failure();

    return 0;
}
