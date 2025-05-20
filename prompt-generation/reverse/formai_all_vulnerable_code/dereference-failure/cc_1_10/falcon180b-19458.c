//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEM_BLOCKS 100

typedef struct {
    void *ptr;
    size_t size;
    char *filename;
    int line;
} MemBlock;

int num_blocks = 0;
MemBlock blocks[MAX_MEM_BLOCKS];

void *my_malloc(size_t size, char *filename, int line) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(1);
    }
    blocks[num_blocks].ptr = ptr;
    blocks[num_blocks].size = size;
    blocks[num_blocks].filename = filename;
    blocks[num_blocks].line = line;
    num_blocks++;
    return ptr;
}

void my_free(void *ptr) {
    for (int i = 0; i < num_blocks; i++) {
        if (blocks[i].ptr == ptr) {
            free(ptr);
            num_blocks--;
            return;
        }
    }
    fprintf(stderr, "Error: Invalid pointer\n");
    exit(1);
}

void print_blocks() {
    printf("Total memory blocks: %d\n", num_blocks);
    for (int i = 0; i < num_blocks; i++) {
        printf("%p (%zu bytes) allocated in %s at line %d\n", blocks[i].ptr, blocks[i].size, blocks[i].filename, blocks[i].line);
    }
}

int main() {
    char *str = my_malloc(10, __FILE__, __LINE__);
    strcpy(str, "Hello, World!");
    printf("%s\n", str);
    my_free(str);
    print_blocks();
    return 0;
}