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
    for (int i = 0; i < 10; i++) {
        if (cache[i].key == -1) {
            cache[i].key = key;
            snprintf(cache[i].value, sizeof(cache[i].value), "%s", value);
            return;
        }
    }
}

void removeFromCache(int key) {
    for (int i = 0; i < 10; i++) {
        if (cache[i].key == key) {
            cache[i].key = -1;
            cache[i].value[0] = '\0';
            return;
        }
    }
}

void displayCache() {
    printf("Cache Contents:\n");
    for (int i = 0; i < 10; i++) {
        if (cache[i].key != -1) {
            printf("Key: %d, Value: %s\n", cache[i].key, cache[i].value);
        } else {
            printf("Key: %d, Value: Empty\n", cache[i].key);
        }
    }
}

int main() {
    for (int i = 0; i < 10; i++) {
        cache[i].key = -1;
        cache[i].value[0] = '\0';
    }

    char input[256];
    while (1) {
        printf("Enter command (add/remove/display/exit): ");
        fgets(input, sizeof(input), stdin);

        if (sscanf(input, "add %d %s", &cache[0].key, cache[0].value) == 2) {
            addToCache(cache[0].key, cache[0].value);
        } else if (sscanf(input, "remove %d", &cache[0].key) == 1) {
            removeFromCache(cache[0].key);
        } else if (sscanf(input, "display") == 0) {
            displayCache();
        } else if (sscanf(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}
