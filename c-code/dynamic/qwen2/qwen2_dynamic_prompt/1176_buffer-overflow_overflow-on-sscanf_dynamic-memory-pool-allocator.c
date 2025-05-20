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
    char input[256];
    while (1) {
        printf("Enter command: ");
        fgets(input, sizeof(input), stdin);
        if (input[0] == 'q' || input[0] == 'Q') break;
        if (sscanf(input, "allocate %d", (int*)&pool_index) == 1) {
            printf("Allocated %d bytes\n", pool_index);
        } else if (sscanf(input, "free %d", (int*)&pool_index) == 1) {
            printf("Freed %d bytes\n", pool_index);
        }
    }
    return 0;
}
