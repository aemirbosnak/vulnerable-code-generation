#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100
#define ARRAY_SIZE 10

void cache_eviction(char *input) {
    char cache[ARRAY_SIZE][MAX_SIZE];
    int cacheIndex = 0;

    int i = 0;
    for (i; i < strlen(input) && cacheIndex < ARRAY_SIZE; i++) {
        cache[cacheIndex][cacheIndex] = input[i];
        cacheIndex = (cacheIndex + 1) % ARRAY_SIZE;
    }

    // Out of bounds read vulnerability here
    printf("Cache content at invalid index: %c\n", cache[(ARRAY_SIZE - 1) + 1]);

    for (i = 0; i < ARRAY_SIZE; i++) {
        printf("Cache[%d]: %s\n", i, cache[i]);
    }
}

int main() {
    char input[MAX_SIZE];
    printf("Enter input string: ");
    scanf("%s", input);

    cache_eviction(input);

    return 0;
}
