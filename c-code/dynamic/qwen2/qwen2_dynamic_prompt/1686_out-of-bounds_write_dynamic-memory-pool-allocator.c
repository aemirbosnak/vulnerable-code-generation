#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

char pool[POOL_SIZE];
int free_index = 0;

void* allocate(int size) {
    if (free_index + size > POOL_SIZE) {
        return NULL;
    }
    void* ptr = &pool[free_index];
    free_index += size;
    return ptr;
}

void deallocate(void* ptr, int size) {
    // No-op in this unsafe implementation
}

int main() {
    char* data = (char*)allocate(50);
    if (data == NULL) {
        printf("Allocation failed\n");
        return 1;
    }

    // Overwrite adjacent memory
    data[50] = 'A';

    // Print overwritten memory
    printf("%c\n", *(data + 50));

    return 0;
}
