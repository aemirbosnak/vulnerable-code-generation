#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100
#define MAX_POOL_SIZE 1000

char *pool[MAX_POOL_SIZE];
size_t pool_count = 0;

void allocate(size_t size) {
    if (pool_count >= MAX_POOL_SIZE) {
        printf("Error: Max pool size reached.\n");
        return;
    }

    pool[pool_count] = malloc(size);
    if (!pool[pool_count]) {
        printf("Error: Out of memory.\n");
        return;
    }

    pool_count++;
}

void deallocate(char *buffer) {
    for (size_t i = 0; i < pool_count; i++) {
        if (pool[i] == buffer) {
            pool[i] = NULL;
            pool_count--;
            free(buffer);
            break;
        }
    }
}

int main() {
    char input[BUFFER_SIZE];
    char *buffer;

    printf("Enter a string: ");
    fgets(input, BUFFER_SIZE, stdin);

    allocate(strlen(input) + 1);
    strcpy(buffer = pool[pool_count - 1], input);

    // Buffer overflow vulnerability: we're writing more data than the buffer can hold
    strcat(buffer, "More data here");

    printf("Allocated buffer:\n%s\n", buffer);
    deallocate(buffer);

    return 0;
}
