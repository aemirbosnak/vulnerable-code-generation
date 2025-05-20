#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1024
#define BLOCK_SIZE 64

typedef struct Block {
    char data[BLOCK_SIZE];
    struct Block* next;
} Block;

Block* head = NULL;

void add_block(char* line) {
    Block* new_block = (Block*) malloc(sizeof(Block));
    strncpy(new_block->data, line, BLOCK_SIZE);
    new_block->next = head;
    head = new_block;
}

void free_cache() {
    Block* current = head;
    while (current != NULL) {
        head = current->next;
        free(current);
        current = head;
    }
    head = NULL;
}

void print_cache() {
    Block* current = head;
    printf("Current cache:\n");
    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
}

int main() {
    char lines[MAX_LINES][BLOCK_SIZE];
    int lines_count = 0;

    printf("Enter lines (Ctrl+D to stop):\n");
    for (int i = 0; i < MAX_LINES; ++i) {
        fgets(lines[i], BLOCK_SIZE, stdin);
        if (feof(stdin)) break;
        lines_count++;
    }

    for (int i = 0; i < lines_count; ++i) {
        add_block(lines[i]);
    }

    print_cache();
    free_cache();
    print_cache();

    return 0;
}
