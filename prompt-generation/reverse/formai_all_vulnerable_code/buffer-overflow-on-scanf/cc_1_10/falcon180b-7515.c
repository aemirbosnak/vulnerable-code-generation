//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMORY 1000000
#define INITIAL_MEMORY 100

int main() {
    int memory[MAX_MEMORY];
    int memory_size = INITIAL_MEMORY;
    int current_memory_size = 0;
    int *current_memory = memory;

    // Initialize memory with random values
    for (int i = 0; i < INITIAL_MEMORY; i++) {
        memory[i] = rand() % 100;
    }

    // Print initial memory usage
    printf("Initial memory usage: %d bytes\n", memory_size);

    // Allocate more memory
    while (1) {
        int option;
        printf("What do you want to do?\n1. Allocate more memory\n2. Print memory usage\n3. Exit\n");
        scanf("%d", &option);

        switch (option) {
        case 1:
            printf("Enter the amount of memory you want to allocate: ");
            scanf("%d", &memory_size);

            if (current_memory_size + memory_size > MAX_MEMORY) {
                printf("Cannot allocate more memory. Maximum memory limit reached.\n");
            } else {
                current_memory += memory_size;
                current_memory_size += memory_size;
                printf("Memory allocated successfully.\n");
            }

            break;

        case 2:
            printf("Current memory usage: %d bytes\n", current_memory_size);
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}