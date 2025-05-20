#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 1024

int cache[CACHE_SIZE];
int next_index = 0;

void evict_cache() {
    int i;
    for (i = 0; i < CACHE_SIZE; i++) {
        cache[i] = 0;
    }
}

void access_memory(int address) {
    if (address >= 0 && address < CACHE_SIZE) {
        cache[next_index] = address;
        next_index = (next_index + 1) % CACHE_SIZE;
    } else {
        printf("Error: Invalid memory address\n");
    }
}

int main() {
    int i;
    for (i = 0; i < CACHE_SIZE * 2; i++) {
        access_memory(i);
    }

    // Intentional integer overflow to demonstrate vulnerability
    int overflow_value = -1;
    overflow_value -= CACHE_SIZE;
    access_memory(overflow_value);

    return 0;
}
