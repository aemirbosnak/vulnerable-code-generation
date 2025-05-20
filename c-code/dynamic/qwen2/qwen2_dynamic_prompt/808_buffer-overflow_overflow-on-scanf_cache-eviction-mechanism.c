#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 1024

char cache[CACHE_SIZE];

void evict_cache() {
    printf("Evicting cache...\n");
    // Simulate cache eviction by overwriting the cache with zeros
    for (int i = 0; i < CACHE_SIZE; i++) {
        cache[i] = 0;
    }
}

int main() {
    char input[256];
    int index;

    while (1) {
        printf("Enter an index to store data in cache: ");
        if (scanf("%d", &index) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        if (index >= CACHE_SIZE) {
            printf("Index out of bounds. Try again.\n");
            continue;
        }

        printf("Enter data to store: ");
        scanf("%s", input);

        // Buffer overflow vulnerability here
        cache[index] = *input;

        printf("Data stored at index %d\n", index);
    }

    return 0;
}
