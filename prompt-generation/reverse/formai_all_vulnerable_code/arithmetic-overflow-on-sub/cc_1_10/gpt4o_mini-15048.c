//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

#define MAX_PINGS 5
#define COMMAND_SIZE 256

// Function to perform a ping test
void ping(const char *host) {
    struct timeval start, end;
    char command[COMMAND_SIZE];
    int status;
    double total_time = 0.0;
    
    printf("Pinging %s with %d packets:\n", host, MAX_PINGS);
    
    for (int i = 0; i < MAX_PINGS; i++) {
        // Build the ping command
        snprintf(command, sizeof(command), "ping -c 1 %s", host);

        // Get the start time
        gettimeofday(&start, NULL);

        // Execute the ping command
        status = system(command);

        // Get the end time
        gettimeofday(&end, NULL);

        // Calculate the time taken for the ping
        double time_taken = (end.tv_sec - start.tv_sec) * 1000.0; // Convert seconds to milliseconds
        time_taken += (end.tv_usec - start.tv_usec) / 1000.0; // Convert microseconds to milliseconds

        // Check if the ping command was successful
        if (status == 0) {
            printf("Reply from %s: time=%.2f ms\n", host, time_taken);
            total_time += time_taken; // Accumulate the RTT
        } else {
            printf("Request timed out for %s.\n", host);
        }

        // Sleep for 1 second before the next ping
        sleep(1);
    }

    // Calculate and display the average RTT if we had successful pings
    if (total_time > 0) {
        printf("Average RTT for %s: %.2f ms\n", host, total_time / MAX_PINGS);
    } else {
        printf("No successful pings to calculate average RTT.\n");
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check for an input host
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname or IP>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Call the ping function with the provided hostname or IP
    ping(argv[1]);

    return EXIT_SUCCESS;
}