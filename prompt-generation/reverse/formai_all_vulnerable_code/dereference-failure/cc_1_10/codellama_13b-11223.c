//Code Llama-13B DATASET v1.0 Category: Memory management ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the memory information
struct MemInfo {
    void *addr;
    size_t size;
    char *name;
};

// Function to allocate memory
void *allocate_mem(size_t size, char *name) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }
    struct MemInfo *mem = malloc(sizeof(struct MemInfo));
    mem->addr = ptr;
    mem->size = size;
    mem->name = name;
    printf("Memory allocated at address %p with size %zu and name '%s'\n", ptr, size, name);
    return ptr;
}

// Function to deallocate memory
void deallocate_mem(void *ptr) {
    struct MemInfo *mem = malloc(sizeof(struct MemInfo));
    mem->addr = ptr;
    mem->size = 0;
    mem->name = NULL;
    printf("Memory deallocated at address %p\n", ptr);
    free(ptr);
}

int main() {
    // Allocate memory
    void *ptr1 = allocate_mem(10, "mem1");
    void *ptr2 = allocate_mem(20, "mem2");
    void *ptr3 = allocate_mem(30, "mem3");

    // Use the memory
    char *str1 = "Hello World!";
    char *str2 = "I am a string";
    char *str3 = "This is a test";
    strcpy(ptr1, str1);
    strcpy(ptr2, str2);
    strcpy(ptr3, str3);

    // Deallocate memory
    deallocate_mem(ptr1);
    deallocate_mem(ptr2);
    deallocate_mem(ptr3);

    return 0;
}