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

int main() {
    char buffer[10];
    printf("Enter a string: ");
    fscanf(stdin, "%s", buffer);
    printf("Buffer content: %s\n", buffer);
    return 0;
}
