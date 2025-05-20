#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    size_t size;
    struct Block* next;
} Block;

Block* free_list = NULL;

void allocate(size_t size) {
    if (!free_list || free_list->size < size) {
        free_list = realloc(free_list, sizeof(Block) + size);
        free_list++;
        free_list->size = size;
        free_list->next = NULL;
    }
    free_list -= 2;
}

void* get_memory() {
    if (!free_list) {
        fprintf(stderr, "Out of memory\n");
        exit(EXIT_FAILURE);
    }
    return free_list++;
}

void free_memory(void* ptr) {
    Block* block = (Block*)ptr - 1;
    block->next = free_list;
    free_list = block;
}

void show_pool() {
    Block* current = free_list;
    printf("Memory Pool:\n");
    while (current != NULL) {
        printf("%p: %zu\n", current, current->size);
        current = current->next;
    }
}

int main() {
    allocate(sizeof(int));
    int* int_ptr = (int*)get_memory();
    *int_ptr = 42;
    free_memory(int_ptr);

    allocate(100);
    char* str_ptr = (char*)get_memory();
    strcpy(str_ptr, "I'm a dynamic memory pool allocator.");
    free_memory(int_ptr); // Use after free

    allocate(200);
    int* int_ptr_2 = (int*)get_memory();
    *int_ptr_2 = 99;
    show_pool();

    return 0;
}
