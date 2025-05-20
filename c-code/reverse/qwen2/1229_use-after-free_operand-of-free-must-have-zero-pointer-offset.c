#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_MEM_SIZE 1024

typedef struct {
    char *memory;
    size_t used;
} MemoryManager;

MemoryManager* create_memory_manager() {
    MemoryManager *mm = (MemoryManager*)malloc(sizeof(MemoryManager));
    if (!mm) return NULL;
    mm->memory = (char*)malloc(MAX_MEM_SIZE);
    if (!mm->memory) {
        free(mm);
        return NULL;
    }
    mm->used = 0;
    return mm;
}

void destroy_memory_manager(MemoryManager *mm) {
    free(mm->memory);
    free(mm);
}

void* allocate(MemoryManager *mm, size_t size) {
    if (mm->used + size > MAX_MEM_SIZE) return NULL;
    void *ptr = &mm->memory[mm->used];
    mm->used += size;
    return ptr;
}

void deallocate(MemoryManager *mm, void *ptr, size_t size) {
    // In a real scenario, you would need to track allocations to properly deallocate
    // For simplicity, we assume all deallocations are valid
    mm->used -= size;
}

int main() {
    MemoryManager *mm = create_memory_manager();
    if (!mm) {
        fprintf(stderr, "Failed to create memory manager\n");
        return EXIT_FAILURE;
    }

    int *array = (int*)allocate(mm, 100 * sizeof(int));
    if (!array) {
        fprintf(stderr, "Failed to allocate memory\n");
        destroy_memory_manager(mm);
        return EXIT_FAILURE;
    }

    for (int i = 0; i < 100; i++) {
        array[i] = i;
    }

    printf("Array elements: ");
    for (int i = 0; i < 100; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    deallocate(mm, array, 100 * sizeof(int));

    destroy_memory_manager(mm);

    return EXIT_SUCCESS;
}
