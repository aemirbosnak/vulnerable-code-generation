//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define SERVER_IP "162.213.251.74" // Example speed test server IP
#define SERVER_PORT 5201
#define TEST_SIZE 10485760 // 10 MB in bytes
#define BUFFER_SIZE 1024

void print_usage() {
    printf("Usage: ./speed_test\n");
    printf("This program tests your internet download speed by connecting to a speed test server.\n");
}

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char *buffer;
    ssize_t bytes_received, total_bytes = 0;
    double elapsed_time;
    struct timespec start, end;

    buffer = (char *)malloc(BUFFER_SIZE);
    if (buffer == NULL) {
        perror("Failed to allocate memory");
        return EXIT_FAILURE;
    }

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        free(buffer);
        return EXIT_FAILURE;
    }

    // Setup server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    
    // Convert IP address from text to binary
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        perror("Invalid address");
        close(sock);
        free(buffer);
        return EXIT_FAILURE;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sock);
        free(buffer);
        return EXIT_FAILURE;
    }

    printf("Connected to server %s:%d. Starting download speed test...\n", SERVER_IP, SERVER_PORT);

    // Start timing
    clock_gettime(CLOCK_MONOTONIC, &start);

    // Download data
    while (total_bytes < TEST_SIZE) {
        bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received < 0) {
            perror("Error while receiving data");
            break;
        }
        total_bytes += bytes_received;
    }

    // End timing
    clock_gettime(CLOCK_MONOTONIC, &end);

    // Calculate elapsed time in seconds
    elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    // Calculate download speed in Mbps
    double download_speed_mbps = (total_bytes * 8) / (elapsed_time * 1e6);

    printf("Downloaded %ld bytes in %.2f seconds.\n", total_bytes, elapsed_time);
    printf("Your download speed: %.2f Mbps\n", download_speed_mbps);

    // Cleanup
    close(sock);
    free(buffer);
    return EXIT_SUCCESS;
}