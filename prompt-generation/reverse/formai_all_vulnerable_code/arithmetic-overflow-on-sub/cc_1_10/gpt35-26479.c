//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

#define TEST_URL "http://speedtest.net/"
#define BUFFER_SIZE 10240

// Function to measure time taken by a specific code
double get_execution_time(struct timeval t1, struct timeval t2) {
    return ((double)(t2.tv_sec - t1.tv_sec) * 1000.0 + (double)(t2.tv_usec - t1.tv_usec) / 1000.0);
}

// Function to perform speed test
void run_speed_test() {
    char url_buffer[BUFFER_SIZE];
    char response_buffer[BUFFER_SIZE];
    struct timeval start_time, end_time;

    // Build the speed test URL
    snprintf(url_buffer, sizeof(url_buffer), "%s?random=%ld", TEST_URL, random());

    // Start the timer
    gettimeofday(&start_time, NULL);

    // Send a GET request to the speed test URL
    FILE *stream = popen(url_buffer, "r");
    if (stream == NULL) {
        perror("Error sending GET request");
        exit(EXIT_FAILURE);
    }

    // Read the response from the speed test server
    size_t bytes_read = fread(response_buffer, 1, sizeof(response_buffer), stream);
    if (bytes_read == 0) {
        perror("Error reading response from server");
        exit(EXIT_FAILURE);
    }

    // Close the popen stream
    pclose(stream);

    // End the timer
    gettimeofday(&end_time, NULL);

    // Calculate the execution time and speed
    double execution_time = get_execution_time(start_time, end_time);
    double speed = (double) bytes_read / execution_time;

    printf("Speed Test Results:\n");
    printf("===================\n");
    printf("Bytes Read: %zu\n", bytes_read);
    printf("Execution Time: %.2f ms\n", execution_time);
    printf("Download Speed: %.2f bytes/ms\n", speed);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Run the speed test
    run_speed_test();

    return EXIT_SUCCESS;
}