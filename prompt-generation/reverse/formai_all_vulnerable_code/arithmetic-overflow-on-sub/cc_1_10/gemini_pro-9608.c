//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <math.h>

#define MB (1024 * 1024)

int main() {
    struct rusage usage;
    struct timeval start, end;
    double elapsed_time;
    double max_ram_usage;

    // Initialize max_ram_usage to 0
    max_ram_usage = 0;

    // Start the timer
    gettimeofday(&start, NULL);

    // Allocate memory until the program runs out of memory
    while (1) {
        // Allocate 1 MB of memory
        void *ptr = malloc(MB);
        if (!ptr) {
            break;
        }

        // Get the current RAM usage
        getrusage(RUSAGE_SELF, &usage);

        // Update the max_ram_usage if the current RAM usage is higher
        if (usage.ru_maxrss > max_ram_usage) {
            max_ram_usage = usage.ru_maxrss;
        }
    }

    // Stop the timer
    gettimeofday(&end, NULL);

    // Calculate the elapsed time
    elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    // Print the max_ram_usage and elapsed_time
    printf("Max RAM usage: %.2f MB\n", max_ram_usage / MB);
    printf("Elapsed time: %.2f seconds\n", elapsed_time);

    return 0;
}