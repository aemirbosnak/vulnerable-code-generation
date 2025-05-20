//Falcon-180B DATASET v1.0 Category: Memory management ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOCK_SIZE 1024
#define MAX_NUM_BLOCKS 1000

typedef struct block {
    size_t size;
    char *data;
} Block;

void *my_malloc(size_t size) {
    Block *block = malloc(sizeof(Block));
    if (block == NULL) {
        return NULL;
    }
    block->size = size;
    block->data = malloc(size);
    if (block->data == NULL) {
        free(block);
        return NULL;
    }
    return block->data;
}

void my_free(void *ptr) {
    if (ptr == NULL) {
        return;
    }
    Block *block = (Block *)ptr - sizeof(Block);
    free(block->data);
    free(block);
}

int main() {
    char *str1 = my_malloc(10);
    char *str2 = my_malloc(20);
    char *str3 = my_malloc(30);

    strcpy(str1, "Hello");
    strcpy(str2, "World");
    strcpy(str3, "This is a test");

    printf("%s\n", str1);
    printf("%s\n", str2);
    printf("%s\n", str3);

    my_free(str1);
    my_free(str2);
    my_free(str3);

    return 0;
}