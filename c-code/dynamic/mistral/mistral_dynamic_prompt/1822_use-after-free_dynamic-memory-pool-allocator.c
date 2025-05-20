#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    size_t size;
    struct Block *next;
    char data[1];
} Block;

Block *pool = NULL;
size_t current_index = 0;

void alloc(size_t size) {
    if (!pool) {
        pool = malloc(size);
        pool->size = size;
        pool->next = NULL;
        current_index = 0;
    } else {
        for (size_t i = current_index; i < pool->size; ++i) {
            if (!pool[i].next) {
                pool[i].next = malloc(size);
                pool[i].next->size = size;
                pool[i].next->next = NULL;
                current_index = i + size;
                break;
            }
        }
    }
}

void free_(void *ptr) {
    Block *current = pool;
    Block *prev = NULL;

    while (current) {
        if (current == ptr) {
            if (prev) prev->next = current->next;
            else pool = current->next;
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }
}

void* my_malloc(size_t size) {
    alloc(size);
    return pool;
}

int main() {
    char *str1 = (char *)my_malloc(100);
    char *str2 = (char *)my_malloc(200);
    strcpy(str1, "Attack at dawn!");
    free_(str1);
    strcpy(str2, "Prepare for the counterattack!");
    free(str2);

    // Misuse the already freed memory
    printf("Freed memory content: %s\n", str1);

    return 0;
}
