//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/shm.h>

#define SIZE 1024

int main() {
    int fd, shmid;
    char *shmaddr;
    pid_t pid;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach shared memory segment to process
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (char *)-1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory segment
    memset(shmaddr, 0, SIZE);

    // Fork child process
    pid = fork();
    if (pid == -1) {
        printf("Error forking child process\n");
        exit(1);
    }

    // Child process
    if (pid == 0) {
        // Wait for parent process to initialize shared memory segment
        sleep(1);

        // Write to shared memory segment
        strcpy(shmaddr, "Hello from child process!");

        // Detach shared memory segment
        if (shmdt(shmaddr) == -1) {
            printf("Error detaching shared memory segment\n");
            exit(1);
        }

        // Exit child process
        exit(0);
    }

    // Parent process
    else {
        // Wait for child process to write to shared memory segment
        sleep(2);

        // Read from shared memory segment
        char *msg = shmaddr;
        printf("Message from child process: %s\n", msg);

        // Detach shared memory segment
        if (shmdt(shmaddr) == -1) {
            printf("Error detaching shared memory segment\n");
            exit(1);
        }

        // Exit parent process
        exit(0);
    }

    return 0;
}