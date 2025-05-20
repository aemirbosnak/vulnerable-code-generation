//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define BILLION 1000000000L

int main() {
    struct timespec start, end;
    long long unsigned int diff;
    int bytes = 0;
    int timeInSeconds = 0;
    float speed = 0;

    printf("Welcome to the Internet Speed Test Application!\n\n");
    printf("Please enter the amount of time in seconds you want to run the test for: ");
    scanf("%d", &timeInSeconds);

    // Ensure we are running the test for at least one second
    if (timeInSeconds <= 0) {
        printf("Invalid input. The test must run for at least one second. Exiting...\n");
        return 1;
    }

    printf("Running speed test for %d seconds...\n\n", timeInSeconds);

    // Get the start time
    clock_gettime(CLOCK_MONOTONIC, &start);

    // Create a buffer with the maximum amount of memory we want to allocate,
    // assumed here to be 10 MB
    int bufferSize = 1024 * 1024 * 10;
    char *buffer = (char *)malloc(bufferSize);
    if (buffer == NULL) {
        printf("Could not allocate memory for test. Exiting...\n");
        return 1;
    }

    // Begin the speed test
    do {
        bytes += bufferSize;
        printf("Buffer size: %d MB\n", bytes / (1024 * 1024));
        free(buffer);
        buffer = (char *)malloc(bufferSize);
    } while (((float)(end.tv_nsec - start.tv_nsec) / BILLION) +
             (end.tv_sec - start.tv_sec) < (float)timeInSeconds);

    // Get the end time
    clock_gettime(CLOCK_MONOTONIC, &end);
    diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;

    // Calculate the speed
    speed = ((float)bytes / diff) * BILLION * 8 / 1024 / 1024;

    // Print the results
    printf("\nTest complete!\n");
    printf("Total data transferred: %d MB\n", bytes / (1024 * 1024));
    printf("Total time taken: %llu ns\n", (long long unsigned int)diff);
    printf("Average speed: %.2f Mbps\n", speed);

    return 0;
}