#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 1024

typedef struct {
    int key;
    char value[256];
} CacheEntry;

CacheEntry cache[CACHE_SIZE];

int hash(int key) {
    return key % CACHE_SIZE;
}

void evict_cache() {
    static int index = 0;
    for (int i = 0; i < CACHE_SIZE; i++) {
        if (cache[index].key != -1) {
            cache[index].key = -1;
            memset(cache[index].value, 0, sizeof(cache[index].value));
        }
        index = (index + 1) % CACHE_SIZE;
    }
}

void add_to_cache(int key, const char* value) {
    int idx = hash(key);
    while (cache[idx].key != -1) {
        idx = (idx + 1) % CACHE_SIZE;
    }
    cache[idx].key = key;
    strcpy(cache[idx].value, value);
}

void get_from_cache(int key) {
    int idx = hash(key);
    while (cache[idx].key != -1) {
        if (cache[idx].key == key) {
            printf("Value: %s\n", cache[idx].value);
            return;
        }
        idx = (idx + 1) % CACHE_SIZE;
    }
    printf("Key not found\n");
}

int main() {
    evict_cache();

    char input[1024];
    while (1) {
        printf("Enter command (add <key> <value>, get <key>, exit): ");
        fgets(input, sizeof(input), stdin);

        if (strncmp(input, "exit", 4) == 0) {
            break;
        }

        char cmd[10], key_str[10], value[256];
        if (sscanf(input, "%9s %9[^ ] %255[^\n]", cmd, key_str, value) != 3) {
            printf("Invalid input format\n");
            continue;
        }

        int key = atoi(key_str);

        if (strcmp(cmd, "add") == 0) {
            add_to_cache(key, value);
        } else if (strcmp(cmd, "get") == 0) {
            get_from_cache(key);
        } else {
            printf("Unknown command\n");
        }
    }

    return 0;
}
