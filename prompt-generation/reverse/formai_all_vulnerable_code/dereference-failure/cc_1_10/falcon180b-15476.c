//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

#define SIZE 100

int main() {
    int shmid;
    char *shmptr;
    pid_t pid;
    int status;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0644);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach to shared memory segment
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (void *)-1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory
    memset(shmptr, 0, SIZE);

    // Fork a child process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process writes to shared memory
        char *str = "Hello, world!";
        strcpy(shmptr, str);

        // Detach from shared memory segment
        if (shmdt(shmptr) == -1) {
            perror("shmdt");
            exit(1);
        }

        // Exit child process
        exit(0);
    } else {
        // Parent process reads from shared memory
        wait(&status);

        // Print contents of shared memory
        printf("Shared memory: %s\n", shmptr);

        // Detach from shared memory segment
        if (shmdt(shmptr) == -1) {
            perror("shmdt");
            exit(1);
        }

        // Exit parent process
        exit(0);
    }

    return 0;
}