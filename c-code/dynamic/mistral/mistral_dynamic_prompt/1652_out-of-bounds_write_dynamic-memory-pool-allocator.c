#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    size_t size;
    char data[1];
} Block;

void* allocate(size_t size) {
    Block* block = (Block*)calloc(1, size + sizeof(Block));
    block->size = size;
    return (char*)block + sizeof(Block);
}

void free_pool(void* pointer) {
    free((char*)pointer - sizeof(Block));
}

int main() {
    char* buffer = (char*)allocate(100);
    strcpy(buffer, "Secret Data");

    char* attacker_buffer = (char*)calloc(10, sizeof(char));
    strcpy(attacker_buffer, "(Malicious Payload)");

    memcpy(buffer + 100, attacker_buffer, strlen(attacker_buffer) + 1);

    printf("Buffer contents before free:\n%s\n", buffer);
    free_pool(buffer);
    printf("Buffer contents after free:\n%s\n", buffer);

    return 0;
}
