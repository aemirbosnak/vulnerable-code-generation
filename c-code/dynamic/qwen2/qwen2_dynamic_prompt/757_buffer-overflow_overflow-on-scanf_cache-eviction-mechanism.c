#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 1024

typedef struct {
    int data[CACHE_SIZE];
} Cache;

void simulate_cache_eviction(Cache *cache, int new_data) {
    static int index = 0;
    cache->data[index] = new_data;
    index = (index + 1) % CACHE_SIZE;
}

int main() {
    Cache cache;
    char input[256];

    printf("Welcome to the Cache Eviction Simulator!\n");
    printf("Enter 'evict' followed by an integer to simulate evicting data from the cache.\n");

    while (1) {
        printf("> ");
        if (scanf("%s", input) != 1) {
            printf("Invalid input. Please enter 'evict' followed by an integer.\n");
            continue;
        }

        if (strcmp(input, "exit") == 0) {
            break;
        } else if (strcmp(input, "evict") == 0) {
            int new_data;
            if (scanf("%d", &new_data) != 1) {
                printf("Invalid input. Please enter 'evict' followed by an integer.\n");
                continue;
            }
            simulate_cache_eviction(&cache, new_data);
            printf("Data evicted: %d\n", new_data);
        } else {
            printf("Unknown command. Type 'help' for more information.\n");
        }
    }

    return 0;
}
