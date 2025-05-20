#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void evict_from_cache(int *cache, int size, int item) {
    for (int i = 0; i < size; i++) {
        if (cache[i] == item) {
            cache[i] = -1; // Evict the item from cache
            return;
        }
    }
}

void access_cache(int *cache, int size, int item) {
    int *ptr = NULL;
    for (int i = 0; i < size; i++) {
        if (cache[i] == item) {
            ptr = &cache[i]; // Store the address of the found item
        }
    }
    printf("Accessing %d\n", *ptr); // Dereference the pointer
}

int main() {
    int cache_size = 10;
    int *cache = (int *)malloc(cache_size * sizeof(int));
    if (!cache) {
        perror("Memory allocation failed");
        return EXIT_FAILURE;
    }

    // Initialize cache
    for (int i = 0; i < cache_size; i++) {
        cache[i] = -1;
    }

    // Simulate cache usage
    evict_from_cache(cache, cache_size, 3);
    access_cache(cache, cache_size, 4); // Intentionally dereferencing forgotten memory

    free(cache);
    return EXIT_SUCCESS;
}
