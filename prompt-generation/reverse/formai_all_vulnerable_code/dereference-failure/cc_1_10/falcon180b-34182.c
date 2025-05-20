//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10

int main() {
    int shmid;
    int *shm;
    int pid;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE * sizeof(int), IPC_CREAT | 0777);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach shared memory segment to process
    shm = (int *) shmat(shmid, NULL, 0);
    if (shm == (void *) -1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory with random values
    for (int i = 0; i < SIZE; i++) {
        shm[i] = rand() % 100;
    }

    // Fork child process
    pid = fork();
    if (pid == -1) {
        printf("Error forking process\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        for (int i = 0; i < SIZE; i++) {
            shm[i] *= 2;
        }
    } else {
        // Parent process
        sleep(1);
        for (int i = 0; i < SIZE; i++) {
            printf("%d\n", shm[i]);
        }
    }

    // Detach shared memory segment from process
    if (shmdt(shm) == -1) {
        printf("Error detaching shared memory segment\n");
        exit(1);
    }

    // Destroy shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        printf("Error destroying shared memory segment\n");
        exit(1);
    }

    return 0;
}