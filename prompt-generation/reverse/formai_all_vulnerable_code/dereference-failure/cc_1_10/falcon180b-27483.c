//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SIZE 100

int main() {
    int shmid;
    char *shmptr;
    pid_t pid;
    int status;
    char *message = "Hello, world!";

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0777);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach to shared memory segment
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (char *) -1) {
        printf("Error attaching to shared memory segment\n");
        exit(2);
    }

    // Write message to shared memory
    strcpy(shmptr, message);

    // Fork child process
    pid = fork();
    if (pid == -1) {
        printf("Error forking child process\n");
        exit(3);
    }

    // If parent process
    if (pid > 0) {
        // Wait for child process to terminate
        wait(&status);

        // Detach from shared memory segment
        if (shmdt(shmptr) == -1) {
            printf("Error detaching from shared memory segment\n");
            exit(4);
        }

        // Delete shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            printf("Error deleting shared memory segment\n");
            exit(5);
        }

        // Print message received from child process
        printf("Message from child process: %s\n", shmptr);
    }

    // If child process
    else {
        // Read message from shared memory
        char *received_message = shmptr;

        // Modify message
        strcat(received_message, " from child process");

        // Write modified message to shared memory
        strcpy(shmptr, received_message);

        // Exit child process
        exit(0);
    }

    return 0;
}