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

void insert(int key, const char* value) {
    int index = hash(key);
    if (strlen(value) >= sizeof(cache[index].value)) {
        printf("Buffer overflow detected!\n");
        exit(1);
    }
    strcpy(cache[index].value, value);
    cache[index].key = key;
}

void evict() {
    for (int i = 0; i < CACHE_SIZE; i++) {
        if (cache[i].key != -1) {
            cache[i].key = -1;
            memset(cache[i].value, 0, sizeof(cache[i].value));
        }
    }
}

int main() {
    evict();
    int key;
    char input[1024];
    while (1) {
        printf("Enter key to insert (-1 to quit): ");
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", &key) != 1 || key == -1) {
            break;
        }
        printf("Enter value: ");
        fgets(input, sizeof(input), stdin);
        insert(key, input);
    }
    return 0;
}
