//MISTRAL-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define SERVER_PORT 8080
#define TIME_INTERVAL 5000 // 5 seconds
#define MAX_BUFFER 1024

// Function to get current time in milliseconds
unsigned long get_current_time() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (ts.tv_sec * 1000) + (ts.tv_nsec / 1000000);
}

// Function to calculate the difference between two timestamps in milliseconds
unsigned long time_diff(unsigned long start_time, unsigned long end_time) {
    return end_time - start_time;
}

int main() {
    int sockfd, new_sockfd, client_len;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_BUFFER];
    unsigned long start_time, end_time;

    // Initialize socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to the server\n");

    start_time = get_current_time();

    while (1) {
        // Send request to the server
        if (send(sockfd, "REQUEST\n", 7, 0) < 0) {
            perror("Send failed");
            exit(EXIT_FAILURE);
        }

        // Receive response from the server
        memset(buffer, 0, MAX_BUFFER);
        if (recv(sockfd, buffer, MAX_BUFFER, 0) < 0) {
            perror("Receive failed");
            exit(EXIT_FAILURE);
        }

        // Print the received data
        printf("Received data: %s\n", buffer);

        end_time = get_current_time();
        unsigned long elapsed_time = time_diff(start_time, end_time);

        printf("Elapsed time: %lu ms\n", elapsed_time);

        // Wait for the next interval
        usleep(TIME_INTERVAL);
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}