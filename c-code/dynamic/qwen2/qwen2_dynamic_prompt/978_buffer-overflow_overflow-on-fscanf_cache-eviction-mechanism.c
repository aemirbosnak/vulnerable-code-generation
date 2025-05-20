#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 16

void simulate_cache_eviction() {
    char buffer[BUFFER_SIZE];
    printf("Enter data to store in cache: ");
    fscanf(stdin, "%s", buffer);
}

int main() {
    while (1) {
        simulate_cache_eviction();
    }
    return 0;
}
