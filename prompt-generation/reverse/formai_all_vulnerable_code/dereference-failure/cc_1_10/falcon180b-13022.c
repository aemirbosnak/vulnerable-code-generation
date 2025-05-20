//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100

int main() {
    int shmid;
    char *shmptr;
    key_t key;
    int shmflg;
    int i;

    // Create a shared memory segment
    shmflg = IPC_CREAT | 0666;
    shmid = shmget(IPC_PRIVATE, SIZE, shmflg);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach to the shared memory segment
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (char *) -1) {
        printf("Error attaching to shared memory segment\n");
        exit(1);
    }

    // Initialize the shared memory with a string
    strcpy(shmptr, "Hello, world!");

    // Create a child process
    pid_t pid = fork();
    if (pid == -1) {
        printf("Error creating child process\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        sleep(1); // Wait for parent to initialize shared memory
        for (i = 0; i < SIZE; i++) {
            printf("%c", shmptr[i]);
        }
        printf("\n");
        shmdt(shmptr);
        exit(0);
    } else {
        // Parent process
        sleep(2); // Give child time to print message
        strcpy(shmptr, "Goodbye, world!");
        shmdt(shmptr);
        wait(NULL);
        exit(0);
    }

    return 0;
}