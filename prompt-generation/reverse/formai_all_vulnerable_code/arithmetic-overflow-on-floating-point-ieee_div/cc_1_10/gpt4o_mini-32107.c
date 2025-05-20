//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>

#define SERVER_IP "127.0.0.1"  // Replace with server IP
#define SERVER_PORT 8080
#define BUFFER_SIZE 1024
#define FILE_SIZE_MB 10
#define UPLOAD_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

double get_time_diff(struct timeval start, struct timeval end) {
    return (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
}

void speed_test_download(int sockfd) {
    char buffer[BUFFER_SIZE];
    struct timeval start, end;
    size_t total_bytes = 0;

    gettimeofday(&start, NULL);
    
    // Read from the server
    while (total_bytes < BUFFER_SIZE * FILE_SIZE_MB) {
        ssize_t bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            break;
        }
        total_bytes += bytes_received;
    }

    gettimeofday(&end, NULL);
    double duration = get_time_diff(start, end);
    double speed_mbps = (total_bytes * 8) / (duration * 1e6); // Convert speed to Mbps

    printf("Download Speed: %.2f Mbps\n", speed_mbps);
}

void speed_test_upload(int sockfd) {
    char buffer[UPLOAD_SIZE];
    memset(buffer, 'A', UPLOAD_SIZE); // Fill buffer with dummy data
    struct timeval start, end;
    size_t total_bytes = UPLOAD_SIZE;

    gettimeofday(&start, NULL);
    
    // Send to server
    if (send(sockfd, buffer, UPLOAD_SIZE, 0) < 0) {
        error("Failed to send data");
    }

    gettimeofday(&end, NULL);
    double duration = get_time_diff(start, end);
    double speed_mbps = (total_bytes * 8) / (duration * 1e6); // Convert speed to Mbps

    printf("Upload Speed: %.2f Mbps\n", speed_mbps);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(SERVER_PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection to server failed");
    }

    printf("Starting speed test...\n");

    // Perform download speed test
    speed_test_download(sockfd);

    // Perform upload speed test
    speed_test_upload(sockfd);

    close(sockfd);
    return 0;
}