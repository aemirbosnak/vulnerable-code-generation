#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Block {
    size_t size;
    char *data;
    struct _Block *next;
} Block;

Block *head = NULL;

void allocate(size_t size) {
    Block *new_block = (Block *) malloc(sizeof(Block));
    new_block->size = size;
    new_block->data = (char *) malloc(size);
    new_block->next = head;
    head = new_block;
}

void free_memory() {
    Block *current = head;
    while (head) {
        current = head;
        head = head->next;
        free(current->data);
        free(current);
    }
    head = NULL;
}

int main() {
    char *input;
    int len;

    printf("Memory Pool Allocator\n");
    while (1) {
        printf("Allocate size (or q to quit): ");
        input = (char *) malloc(1024);
        gets(input);
        len = strlen(input);
        if (strcmp(input, "q\n") == 0) break;

        if (len == 0) {
            printf("Invalid input\n");
            free(input);
            continue;
        }

        int size = atoi(input);
        allocate(size);

        if (size > len) {
            printf("Data for allocation larger than input\n");
            continue;
        }

        printf("Enter data (max %d bytes): ", size);
        scanf("%s", input);
        memcpy(head->data, input, size);

        printf("Data written to memory pool:\n");
        printf("%.*s\n", size, head->data);
    }

    free_memory();
    return 0;
}
