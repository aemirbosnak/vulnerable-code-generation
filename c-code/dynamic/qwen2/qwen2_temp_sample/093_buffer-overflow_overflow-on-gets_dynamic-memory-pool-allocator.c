#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

char pool[POOL_SIZE];
int free_index = 0;

void *allocate(int size) {
    if (free_index + size > POOL_SIZE) {
        return NULL;
    }
    char *ptr = &pool[free_index];
    free_index += size;
    return ptr;
}

void deallocate(char *ptr) {
    // No-op in this unsafe implementation
}

int main() {
    char *buffer = allocate(512);
    if (buffer == NULL) {
        printf("Allocation failed\n");
        return 1;
    }

    // Overwrite adjacent memory to demonstrate buffer overflow
    strcpy(buffer + 512, "This is an overflow");

    printf("%s\n", buffer);

    deallocate(buffer);

    return 0;
}
