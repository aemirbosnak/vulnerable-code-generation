#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    char *data;
    size_t size;
    struct Block *next;
} Block;

void compress(Block *head) {
    Block *current = head;
    while (current != NULL) {
        Block *temp = current->next;
        free(current->data);
        free(current);
        current = temp;
    }
    head = NULL;
}

void allocateAndStore(Block **head, const char *data, size_t size) {
    Block *newBlock = (Block *)malloc(sizeof(Block));
    newBlock->data = (char *)malloc(size);
    newBlock->size = size;
    newBlock->next = *head;
    *head = newBlock;
    memcpy(newBlock->data, data, size);
}

void processFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    size_t size = 0;
    char *buffer = (char *)malloc(1);
    Block *blocks = NULL;

    while ((size_t)fread(buffer, 1, 1, file) > 0) {
        allocateAndStore(&blocks, buffer, size + 1);
        size++;
        buffer[0] = '\0';
    }

    fclose(file);

    printf("Initial data size: %ld\n", sizeof(blocks));

    compress(blocks);

    printf("Final data size: %ld\n", sizeof(blocks));
}

int main() {
    const char *file = "test.txt";
    processFile(file);

    return 0;
}
