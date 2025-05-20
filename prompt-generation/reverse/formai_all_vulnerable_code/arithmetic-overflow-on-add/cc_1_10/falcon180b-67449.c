//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

#define SIZE 100

// Structure for shared memory
struct shm {
    int count;
    char data[SIZE];
};

int main() {
    int shmid, pid;
    struct shm *shm;

    // Create shared memory
    shmid = shmget(IPC_PRIVATE, sizeof(struct shm), IPC_CREAT | 0666);

    if (shmid == -1) {
        printf("Error creating shared memory\n");
        exit(1);
    }

    // Attach shared memory to process
    shm = (struct shm *) shmat(shmid, NULL, 0);

    if (shm == (void *) -1) {
        printf("Error attaching shared memory\n");
        exit(1);
    }

    // Initialize shared memory
    shm->count = 0;
    strcpy(shm->data, "Hello, world!");

    // Fork a child process
    pid = fork();

    if (pid == 0) {
        // Child process
        sleep(1);
        shm->count++;
        strcpy(shm->data, "Child process says hi!");
        exit(0);
    } else {
        // Parent process
        wait(NULL);

        printf("Shared memory count: %d\n", shm->count);
        printf("Shared memory data: %s\n", shm->data);

        shmdt(shm);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}