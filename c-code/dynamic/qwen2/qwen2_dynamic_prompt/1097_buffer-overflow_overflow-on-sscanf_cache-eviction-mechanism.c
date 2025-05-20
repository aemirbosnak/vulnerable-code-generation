#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 1024

typedef struct {
    int key;
    char value[CACHE_SIZE];
} CacheEntry;

CacheEntry cache[10];

void addToCache(int key, const char* value) {
    if (key >= 0 && key < 10) {
        snprintf(cache[key].value, sizeof(cache[key].value), "%s", value);
        cache[key].key = key;
    } else {
        printf("Invalid key\n");
    }
}

int main() {
    char input[256];
    while (1) {
        printf("Enter key and value: ");
        fgets(input, sizeof(input), stdin);
        if (input[0] == 'q' || input[0] == 'Q') {
            break;
        }

        int key;
        char value[CACHE_SIZE];
        if (sscanf(input, "%d %255s", &key, value) != 2) {
            printf("Invalid input format\n");
            continue;
        }

        addToCache(key, value);
    }

    return 0;
}
