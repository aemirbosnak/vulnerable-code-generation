#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

char *memory_pool = NULL;
int pool_index = 0;

void init_memory_pool() {
    memory_pool = (char *)malloc(POOL_SIZE);
    if (!memory_pool) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}

void *allocate_memory(int size) {
    if (pool_index + size > POOL_SIZE) {
        fprintf(stderr, "Out of memory\n");
        return NULL;
    }
    char *ptr = &memory_pool[pool_index];
    pool_index += size;
    return ptr;
}

int main() {
    init_memory_pool();

    int num_elements;
    printf("Enter number of elements to allocate: ");
    scanf("%d", &num_elements);

    char **strings = (char **)allocate_memory(num_elements * sizeof(char *));
    if (!strings) {
        return EXIT_FAILURE;
    }

    for (int i = 0; i < num_elements; i++) {
        strings[i] = (char *)allocate_memory(100); // Allocate 100 bytes per string
        if (!strings[i]) {
            return EXIT_FAILURE;
        }
    }

    printf("Enter strings:\n");
    for (int i = 0; i < num_elements; i++) {
        scanf("%s", strings[i]); // Vulnerable to buffer overflow
    }

    printf("Allocated strings:\n");
    for (int i = 0; i < num_elements; i++) {
        printf("%s\n", strings[i]);
    }

    free(memory_pool);
    return EXIT_SUCCESS;
}
