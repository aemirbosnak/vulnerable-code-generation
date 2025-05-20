//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024
#define TEST_DURATION 5

void display_speed(double speed) {
    printf("Speed: %.2f KB/s\n", speed);
}

void measure_download_speed(const char* server_ip) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    size_t total_bytes = 0, bytes_received;
    time_t start_time, end_time;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sockfd);
        return;
    }

    start_time = time(NULL);
    
    // Receive data for a specified duration
    while (difftime(time(NULL), start_time) < TEST_DURATION) {
        bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) break;
        total_bytes += bytes_received;
    }

    end_time = time(NULL);
    
    close(sockfd);
    
    double duration_in_seconds = difftime(end_time, start_time);
    display_speed((total_bytes / 1024.0) / duration_in_seconds);
}

void measure_upload_speed(const char* server_ip) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    size_t total_bytes = 0, bytes_sent;
    time_t start_time, end_time;

    snprintf(buffer, BUFFER_SIZE, "This is a test data packet that will be uploaded repeatedly!");

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sockfd);
        return;
    }

    start_time = time(NULL);
    
    // Send data for a specified duration
    while (difftime(time(NULL), start_time) < TEST_DURATION) {
        bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
        if (bytes_sent <= 0) break;
        total_bytes += bytes_sent;
    }

    end_time = time(NULL);
    
    close(sockfd);
    
    double duration_in_seconds = difftime(end_time, start_time);
    display_speed((total_bytes / 1024.0) / duration_in_seconds);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <server_ip>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *server_ip = argv[1];

    printf("Starting download speed test...\n");
    measure_download_speed(server_ip);
    printf("Download speed test completed.\n");

    printf("Starting upload speed test...\n");
    measure_upload_speed(server_ip);
    printf("Upload speed test completed.\n");

    return EXIT_SUCCESS;
}