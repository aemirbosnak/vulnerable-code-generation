//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: accurate
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
    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach shared memory segment to process
    shm = shmat(shmid, NULL, 0);
    if (shm == (char *) -1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory
    for (i = 0; i < SIZE; i++) {
        shm[i] = 'A' + i;
    }

    // Detach shared memory segment
    if (shmdt(shm) == -1) {
        printf("Error detaching shared memory segment\n");
        exit(1);
    }

    // Attach shared memory segment to another process
    pid_t pid = fork();
    if (pid == 0) {
        shm = shmat(shmid, NULL, 0);
        if (shm == (char *) -1) {
            printf("Error attaching shared memory segment in child process\n");
            exit(1);
        }

        // Modify shared memory
        for (i = 0; i < SIZE; i++) {
            shm[i] = 'a' + i;
        }

        // Detach shared memory segment
        if (shmdt(shm) == -1) {
            printf("Error detaching shared memory segment in child process\n");
            exit(1);
        }

        exit(0);
    } else {
        // Wait for child process to finish
        wait(NULL);

        // Attach shared memory segment to parent process
        shm = shmat(shmid, NULL, 0);
        if (shm == (char *) -1) {
            printf("Error attaching shared memory segment in parent process\n");
            exit(1);
        }

        // Read modified shared memory
        for (i = 0; i < SIZE; i++) {
            printf("%c", shm[i]);
        }

        // Detach shared memory segment
        if (shmdt(shm) == -1) {
            printf("Error detaching shared memory segment in parent process\n");
            exit(1);
        }

        exit(0);
    }
}