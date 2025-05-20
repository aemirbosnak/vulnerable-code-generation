//Code Llama-13B DATASET v1.0 Category: Interprocess communication ; Style: energetic
// Interprocess Communication (IPC) example program
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

// Define shared memory segment size
#define SHM_SIZE 1024

// Define shared memory key
#define SHM_KEY 1234

// Shared memory segment
int *shm;

// Child process
void child_process() {
    // Open shared memory segment
    shm = (int *)shmat(SHM_KEY, NULL, 0);

    // Wait for parent process to write data
    while (*shm == 0) {
        sleep(1);
    }

    // Print shared memory data
    printf("Child process received data from parent: %d\n", *shm);

    // Exit child process
    exit(0);
}

// Parent process
void parent_process() {
    // Open shared memory segment
    shm = (int *)shmat(SHM_KEY, NULL, 0);

    // Write data to shared memory segment
    *shm = 42;

    // Create child process
    pid_t pid = fork();

    // Child process
    if (pid == 0) {
        child_process();
    }

    // Parent process
    else {
        // Wait for child process to exit
        wait(NULL);

        // Print shared memory data
        printf("Parent process wrote data to shared memory: %d\n", *shm);
    }
}

// Main function
int main() {
    // Create shared memory segment
    shm = (int *)shmget(SHM_KEY, SHM_SIZE, 0666);

    // Parent process
    parent_process();

    // Destroy shared memory segment
    shmctl(shm, IPC_RMID, NULL);

    return 0;
}