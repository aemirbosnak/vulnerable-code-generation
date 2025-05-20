//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100

int main() {
    int shmid;
    char *shm;
    int i;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE * sizeof(char), IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory segment to process address space
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Initialize shared memory with data
    for (i = 0; i < SIZE; i++) {
        shm[i] = 'A' + i;
    }

    // Fork child process
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }

    // Child process writes to shared memory
    if (pid == 0) {
        shm[50] = 'B';
    }

    // Parent process reads from shared memory
    else {
        sleep(1);
        for (i = 0; i < SIZE; i++) {
            if (shm[i] == 'B') {
                printf("Found B at index %d\n", i);
            }
        }
    }

    // Detach shared memory segment from process address space
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Remove shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}