#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 10

int cache[CACHE_SIZE];
int next_to_replace = 0;

void access_memory(int address) {
    if (address >= 0 && address < 100) {
        int index = address % CACHE_SIZE;
        printf("Accessing memory at address: %d\n", address);
        printf("Cache before access: ");
        for (int i = 0; i < CACHE_SIZE; i++) {
            printf("%d ", cache[i]);
        }
        printf("\n");

        // Simulate cache eviction
        cache[index] = address;
        next_to_replace = (next_to_replace + 1) % CACHE_SIZE;

        printf("Cache after access: ");
        for (int i = 0; i < CACHE_SIZE; i++) {
            printf("%d ", cache[i]);
        }
        printf("\n");
    } else {
        printf("Invalid memory address: %d\n", address);
    }
}

int main() {
    for (int i = 0; i < 20; i++) {
        access_memory(i * 5);
    }

    return 0;
}
