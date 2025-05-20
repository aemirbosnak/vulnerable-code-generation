//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define TOTAL_MEMORY 1000000 // Total memory in bytes
#define CHUNK_SIZE 1000 // Size of each chunk in bytes

void *malloc_wrapper(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Out of memory!\n");
        exit(1);
    }
    return ptr;
}

void free_wrapper(void *ptr) {
    free(ptr);
}

int main() {
    unsigned char *memory = malloc_wrapper(TOTAL_MEMORY);
    if (memory == NULL) {
        return 1;
    }

    unsigned char *free_list = memory;
    unsigned char *used_list = memory + CHUNK_SIZE;

    while (1) {
        printf("Current RAM usage: %d%%\n", (int)((double)(used_list - free_list) / TOTAL_MEMORY * 100.0));
        fflush(stdout);

        int choice;
        printf("Enter your choice:\n");
        printf("1. Allocate memory\n");
        printf("2. Free memory\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            {
                unsigned char *new_memory = used_list;
                used_list += CHUNK_SIZE;

                if (used_list >= memory + TOTAL_MEMORY) {
                    printf("Out of memory!\n");
                    break;
                }

                printf("Allocated %d bytes at %p\n", CHUNK_SIZE, new_memory);
                fflush(stdout);
            }
            break;

        case 2:
            {
                unsigned char *ptr = free_list;
                while (ptr < used_list) {
                    printf("Freed %d bytes at %p\n", CHUNK_SIZE, ptr);
                    fflush(stdout);
                    ptr += CHUNK_SIZE;
                }
                used_list = free_list;
            }
            break;

        case 3:
            free_wrapper(memory);
            return 0;

        default:
            printf("Invalid choice!\n");
            break;
        }
    }

    return 0;
}