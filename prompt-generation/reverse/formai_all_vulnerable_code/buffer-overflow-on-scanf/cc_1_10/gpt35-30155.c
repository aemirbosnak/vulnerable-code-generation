//FormAI DATASET v1.0 Category: Interprocess communication ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

// Define the shared memory key
#define SHMKEY 2021

int main()
{
    // Declare variables
    int shmid;
    int *shared_memory;
    int pid;
    char message[100];

    // Create shared memory segment
    if ((shmid = shmget(SHMKEY, sizeof(int), IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach shared memory segment
    if ((shared_memory = shmat(shmid, NULL, 0)) == (int *) -1) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Fork a new process
    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process writes to shared memory
        printf("Enter a message for the parent: ");
        scanf("%s", message);

        // Copy message to shared memory
        strncpy((char *) shared_memory, message, sizeof(message));

        // Detach shared memory
        if (shmdt(shared_memory) == -1) {
            perror("shmdt");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);
    } else {
        // Parent process reads from shared memory
        wait(NULL);

        // Get message from shared memory
        printf("Message from child: %s\n", (char *) shared_memory);

        // Detach shared memory
        if (shmdt(shared_memory) == -1) {
            perror("shmdt");
            exit(EXIT_FAILURE);
        }

        // Destroy shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            perror("shmctl");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);
    }
}