#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 64
#define MAX_MEM_SIZE 1024

typedef struct {
    char name[MAX_NAME_SIZE];
    void *mem_block;
    size_t mem_size;
    struct mem_pool *next;
} mem_pool;

mem_pool *head = NULL;

void add_to_pool(char *name, void *mem_block, size_t mem_size) {
    mem_pool *new_node = (mem_pool *) malloc(sizeof(mem_pool));
    strncpy(new_node->name, name, MAX_NAME_SIZE);
    new_node->mem_block = mem_block;
    new_node->mem_size = mem_size;
    new_node->next = head;
    head = new_node;
}

void *get_mem(char *name, size_t size) {
    mem_pool *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0 && current->mem_size >= size) {
            void *mem_block = current->mem_block;
            current->mem_block = ((char *)current->mem_block) + current->mem_size;
            current->mem_size -= size;
            return mem_block;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    char buffer[5];
    int malicious_input = 513;

    add_to_pool("Stack", &buffer, sizeof(buffer));

    printf("Enter memory block name to use: ");
    fscanf(stdin, "%s", buffer);

    return 0;
}
