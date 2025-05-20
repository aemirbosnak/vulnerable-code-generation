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
    while (1) {
        printf("Enter command: ");
        fgets(input, sizeof(input), stdin);
        if (input[0] == 'q' && input[1] == '\n') {
            break;
        } else if (input[0] == 'a' && input[1] == 'l' && input[2] == 'l' && input[3] == 'o' && input[4] == 'c' && input[5] == 'a' && input[6] == 't' && input[7] == 'e' && input[8] == ' ' && input[9] != '\n') {
            int size;
            if (sscanf(&input[10], "%d", &size) != 1) {
                printf("Invalid input\n");
                continue;
            }
            void* ptr = allocate(size);
            if (ptr == NULL) {
                printf("Allocation failed\n");
            } else {
                printf("Allocated %d bytes at address %p\n", size, ptr);
            }
        } else if (input[0] == 'f' && input[1] == 'r' && input[2] == 'e' && input[3] == 'e' && input[4] == ' ' && input[5] != '\n') {
            free_all();
            printf("All memory freed\n");
        } else {
            printf("Unknown command\n");
        }
    }
    return 0;
}
