#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
#define TAG_LENGTH 10

void set(int tag, char *value) {
    int index = tag % SIZE;
    char *cache = malloc(SIZE * TAG_LENGTH);

    for (int i = 0; i < SIZE; ++i) {
        if (i == index) {
            strcpy(cache + i * TAG_LENGTH, value);
            return;
        }
    }

    // Cache is full, evict the oldest entry and add the new one.
    for (int i = 0; i < SIZE - 1; ++i) {
        memcpy(cache + i * TAG_LENGTH, cache + (i + 1) * TAG_LENGTH, TAG_LENGTH);
    }
    strcpy(cache + (SIZE - 1) * TAG_LENGTH, value);
}

int main() {
    char *cache;
    char input[TAG_LENGTH];

    set(0, "Hello, World!");
    set(1, "I'm a penetration tester.");
    set(2, "Evaluating security.");

    // Intentionally forget the memory allocation and keep accessing it.
    printf("%s\n", cache);

    return 0;
}
