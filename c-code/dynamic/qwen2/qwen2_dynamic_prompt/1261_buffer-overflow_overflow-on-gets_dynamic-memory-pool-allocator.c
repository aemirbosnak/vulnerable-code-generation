#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define POOL_SIZE 1024

typedef struct {
    char data[POOL_SIZE];
} MemoryPool;

MemoryPool pool;
int pool_index = 0;

void* allocate_memory(size_t size) {
    if (pool_index + size > POOL_SIZE) {
        return NULL; // Out of memory
    }
    void* ptr = &pool.data[pool_index];
    pool_index += size;
    return ptr;
}

void free_memory(void* ptr) {
    // No-op in this simple example
}

char* get_string() {
    static char buffer[100];
    printf("Enter a string: ");
    fgets(buffer, sizeof(buffer), stdin);
    return buffer;
}

int main() {
    char* str = (char*)allocate_memory(50);
    if (!str) {
        fprintf(stderr, "Out of memory\n");
        return 1;
    }

    strcpy(str, get_string());

    printf("String stored: %s", str);

    free_memory(str); // Freeing allocated memory

    return 0;
}
