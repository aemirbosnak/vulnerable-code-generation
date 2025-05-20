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
    return abs(key % CACHE_SIZE);
}

void insert(int key, const char* value) {
    int index = hash(key);
    while (cache[index].key != -1) {
        if (cache[index].key == key) {
            // Overwrite existing entry
            snprintf(cache[index].value, sizeof(cache[index].value), "%s", value);
            return;
        }
        index = (index + 1) % CACHE_SIZE;
    }
    cache[index].key = key;
    snprintf(cache[index].value, sizeof(cache[index].value), "%s", value);
}

void display() {
    printf("Cache Contents:\n");
    for (int i = 0; i < CACHE_SIZE; i++) {
        if (cache[i].key != -1) {
            printf("Key: %d, Value: %s\n", cache[i].key, cache[i].value);
        }
    }
}

int main() {
    for (int i = 0; i < CACHE_SIZE; i++) {
        cache[i].key = -1;
    }

    int choice, key;
    char value[512]; // Buffer larger than needed to trigger overflow

    while (1) {
        printf("\n1. Insert\n2. Display\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%s", value); // Vulnerability here
                insert(key, value);
                break;
            case 2:
                display();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
