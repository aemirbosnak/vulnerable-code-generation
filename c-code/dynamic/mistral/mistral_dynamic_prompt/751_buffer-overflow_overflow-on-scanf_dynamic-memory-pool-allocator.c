#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    void *data;
    size_t size;
    struct Block *next;
} Block;

Block *head = NULL;

void allocate(size_t size) {
    Block *new_block = (Block*)malloc(sizeof(Block));
    new_block->data = malloc(size);
    new_block->size = size;
    new_block->next = head;
    head = new_block;
}

void free_pool() {
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
    int choice;
    printf("Dynamic Memory Pool Allocator\n");
    printf("1. Allocate\n2. Free\n3. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the size of the memory block to allocate: ");
                int block_size;
                scanf("%d", &block_size);
                allocate(block_size);
                break;
            case 2:
                free_pool();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
