//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define SERVER_IP "speed.hetzner.de" // A public speed test server
#define SERVER_PORT 8080
#define BUFFER_SIZE 8192 // Size of the buffer for data transfer

void error(const char *msg) {
    perror(msg);
    exit(1);
}

double get_download_speed(int sockfd) {
    char buffer[BUFFER_SIZE];
    struct timeval start, end;
    size_t total_bytes = 0;
    ssize_t bytes_received;

    // Start the timer
    gettimeofday(&start, NULL);
    
    // Request the file
    const char *request = "GET /100MB.bin HTTP/1.1\r\nHost: " SERVER_IP "\r\nConnection: close\r\n\r\n";
    send(sockfd, request, strlen(request), 0);

    // Read data
    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        total_bytes += bytes_received;
    }

    // Stop the timer
    gettimeofday(&end, NULL);

    // Calculate download speed in Mbps
    double duration = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    double speed_mbps = (total_bytes * 8) / (duration * 1000000);
    return speed_mbps;
}

double get_upload_speed(int sockfd) {
    char buffer[BUFFER_SIZE];
    struct timeval start, end;
    size_t total_bytes = 0;
    ssize_t bytes_sent;

    // Start the timer
    gettimeofday(&start, NULL);

    // Send dummy data
    memset(buffer, 'A', BUFFER_SIZE);
    for (int i = 0; i < 10; ++i) {
        bytes_sent = send(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_sent > 0) {
            total_bytes += bytes_sent;
        }
    }

    // Stop the timer
    gettimeofday(&end, NULL);

    // Calculate upload speed in Mbps
    double duration = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    double speed_mbps = (total_bytes * 8) / (duration * 1000000);
    return speed_mbps;
}

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // Set server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &serv_addr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting to server");
    }

    // Get download speed
    printf("Testing download speed...\n");
    double download_speed = get_download_speed(sockfd);
    printf("Download Speed: %.2f Mbps\n", download_speed);

    // Close and create a new socket for upload test
    close(sockfd);
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // Test upload speed to the same server
    printf("Testing upload speed...\n");
    double upload_speed = get_upload_speed(sockfd);
    printf("Upload Speed: %.2f Mbps\n", upload_speed);

    // Clean up
    close(sockfd);
    return 0;
}