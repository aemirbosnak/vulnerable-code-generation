//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SIZE 100

int main() {
    int shmid, i;
    char *shmaddr;
    pid_t pid;
    int status;
    char *message = "Hello, world!";

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment to process
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Write message to shared memory
    strcpy(shmaddr, message);

    // Fork child process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process reads message from shared memory
        printf("Child: %s\n", shmaddr);

        // Detach shared memory segment
        if (shmdt(shmaddr) == -1) {
            perror("shmdt");
            exit(1);
        }

        // Exit child process
        exit(0);
    } else {
        // Parent process waits for child to exit
        waitpid(pid, &status, 0);

        // Detach shared memory segment
        if (shmdt(shmaddr) == -1) {
            perror("shmdt");
            exit(1);
        }

        // Exit parent process
        exit(0);
    }

    return 0;
}