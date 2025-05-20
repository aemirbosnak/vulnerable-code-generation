//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define SERVER_IP "1.1.1.1"  // Example IP for testing
#define SERVER_PORT 80
#define BUFFER_SIZE 8192
#define TEST_DURATION 10  // Duration of the test in seconds

void perform_speed_test(int duration) {
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;
    int sockfd;
    long total_bytes = 0;
    time_t start_time, current_time;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

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

    snprintf(buffer, sizeof(buffer), "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", SERVER_IP);
    
    // Send request
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Send failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    start_time = time(NULL);
    do {
        bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received > 0) {
            total_bytes += bytes_received;
        } else if (bytes_received < 0) {
            perror("Receive failed");
            close(sockfd);
            exit(EXIT_FAILURE);
        }
        current_time = time(NULL);
    } while (current_time - start_time < duration);

    close(sockfd);

    double speed_mbps = (total_bytes * 8.0) / (1024 * 1024 * duration);
    printf("Downloaded %ld bytes in %d seconds\n", total_bytes, duration);
    printf("Speed: %.2f Mbps\n", speed_mbps);
}

int main() {
    printf("Starting Internet Speed Test...\n");
    perform_speed_test(TEST_DURATION);
    printf("Test completed!\n");
    return 0;
}