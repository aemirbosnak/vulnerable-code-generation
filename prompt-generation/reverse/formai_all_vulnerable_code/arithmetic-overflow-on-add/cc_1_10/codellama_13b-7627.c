//Code Llama-13B DATASET v1.0 Category: Interprocess communication ; Style: portable
// IPC_example.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc, char *argv[]) {
    int shm_id;
    char *shm_ptr;
    int *int_ptr;
    int i;

    // Create shared memory
    shm_id = shmget(IPC_PRIVATE, 4096, IPC_CREAT | 0666);
    if (shm_id < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory to process
    shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (void *) -1) {
        perror("shmat");
        exit(1);
    }

    // Convert shared memory to integer pointer
    int_ptr = (int *) shm_ptr;

    // Set shared memory to 0
    *int_ptr = 0;

    // Fork child process
    if (fork() == 0) {
        // Child process increments shared memory value
        for (i = 0; i < 1000; i++) {
            *int_ptr += 1;
        }
    } else {
        // Parent process waits for child process to exit
        wait(NULL);

        // Print shared memory value
        printf("Shared memory value: %d\n", *int_ptr);
    }

    // Detach shared memory from process
    if (shmdt(shm_ptr) < 0) {
        perror("shmdt");
        exit(1);
    }

    // Delete shared memory
    if (shmctl(shm_id, IPC_RMID, 0) < 0) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}