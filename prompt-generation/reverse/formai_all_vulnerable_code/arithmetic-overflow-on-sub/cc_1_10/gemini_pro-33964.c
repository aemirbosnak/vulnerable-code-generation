//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <unistd.h>
#include <time.h>

#define INTERVAL 2
#define MAX_SIZE 1024 * 1024 * 100

int main() {
    // Initialize variables
    int i = 0;
    int count = 0;
    struct rusage usage;
    struct timespec start, end;
    pid_t pid = getpid();

    // Allocate memory
    void *ptr = malloc(MAX_SIZE);
    if (ptr == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    // Start timer
    clock_gettime(CLOCK_REALTIME, &start);

    // Loop until counter reaches max value
    while (count < 500) {
        // Get memory usage
        getrusage(RUSAGE_SELF, &usage);

        // Calculate elapsed time
        clock_gettime(CLOCK_REALTIME, &end);
        long elapsed = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000;

        // Print memory usage
        printf("%d: %ldMB\n", elapsed, usage.ru_maxrss / 1024);

        // Increment counter
        count++;

        // Sleep for specified interval
        sleep(INTERVAL);
    }

    // Free memory
    free(ptr);

    return EXIT_SUCCESS;
}