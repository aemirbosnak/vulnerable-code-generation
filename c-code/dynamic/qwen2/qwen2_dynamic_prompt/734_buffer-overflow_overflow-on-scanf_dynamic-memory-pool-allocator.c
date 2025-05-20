#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

char pool[POOL_SIZE];
int free_index = 0;

void* allocate(int size) {
    if (free_index + size > POOL_SIZE) {
        return NULL;
    }
    void* ptr = &pool[free_index];
    free_index += size;
    return ptr;
}

void deallocate(void* ptr) {
    // No-op in this unsafe implementation
}

int main() {
    char buffer[10];
    printf("Enter a string: ");
    scanf("%s", buffer);
    printf("Buffer content: %s\n", buffer);

    int size = sizeof(buffer);
    void* allocated_ptr = allocate(size);
    if (allocated_ptr == NULL) {
        printf("Allocation failed!\n");
        return 1;
    }

    // Overwrite the buffer to cause overflow
    strcpy((char*)allocated_ptr, "This is an overflowed buffer");

    printf("Allocated buffer content: %s\n", (char*)allocated_ptr);

    deallocate(allocated_ptr); // No-op

    return 0;
}
