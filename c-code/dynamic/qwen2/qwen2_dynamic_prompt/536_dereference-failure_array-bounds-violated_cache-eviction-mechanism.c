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
        cache[index] = address;
        next_to_replace = (next_to_replace + 1) % CACHE_SIZE;
    } else {
        printf("Invalid memory address: %d\n", address);
    }
}

void print_cache() {
    printf("Cache contents:\n");
    for (int i = 0; i < CACHE_SIZE; i++) {
        printf("%d ", cache[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < 20; i++) {
        int address = rand() % 100;
        access_memory(address);
        print_cache();
    }

    return 0;
}
