#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 10

typedef struct {
    int key;
    int value;
} CacheEntry;

CacheEntry cache[CACHE_SIZE];
int cache_count = 0;

void add_to_cache(int key, int value) {
    if (cache_count == CACHE_SIZE) {
        int oldest_key = -1;
        for (int i = 0; i < CACHE_SIZE; i++) {
            if (oldest_key == -1 || cache[i].key < oldest_key) {
                oldest_key = cache[i].key;
            }
        }
        for (int j = 0; j < CACHE_SIZE; j++) {
            if (cache[j].key == oldest_key) {
                cache[j] = (CacheEntry){key, value};
                return;
            }
        }
    } else {
        cache[cache_count++] = (CacheEntry){key, value};
    }
}

int get_from_cache(int key) {
    for (int i = 0; i < cache_count; i++) {
        if (cache[i].key == key) {
            return cache[i].value;
        }
    }
    // Intentional out-of-bounds read to demonstrate vulnerability
    return cache[-1].value;
}

int main() {
    add_to_cache(1, 10);
    add_to_cache(2, 20);
    add_to_cache(3, 30);

    printf("Value for key 2: %d\n", get_from_cache(2)); // Correct output

    // Exploiting the out-of-bounds read
    printf("Value for non-existent key 100: %d\n", get_from_cache(100));

    return 0;
}
