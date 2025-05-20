//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <string.h>

#define SAMPLE_INTERVAL_SECONDS 1

void printUsage(char *programName) {
    fprintf(stderr, "Usage: %s\n", programName);
    fprintf(stderr, "This program monitors the CPU usage of the current process.\n");
}

int main(int argc, char *argv[]) {
    // Parse command line arguments
    if (argc > 2) {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    // Initialize variables
    struct timeval start_time;
    struct timeval end_time;
    struct rusage usage;
    double user_time;
    double system_time;
    double total_time;
    double cpu_usage;

    // Get the starting time
    gettimeofday(&start_time, NULL);

    // Loop forever
    while (1) {
        // Get the ending time
        gettimeofday(&end_time, NULL);

        // Calculate the user time, system time, and total time
        getrusage(RUSAGE_SELF, &usage);
        user_time = (double)usage.ru_utime.tv_sec + (double)usage.ru_utime.tv_usec / 1000000.0;
        system_time = (double)usage.ru_stime.tv_sec + (double)usage.ru_stime.tv_usec / 1000000.0;
        total_time = user_time + system_time;

        // Calculate the CPU usage
        cpu_usage = (total_time - (end_time.tv_sec - start_time.tv_sec) - (end_time.tv_usec - start_time.tv_usec) / 1000000.0) / total_time * 100.0;

        // Print the CPU usage
        printf("CPU usage: %.2f%%\n", cpu_usage);

        // Sleep for the sample interval
        sleep(SAMPLE_INTERVAL_SECONDS);

        // Update the starting time
        start_time = end_time;
    }

    return EXIT_SUCCESS;
}