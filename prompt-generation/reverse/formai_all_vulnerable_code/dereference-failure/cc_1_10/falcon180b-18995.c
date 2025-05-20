//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

#define SIZE 1024

int main() {
    int shmid;
    char *shmaddr;
    pid_t pid;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0644);
    if (shmid == -1) {
        printf("Error creating shared memory segment.\n");
        exit(1);
    }

    // Attach shared memory segment to process address space
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (char *)-1) {
        printf("Error attaching shared memory segment.\n");
        exit(1);
    }

    // Initialize shared memory with a message
    strcpy(shmaddr, "Hello from the future!");

    // Fork a child process
    pid = fork();
    if (pid == -1) {
        printf("Error forking.\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process: %s\n", shmaddr);
    } else {
        // Parent process
        wait(NULL);
    }

    // Detach shared memory segment
    if (shmdt(shmaddr) == -1) {
        printf("Error detaching shared memory segment.\n");
        exit(1);
    }

    // Destroy shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error destroying shared memory segment.\n");
        exit(1);
    }

    return 0;
}