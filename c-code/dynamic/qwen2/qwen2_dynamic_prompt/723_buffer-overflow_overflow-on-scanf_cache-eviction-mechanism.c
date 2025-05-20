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

Cache cache;

void simulate_cache_eviction() {
    printf("Simulating cache eviction...\n");
    // Simulate some operations that might lead to an overflow
    for (int i = 0; i < CACHE_SIZE + 10; i++) {
        cache.data[i] = i;
    }
}

void vulnerable_function() {
    char input[10];
    printf("Enter a string: ");
    scanf("%s", input); // Vulnerable to buffer overflow
}

int main() {
    simulate_cache_eviction();
    vulnerable_function();
    return 0;
}
