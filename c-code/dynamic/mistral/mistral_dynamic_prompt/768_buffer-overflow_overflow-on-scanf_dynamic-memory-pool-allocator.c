#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    size_t capacity;
    size_t size;
    char *data;
} PoolBlock;

PoolBlock *pool_allocate(size_t size) {
    PoolBlock *block = (PoolBlock *) malloc(sizeof(PoolBlock));
    block->capacity = size;
    block->size = size;
    block->data = (char *) malloc(size);
    return block;
}

void pool_free(PoolBlock *block) {
    free(block->data);
    free(block);
}

char *pool_readline(FILE *file) {
    size_t size = 0;
    char *line = NULL;
    char c;

    while ((c = fgetc(file)) != EOF) {
        if (!size) {
            line = pool_allocate(1);
            line[0] = c;
            size++;
            continue;
        }
        char *temp = (char *) realloc(line, size + 2);
        if (!temp) {
            pool_free(line);
            line = NULL;
            break;
        }
        line = temp;
        line[size] = c;
        size++;
        line[(size + 1)] = '\0';
    }
    if (line && size > 0) line[size - 1] = '\0';
    return line;
}

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");
    char *line;
    if (!file) {
        printf("Error opening file.\n");
        return 1;
    }
    while ((line = pool_readline(file))) {
        printf("%s\n", line);
        pool_free(line);
    }
    fclose(file);
    return 0;
}
