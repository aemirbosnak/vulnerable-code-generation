//Falcon-180B DATASET v1.0 Category: Memory management ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOCKS 100
#define BLOCK_SIZE 100

typedef struct {
    int size;
    int free;
    char *data;
} block_t;

block_t blocks[MAX_BLOCKS];
int num_blocks = 0;
int total_size = 0;

void init() {
    int i;
    for (i = 0; i < MAX_BLOCKS; i++) {
        blocks[i].size = BLOCK_SIZE;
        blocks[i].free = 1;
        blocks[i].data = (char *)malloc(BLOCK_SIZE);
        if (blocks[i].data == NULL) {
            printf("Error: Out of memory\n");
            exit(1);
        }
        total_size += BLOCK_SIZE;
    }
    num_blocks = MAX_BLOCKS;
}

void *my_malloc(int size) {
    int i;
    void *ptr;
    for (i = 0; i < num_blocks; i++) {
        if (blocks[i].size >= size && blocks[i].free) {
            blocks[i].free = 0;
            ptr = (void *)blocks[i].data;
            return ptr;
        }
    }
    printf("Error: Out of memory\n");
    exit(1);
}

void my_free(void *ptr) {
    int i;
    for (i = 0; i < num_blocks; i++) {
        if ((void *)blocks[i].data == ptr) {
            blocks[i].free = 1;
            return;
        }
    }
    printf("Error: Invalid pointer\n");
    exit(1);
}

int main() {
    char *str1, *str2, *str3;
    int size1, size2, size3;

    init();

    str1 = (char *)my_malloc(50);
    str2 = (char *)my_malloc(100);
    str3 = (char *)my_malloc(200);

    size1 = strlen(str1);
    size2 = strlen(str2);
    size3 = strlen(str3);

    printf("Size of str1: %d\n", size1);
    printf("Size of str2: %d\n", size2);
    printf("Size of str3: %d\n", size3);

    my_free(str1);
    my_free(str2);
    my_free(str3);

    return 0;
}