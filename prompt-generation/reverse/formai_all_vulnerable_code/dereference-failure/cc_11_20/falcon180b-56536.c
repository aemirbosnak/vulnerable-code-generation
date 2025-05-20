//Falcon-180B DATASET v1.0 Category: Memory management ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char *name;
    int size;
    void *address;
} MemoryBlock;

int main() {
    int i, j;
    MemoryBlock *memory = (MemoryBlock *)malloc(MAX_SIZE * sizeof(MemoryBlock));
    char input[100];

    for (i = 0; i < MAX_SIZE; i++) {
        memory[i].name = NULL;
        memory[i].size = 0;
        memory[i].address = NULL;
    }

    while (1) {
        printf("Enter command (allocate/deallocate/list/exit): ");
        scanf("%s", input);

        if (strcmp(input, "allocate") == 0) {
            printf("Enter block name: ");
            scanf("%s", input);
            printf("Enter block size: ");
            scanf("%d", &j);

            for (i = 0; i < MAX_SIZE; i++) {
                if (memory[i].name == NULL && memory[i].size == j) {
                    memory[i].name = strdup(input);
                    memory[i].address = malloc(j * sizeof(char));
                    memory[i].size = j;
                    printf("Block '%s' allocated at address %p\n", input, memory[i].address);
                    break;
                }
            }
        } else if (strcmp(input, "deallocate") == 0) {
            printf("Enter block name: ");
            scanf("%s", input);

            for (i = 0; i < MAX_SIZE; i++) {
                if (memory[i].name!= NULL && strcmp(memory[i].name, input) == 0) {
                    free(memory[i].address);
                    memory[i].address = NULL;
                    memory[i].size = 0;
                    printf("Block '%s' deallocated\n", input);
                    break;
                }
            }
        } else if (strcmp(input, "list") == 0) {
            printf("Allocated blocks:\n");
            for (i = 0; i < MAX_SIZE; i++) {
                if (memory[i].name!= NULL) {
                    printf("Name: %s, Size: %d, Address: %p\n", memory[i].name, memory[i].size, memory[i].address);
                }
            }
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command\n");
        }
    }

    free(memory);
    return 0;
}