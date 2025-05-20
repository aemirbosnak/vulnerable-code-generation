//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100

int main() {
    int fd, shmid;
    char *ptr;

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Error creating shared memory segment\n");
        exit(1);
    }

    // Attach shared memory segment to process
    ptr = shmat(shmid, NULL, 0);
    if (ptr == (void *) -1) {
        printf("Error attaching shared memory segment\n");
        exit(1);
    }

    // Initialize shared memory
    memset(ptr, 0, SIZE);

    // Create child process
    switch (fork()) {
        case -1: // Error
            printf("Error creating child process\n");
            exit(1);
        case 0: // Child process
            // Access shared memory
            printf("Child process accessing shared memory\n");
            for (int i = 0; i < SIZE; i++) {
                ptr[i] = i;
            }
            break;
        default: // Parent process
            // Wait for child process to finish
            wait(NULL);

            // Access shared memory
            printf("Parent process accessing shared memory\n");
            for (int i = 0; i < SIZE; i++) {
                printf("%d ", ptr[i]);
            }
            printf("\n");

            // Detach shared memory segment from process
            if (shmdt(ptr) == -1) {
                printf("Error detaching shared memory segment\n");
                exit(1);
            }

            // Delete shared memory segment
            if (shmctl(shmid, IPC_RMID, NULL) == -1) {
                printf("Error deleting shared memory segment\n");
                exit(1);
            }
            break;
    }
    return 0;
}