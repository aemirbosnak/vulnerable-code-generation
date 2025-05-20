//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/ipc.h>

// Shared memory segment
#define SHM_KEY 12345
#define SHM_SIZE 1024

// Function to get the current RAM usage
int get_ram_usage() {
    // Open the /proc/meminfo file
    FILE *f = fopen("/proc/meminfo", "r");
    if (f == NULL) {
        perror("fopen");
        return -1;
    }

    // Read the MemTotal and MemAvailable lines
    char line[1024];
    int mem_total = 0;
    int mem_available = 0;
    while (fgets(line, sizeof(line), f) != NULL) {
        if (strncmp(line, "MemTotal:", 9) == 0) {
            sscanf(line, "MemTotal: %d kB", &mem_total);
        } else if (strncmp(line, "MemAvailable:", 13) == 0) {
            sscanf(line, "MemAvailable: %d kB", &mem_available);
        }
    }

    // Close the /proc/meminfo file
    fclose(f);

    // Calculate the RAM usage
    int ram_usage = mem_total - mem_available;

    // Return the RAM usage
    return ram_usage;
}

// Main function
int main() {
    // Create a shared memory segment
    int shm_id = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shm_id == -1) {
        perror("shmget");
        return -1;
    }

    // Attach the shared memory segment to the current process
    char *shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (char *)-1) {
        perror("shmat");
        return -1;
    }

    // Get the current RAM usage
    int ram_usage = get_ram_usage();

    // Write the RAM usage to the shared memory segment
    sprintf(shm_ptr, "%d", ram_usage);

    // Detach the shared memory segment from the current process
    if (shmdt(shm_ptr) == -1) {
        perror("shmdt");
        return -1;
    }

    // Destroy the shared memory segment
    if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        return -1;
    }

    return 0;
}