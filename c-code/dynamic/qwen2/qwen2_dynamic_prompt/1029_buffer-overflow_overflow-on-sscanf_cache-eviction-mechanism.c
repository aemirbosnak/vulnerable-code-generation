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
    int key;
    char input[256];

    while (1) {
        printf("Enter key (0-9) to add to cache: ");
        if (scanf("%d", &key) != 1) {
            printf("Invalid input\n");
            break;
        }

        getchar(); // Consume newline character left by scanf

        printf("Enter value to store: ");
        fgets(input, sizeof(input), stdin);

        // Vulnerability: Buffer overflow in sscanf
        sscanf(input, "%255s", cache[key].value); // Overflow here

        addToCache(key, cache[key].value);
    }

    return 0;
}
