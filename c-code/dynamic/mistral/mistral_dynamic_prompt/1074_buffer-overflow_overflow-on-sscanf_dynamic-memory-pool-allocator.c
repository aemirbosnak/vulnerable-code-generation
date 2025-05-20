#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void alloc_block(char** block, size_t size) {
    *block = malloc(size);
}

void free_block(char* block) {
    free(block);
}

int main(int argc, char* argv[]) {
    char* buf = NULL;
    size_t capacity = 1024;
    size_t count = 0;

    if (argc < 2) {
        printf("Usage: %s <input_string>\n", argv[0]);
        return 1;
    }

    alloc_block(&buf, capacity);

    while (sscanf(argv[1] + count, "%99[^\n]", buf + count) == 1) {
        count += 99;

        if (count >= capacity) {
            capacity *= 2;
            buf = realloc(buf, capacity);
        }
    }

    free_block(buf);
    return 0;
}
