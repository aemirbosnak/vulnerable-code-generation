//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define SERVER_PORT 80
#define BUFFER_SIZE 8192
#define DOWNLOAD_SIZE 104857600 // 100 MB

void print_usage() {
    printf("Usage: speedtest <server_ip>\n");
    printf("Example: speedtest 192.168.1.1\n");
}

long long get_time_diff(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) * 1000000000LL + (end.tv_nsec - start.tv_nsec);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *server_ip = argv[1];
    int sockfd;
    struct sockaddr_in server_addr;
    char request[2048];
    char buffer[BUFFER_SIZE];
    size_t total_received = 0;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Prepare HTTP GET request
    snprintf(request, sizeof(request),
             "GET /100MB.zip HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n", server_ip);

    // Send request to server
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("Send failed");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Start time measurement
    struct timespec start_time, end_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);

    // Receive data
    while (total_received < DOWNLOAD_SIZE) {
        ssize_t bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break; // Connection closed or error
        }
        total_received += bytes_received;
    }

    // End time measurement
    clock_gettime(CLOCK_MONOTONIC, &end_time);

    // Calculate elapsed time
    long long elapsed_time = get_time_diff(start_time, end_time);
    double elapsed_seconds = (double)elapsed_time / 1e9;

    // Calculate download speed in Mbps
    double download_speed_mbps = (total_received * 8) / (elapsed_seconds * 1e6);

    printf("Downloaded: %.2f MB\n", total_received / (1024.0 * 1024.0));
    printf("Elapsed Time: %.2f seconds\n", elapsed_seconds);
    printf("Download Speed: %.2f Mbps\n", download_speed_mbps);

    // Clean up
    close(sockfd);
    return EXIT_SUCCESS;
}