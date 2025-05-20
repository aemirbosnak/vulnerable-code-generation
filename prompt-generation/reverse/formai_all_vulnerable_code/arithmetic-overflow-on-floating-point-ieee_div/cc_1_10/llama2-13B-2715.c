//LLAMA2-13B DATASET v1.0 Category: Interprocess communication ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0xDEADBEEF
#define SHM_SIZE 4096

struct stats {
    int count;
    double sum;
    double avg;
};

int main() {
    key_t key = SHM_KEY;
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0644);
    if (shmid < 0) {
        perror("shmget() failed");
        return 1;
    }

    // Create a shared memory segment
    void *shm = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shmid, 0);
    if (shm == MAP_FAILED) {
        perror("mmap() failed");
        return 1;
    }

    // Initialize the shared memory with some stats
    struct stats *stats = shm;
    stats->count = 0;
    stats->sum = 0.0;
    stats->avg = 0.0;

    // Fork a child process to compute stats
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork() failed");
        return 1;
    }
    if (pid == 0) {
        // Child process
        close(shmid);
        munmap(shm, SHM_SIZE);

        // Compute stats on the shared memory
        for (int i = 0; i < 100; i++) {
            double value = (double)i / 100.0;
            stats->count++;
            stats->sum += value;
            stats->avg = stats->sum / stats->count;
        }

        // Print the stats
        printf("Child process: count = %d, sum = %f, avg = %f\n",
               stats->count, stats->sum, stats->avg);

        exit(0);
    } else {
        // Parent process
        close(shmid);
        munmap(shm, SHM_SIZE);

        // Wait for the child process to finish
        wait(NULL);

        // Print the stats
        printf("Parent process: count = %d, sum = %f, avg = %f\n",
               stats->count, stats->sum, stats->avg);
    }

    return 0;
}