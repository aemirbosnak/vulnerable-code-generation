#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

char pool[POOL_SIZE];
int pool_index = 0;

void* allocate(int size) {
    if (pool_index + size > POOL_SIZE) {
        return NULL;
    }
    void* ptr = &pool[pool_index];
    pool_index += size;
    return ptr;
}

void free_all() {
    pool_index = 0;
}

int main() {
    char input[256];
    printf("Enter data to store: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    int size = strlen(input) + 1;
    void* ptr = allocate(size);
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Vulnerability: Buffer overflow in sscanf
    sscanf(input, "%s", (char*)ptr);

    printf("Data stored at %p\n", ptr);

    free_all();
    return 0;
}
