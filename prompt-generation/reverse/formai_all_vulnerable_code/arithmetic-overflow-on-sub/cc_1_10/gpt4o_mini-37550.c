//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define SERVER_IP "www.speedtest.net"
#define SERVER_PORT 80
#define BUFFER_SIZE 4096

void measure_speed() {
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int sockfd, bytes_sent, bytes_received;
    char request[BUFFER_SIZE];
    clock_t start_time, end_time;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setup server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        perror("Invalid address");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Create a HTTP GET request
    snprintf(request, sizeof(request), "GET /random/2048 HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", SERVER_IP);

    // Measure upload speed (sending request)
    start_time = clock();
    bytes_sent = send(sockfd, request, strlen(request), 0);
    if (bytes_sent < 0) {
        perror("Send failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Measure download speed (receiving response)
    int total_bytes = 0;
    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        total_bytes += bytes_received;
    }

    if (bytes_received < 0) {
        perror("Receive failed");
    }

    end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    // Calculate download speed in Mbps
    double download_speed = (total_bytes * 8) / (1024 * 1024 * time_taken);
    printf("Download Speed: %.2f Mbps\n", download_speed);

    // Close the socket
    close(sockfd);
}

int main() {
    printf("Starting Internet Speed Test...\n");
    measure_speed();
    printf("Speed Test Completed!\n");
    return 0;
}