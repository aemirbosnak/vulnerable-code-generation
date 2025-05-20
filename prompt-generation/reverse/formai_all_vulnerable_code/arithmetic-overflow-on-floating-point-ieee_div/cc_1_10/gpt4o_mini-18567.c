//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define SERVER_IP "speed.hetzner.de" // Sample speed test server
#define SERVER_PORT 80
#define BUFFER_SIZE 8192

void report_speed(double speed, const char *operation) {
    printf("Your %s speed is: %.2f Mbps\n", operation, speed);
}

double calculate_speed(size_t bytes, double seconds) {
    return (bytes * 8) / (seconds * 1024 * 1024); // Convert to Mbps
}

void download_test() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    size_t total_bytes = 0;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    const char *request = "GET /100MB.bin HTTP/1.1\r\nHost: " SERVER_IP "\r\nConnection: close\r\n\r\n";
    send(sockfd, request, strlen(request), 0);

    time_t start_time = time(NULL);
    
    while (1) {
        ssize_t bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) break;
        total_bytes += bytes_received;
    }

    time_t end_time = time(NULL);
    close(sockfd);

    double elapsed_time = difftime(end_time, start_time);
    double download_speed = calculate_speed(total_bytes, elapsed_time);
    report_speed(download_speed, "download");
}

void upload_test() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    size_t total_bytes = 0;
    const char *data = malloc(BUFFER_SIZE);
    
    // Fill buffer with random data for upload test
    memset((void*)data, 'A', BUFFER_SIZE);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    const char *request = "POST /upload HTTP/1.1\r\nHost: " SERVER_IP "\r\nContent-Length: 8192\r\n\r\n";
    send(sockfd, request, strlen(request), 0);

    time_t start_time = time(NULL);
    
    while (total_bytes < BUFFER_SIZE) {
        ssize_t bytes_sent = send(sockfd, data + total_bytes, BUFFER_SIZE - total_bytes, 0);
        if (bytes_sent <= 0) break;
        total_bytes += bytes_sent;
    }
    
    time_t end_time = time(NULL);
    close(sockfd);
    free((void*)data);

    double elapsed_time = difftime(end_time, start_time);
    double upload_speed = calculate_speed(total_bytes, elapsed_time);
    report_speed(upload_speed, "upload");
}

int main() {
    printf("Starting Internet Speed Test...\n");
    download_test();
    upload_test();
    
    return 0;
}