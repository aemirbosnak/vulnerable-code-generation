//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10

int main(int argc, char *argv[]) {
    int shmid, i, j;
    char *shmptr;
    pid_t pid;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE * sizeof(int), IPC_CREAT | 0777);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach shared memory segment to process
    shmptr = shmat(shmid, NULL, 0);
    if (shmptr == (void*)-1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory segment
    for (i = 0; i < SIZE; i++) {
        *(shmptr + i) = 0;
    }

    // Fork child process
    pid = fork();
    if (pid == 0) {
        // Child process
        for (i = 0; i < SIZE; i++) {
            *(shmptr + i) = i;
        }
        sleep(1);
        for (i = 0; i < SIZE; i++) {
            *(shmptr + i) = -i;
        }
        exit(0);
    } else {
        // Parent process
        sleep(2);
        for (i = 0; i < SIZE; i++) {
            *(shmptr + i) = -i;
        }
        sleep(1);
        for (i = 0; i < SIZE; i++) {
            *(shmptr + i) = i;
        }
        wait(NULL);
    }

    return 0;
}