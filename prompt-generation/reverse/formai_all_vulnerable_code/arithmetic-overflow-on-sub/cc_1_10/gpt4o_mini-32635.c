//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define SERVER_IP "example.com"  // You can specify any server that supports HTTP
#define SERVER_PORT 80
#define BUFFER_SIZE 1024

void display_speed(double seconds, size_t bytes) {
    double megabytes = bytes / (1024.0 * 1024.0);
    double speed_mbps = (megabytes / seconds) * 8.0; // Convert to Mbps

    printf("\n-------------------------------------\n");
    printf("Download Test Complete!\n");
    printf("Total Data Downloaded: %.2f MB\n", megabytes);
    printf("Time Taken: %.2f seconds\n", seconds);
    printf("Your Internet Speed: %.2f Mbps\n", speed_mbps);
    printf("-------------------------------------\n");
}

int main() {
    int sock;
    struct sockaddr_in server;
    char request[BUFFER_SIZE], response[BUFFER_SIZE];
    struct timeval start, end;
    size_t total_bytes = 0;

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);

    // Convert IP address from text to binary form
    if (inet_pton(AF_INET, SERVER_IP, &server.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        close(sock);
        return EXIT_FAILURE;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connection failed");
        close(sock);
        return EXIT_FAILURE;
    }

    // Create the HTTP GET request
    snprintf(request, sizeof(request), "GET /1mb.bin HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", SERVER_IP);

    // Send the request
    send(sock, request, strlen(request), 0);
    printf("Sending request to %s...\n", SERVER_IP);
    
    // Start the timer
    gettimeofday(&start, NULL);

    // Receive the response
    while (1) {
        ssize_t bytes_received = recv(sock, response, sizeof(response) - 1, 0);
        if (bytes_received <= 0) {
            break; // No more data or error
        }
        total_bytes += bytes_received;
    }

    // Stop the timer
    gettimeofday(&end, NULL);

    // Calculate the elapsed time
    double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;

    // Display the speed
    display_speed(elapsed_time, total_bytes);

    // Clean up
    close(sock);
    return EXIT_SUCCESS;
}