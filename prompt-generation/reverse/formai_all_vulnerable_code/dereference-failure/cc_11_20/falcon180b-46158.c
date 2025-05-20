//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SIZE 10

int main() {
    int shmid, i;
    pid_t pid;
    char *shmaddr;
    char *shmptr;
    int *ptr;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE * sizeof(int), IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment.\n");
        exit(1);
    }

    // Attach to shared memory segment
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (char *) -1) {
        printf("Error attaching to shared memory segment.\n");
        exit(1);
    }

    // Initialize shared memory
    ptr = (int *) shmaddr;
    for (i = 0; i < SIZE; i++) {
        ptr[i] = i;
    }

    // Fork child process
    pid = fork();
    if (pid == 0) {
        // Child process
        shmptr = (char *) shmat(shmid, NULL, 0);
        if (shmptr == (char *) -1) {
            printf("Error attaching to shared memory segment.\n");
            exit(1);
        }

        // Access shared memory
        ptr = (int *) shmptr;
        for (i = 0; i < SIZE; i++) {
            printf("Child process: %d\n", ptr[i]);
        }

        // Detach from shared memory segment
        if (shmdt(shmptr) == -1) {
            printf("Error detaching from shared memory segment.\n");
            exit(1);
        }

        // Exit child process
        exit(0);
    } else {
        // Parent process
        wait(NULL);

        // Access shared memory
        shmptr = (char *) shmat(shmid, NULL, 0);
        if (shmptr == (char *) -1) {
            printf("Error attaching to shared memory segment.\n");
            exit(1);
        }

        ptr = (int *) shmptr;
        for (i = 0; i < SIZE; i++) {
            printf("Parent process: %d\n", ptr[i]);
        }

        // Detach from shared memory segment
        if (shmdt(shmptr) == -1) {
            printf("Error detaching from shared memory segment.\n");
            exit(1);
        }
    }

    return 0;
}