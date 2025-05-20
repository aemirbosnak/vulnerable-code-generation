//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define the size of the buffer to be used for data transfer
#define BUFFER_SIZE 1024

// Define the number of iterations to be performed for the speed test
#define ITERATIONS 10

// Define the IP address of the server to be used for the speed test
#define SERVER_IP "1.1.1.1"

// Define the port number of the server to be used for the speed test
#define SERVER_PORT 80

// Define the timeout value for the speed test in seconds
#define TIMEOUT 5

// Define the name of the file to be used for logging the speed test results
#define LOG_FILE "speed_test.log"

// Function to calculate the elapsed time in milliseconds between two timevals
long elapsed_time(struct timeval *start, struct timeval *end) {
    return (end->tv_sec - start->tv_sec) * 1000 + (end->tv_usec - start->tv_usec) / 1000;
}

// Function to perform the speed test
int speed_test() {
    // Create a socket for the speed test
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    // Set the timeout value for the socket
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
        perror("setsockopt");
        return -1;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return -1;
    }

    // Create a buffer for the data to be transferred
    char *buffer = malloc(BUFFER_SIZE);
    if (buffer == NULL) {
        perror("malloc");
        return -1;
    }

    // Perform the speed test iterations
    long total_time = 0;
    for (int i = 0; i < ITERATIONS; i++) {
        // Send data to the server
        int bytes_sent = send(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_sent == -1) {
            perror("send");
            return -1;
        }

        // Start the timer
        struct timeval start;
        gettimeofday(&start, NULL);

        // Receive data from the server
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received == -1) {
            perror("recv");
            return -1;
        }

        // Stop the timer
        struct timeval end;
        gettimeofday(&end, NULL);

        // Calculate the elapsed time
        long time = elapsed_time(&start, &end);

        // Update the total time
        total_time += time;
    }

    // Calculate the average speed
    double speed = (double)BUFFER_SIZE * 8 * ITERATIONS / total_time;

    // Log the speed test results
    FILE *fp = fopen(LOG_FILE, "a");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }
    fprintf(fp, "Speed: %.2f Mbps\n", speed);
    fclose(fp);

    // Close the socket
    close(sockfd);

    // Free the buffer
    free(buffer);

    return 0;
}

// Main function
int main() {
    // Perform the speed test
    if (speed_test() == -1) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}