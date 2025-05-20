//Falcon2-11B DATASET v1.0 Category: RAM usage monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

// Function to get current time in seconds since epoch
long getTime() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec / 1000000;
}

// Function to print usage message
void printUsage() {
    printf("RAM Usage Monitor\n");
    printf("Usage:./ram_monitor [-s seconds] [-h]\n");
    printf("  -s seconds : specify seconds to wait between checks (default is 1)\n");
    printf("  -h : show this help message\n");
}

// Main function
int main(int argc, char *argv[]) {
    // Parse command line arguments
    int seconds = 1;
    char *help = 0;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-s") == 0) {
            seconds = atoi(argv[i+1]);
            i++;
        } else if (strcmp(argv[i], "-h") == 0) {
            help = 1;
        } else {
            fprintf(stderr, "Unknown option: %s\n", argv[i]);
            printUsage();
            return 1;
        }
    }

    // If help option is specified, print usage message and exit
    if (help) {
        printUsage();
        return 0;
    }

    // Initialize variables
    long start_time = getTime();
    long current_time = getTime();
    long ram_usage = 0;
    int count = 0;

    // Main loop
    while (1) {
        // Get current RAM usage
        ram_usage = sysconf(_SC_PHYS_PAGES);

        // Calculate elapsed time since last check
        current_time = getTime();
        long elapsed_time = current_time - start_time;

        // Check if time to wait has elapsed
        if (elapsed_time >= seconds) {
            // Print current RAM usage
            printf("RAM usage: %ld bytes\n", ram_usage);

            // Reset variables
            start_time = current_time;
            count++;

            // Check if requested to exit
            if (count == 10) {
                printf("Exiting...\n");
                return 0;
            }
        }

        // Wait for specified amount of time
        usleep(100000); // 0.1 seconds
    }

    return 0;
}