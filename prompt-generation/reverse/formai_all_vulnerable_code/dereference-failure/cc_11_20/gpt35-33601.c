//FormAI DATASET v1.0 Category: Memory management ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

static const int MB = 1024 * 1024;

int main(int argc, char* argv[]) {
    int num_processes = 0;
    int* pids = NULL;
    int* mem_blocks = NULL;
    int size_per_block = 0;
    int total_mem_requested = 0;

    if (argc < 3) {
        printf("Usage: %s [num_processes] [size_per_block (MB)]\n", argv[0]);
        exit(1);
    }

    // Read num_processes and size_per_block
    num_processes = atoi(argv[1]);
    size_per_block = atoi(argv[2]);
    total_mem_requested = num_processes * size_per_block;

    // Allocate memory blocks
    if ((mem_blocks = malloc(num_processes * sizeof(int*))) == NULL) {
        printf("Error: Failed to allocate memory for mem_blocks\n");
        exit(1);
    }

    for (int i = 0; i < num_processes; i++) {
        if ((mem_blocks[i] = malloc(size_per_block * MB)) == NULL) {
            printf("Error: Failed to allocate memory for process %d\n", i);
            exit(1);
        }
        printf("Memory block of size %d MB allocated for process %d\n", size_per_block, i);

        // Write to each memory block
        for (int j = 0; j < size_per_block * MB; j++) {
            *((char*)mem_blocks[i] + j) = 0;
        }
    }

    // Spawn child processes and have them access their allocated memory blocks
    if ((pids = malloc(num_processes * sizeof(int))) == NULL) {
        printf("Error: Failed to allocate memory for pids\n");
        exit(1);
    }

    printf("\nSpawning child processes...\n\n");

    for (int i = 0; i < num_processes; i++) {
        int pid = fork();

        if (pid == -1) {
            printf("Error: Failed to fork process %d\n", i);
            exit(1);
        } else if (pid == 0) {
            printf("Child process %d running...\n", i);

            // Access memory block
            for (int j = 0; j < size_per_block * MB; j += MB) {
                int val = *((int*)((char*)mem_blocks[i] + j));
                printf("Process %d read value %d at address %p\n", i, val, (char*)mem_blocks[i] + j);
            }

            printf("Child process %d exiting...\n", i);
            exit(0);
        } else {
            pids[i] = pid;
        }
    }

    // Wait for child processes to exit
    printf("\nWaiting for child processes to exit...\n\n");

    for (int i = 0; i < num_processes; i++) {
        int status = 0;
        waitpid(pids[i], &status, 0);
        printf("Child process %d exited with status %d\n", i, status);
    }

    // Free memory blocks
    printf("\nFreeing memory blocks...\n");

    for (int i = 0; i < num_processes; i++) {
        free(mem_blocks[i]);
        printf("Memory block for process %d freed\n", i);
    }

    // Free allocated memory
    free(mem_blocks);
    free(pids);

    printf("\nTotal memory requested: %d MB\n", total_mem_requested);

    return 0;
}