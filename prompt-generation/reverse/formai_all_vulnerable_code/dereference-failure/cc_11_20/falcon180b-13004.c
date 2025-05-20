//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/shm.h>

#define SIZE 10

int main() {
    int shmid;
    int *shared_memory;
    pid_t childpid;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE * sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment.\n");
        exit(1);
    }

    // Attach to shared memory segment
    shared_memory = shmat(shmid, NULL, 0);
    if (shared_memory == (void*) -1) {
        printf("Error attaching to shared memory segment.\n");
        exit(1);
    }

    // Initialize shared memory
    for (int i = 0; i < SIZE; i++) {
        shared_memory[i] = i;
    }

    // Fork a child process
    childpid = fork();
    if (childpid == -1) {
        printf("Error forking child process.\n");
        exit(1);
    } else if (childpid == 0) {
        // Child process

        // Increment values in shared memory
        for (int i = 0; i < SIZE; i++) {
            shared_memory[i]++;
        }

        // Detach from shared memory segment
        if (shmdt(shared_memory) == -1) {
            printf("Error detaching from shared memory segment.\n");
            exit(1);
        }

        // Exit child process
        exit(0);
    } else {
        // Parent process

        // Wait for child process to finish
        wait(NULL);

        // Print updated values in shared memory
        printf("Updated values in shared memory:\n");
        for (int i = 0; i < SIZE; i++) {
            printf("%d ", shared_memory[i]);
        }
        printf("\n");

        // Detach from shared memory segment
        if (shmdt(shared_memory) == -1) {
            printf("Error detaching from shared memory segment.\n");
            exit(1);
        }

        // Delete shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            printf("Error deleting shared memory segment.\n");
            exit(1);
        }

        // Exit parent process
        exit(0);
    }

    return 0;
}