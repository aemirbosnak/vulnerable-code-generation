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
    if (pool_index + size > POOL_SIZE) return NULL;
    void* ptr = &pool[pool_index];
    pool_index += size;
    return ptr;
}

int main() {
    char buffer[10];
    FILE* file = fopen("input.txt", "r");
    if (!file) {
        printf("Failed to open file\n");
        return 1;
    }

    while (fscanf(file, "%s", buffer) != EOF) {
        void* ptr = allocate(sizeof(buffer));
        if (!ptr) {
            printf("Memory allocation failed\n");
            fclose(file);
            return 1;
        }
        strcpy((char*)ptr, buffer);
        printf("Allocated %lu bytes for '%s'\n", sizeof(buffer), (char*)ptr);
    }

    fclose(file);
    return 0;
}
