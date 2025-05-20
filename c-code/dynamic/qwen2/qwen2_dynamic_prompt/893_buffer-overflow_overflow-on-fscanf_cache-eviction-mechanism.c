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

void read_cache_entry(int index) {
    CacheEntry entry;
    printf("Enter key: ");
    scanf("%d", &entry.key);
    printf("Enter value: ");
    fscanf(stdin, "%s", entry.value); // Vulnerability here
}

int main() {
    int choice, index;
    while (1) {
        printf("\n1. Read cache entry\n2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter cache index (0-9): ");
                scanf("%d", &index);
                if (index >= 0 && index < 10) {
                    read_cache_entry(index);
                } else {
                    printf("Invalid index!\n");
                }
                break;
            case 2:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
