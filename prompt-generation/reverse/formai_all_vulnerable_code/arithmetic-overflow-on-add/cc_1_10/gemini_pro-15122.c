//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: distributed
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

// Shared memory segment size
#define SEGMENT_SIZE 1024

// Process ID of the parent process
#define PARENT_PID 0

// Shared memory segment key
#define SHM_KEY 1234

int main() {
    // Create shared memory segment
    int shmid = shmget(SHM_KEY, SEGMENT_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    // Attach shared memory segment to process
    void *shm = shmat(shmid, NULL, 0);
    if (shm == (void *)-1) {
        perror("shmat");
        return 1;
    }

    // Get process ID
    pid_t pid = getpid();

    // Initialize shared memory segment
    if (pid == PARENT_PID) {
        // Parent process initializes shared memory segment to zero
        memset(shm, 0, SEGMENT_SIZE);
    }

    // Child processes modify shared memory segment
    while (1) {
        // Increment the shared memory segment by one
        int *counter = (int *)shm;
        (*counter)++;

        // Print the shared memory segment
        printf("Process %d: %d\n", pid, *counter);

        // Sleep for one second
        sleep(1);
    }

    // Detach shared memory segment from process
    shmdt(shm);

    // Delete shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}