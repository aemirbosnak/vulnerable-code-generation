//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: puzzling
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
    char *shm;
    pid_t pid;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE * sizeof(int), IPC_CREAT | 0777);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach shared memory segment to process
    shm = shmat(shmid, 0, 0);
    if (shm == (void *) -1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory
    for (i = 0; i < SIZE; i++) {
        *(shm + i) = 0;
    }

    // Fork a child process
    pid = fork();
    if (pid == 0) {
        // Child process
        for (i = 0; i < SIZE; i++) {
            *(shm + i) = i;
        }
        exit(0);
    } else if (pid < 0) {
        // Error forking
        printf("Error forking\n");
        exit(1);
    } else {
        // Parent process
        wait(NULL);

        // Print shared memory
        for (i = 0; i < SIZE; i++) {
            printf("%d ", *(shm + i));
        }
        printf("\n");

        // Detach shared memory segment
        if (shmdt(shm) == -1) {
            printf("Error detaching shared memory segment\n");
            exit(1);
        }

        // Delete shared memory segment
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
            printf("Error deleting shared memory segment\n");
            exit(1);
        }
    }

    return 0;
}