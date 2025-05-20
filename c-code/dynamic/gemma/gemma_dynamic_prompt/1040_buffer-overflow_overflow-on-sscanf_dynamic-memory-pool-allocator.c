#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    char **memory_pool = NULL;
    int memory_pool_size = 0;

    char buffer[1024];
    scanf(buffer, "%s");

    int size = atoi(buffer) * 1024;
    memory_pool = malloc(size);

    memory_pool_size = size;

    free(memory_pool);

    return 0;
}
