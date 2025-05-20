//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    int shm_id;
    int *shm_ptr;
    pid_t child_pid;

    // Create shared memory segment
    shm_id = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
    if (shm_id == -1) {
        fprintf(stderr, "Error: shmget failed\n");
        return 1;
    }

    // Attach shared memory segment to process
    shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (void *) -1) {
        fprintf(stderr, "Error: shmat failed\n");
        return 1;
    }

    // Initialize shared memory value
    *shm_ptr = 0;

    // Fork child process
    child_pid = fork();
    if (child_pid == -1) {
        fprintf(stderr, "Error: fork failed\n");
        return 1;
    } else if (child_pid == 0) {
        // Child process
        sleep(1); // Give parent time to set up shared memory

        // Increment shared memory value
        (*shm_ptr)++;

        // Detach shared memory segment
        if (shmdt(shm_ptr) == -1) {
            fprintf(stderr, "Error: shmdt failed\n");
            return 1;
        }

        // Exit child process
        return 0;
    } else {
        // Parent process
        sleep(2); // Give child time to modify shared memory

        // Print shared memory value
        printf("Shared memory value: %d\n", *shm_ptr);

        // Detach shared memory segment
        if (shmdt(shm_ptr) == -1) {
            fprintf(stderr, "Error: shmdt failed\n");
            return 1;
        }

        // Wait for child process to exit
        wait(NULL);

        return 0;
    }
}