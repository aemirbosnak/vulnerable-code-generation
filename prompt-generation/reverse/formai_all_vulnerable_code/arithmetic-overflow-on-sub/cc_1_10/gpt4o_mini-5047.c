//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 80
#define SERVER_IP "your.server.ip.address" // replace with the actual server IP

void error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

double get_time_diff(struct timeval start, struct timeval end) {
    return (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
}

void test_download_speed(int sockfd) {
    char buffer[BUFFER_SIZE];
    struct timeval start_time, end_time;
    size_t total_bytes = 0;
    ssize_t bytes_read;

    gettimeofday(&start_time, NULL);
    while ((bytes_read = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        total_bytes += bytes_read;
    }
    gettimeofday(&end_time, NULL);

    if (bytes_read < 0) {
        error("Error receiving data");
    }

    double time_taken = get_time_diff(start_time, end_time);
    double speed_mbps = (total_bytes * 8) / (time_taken * 1000000); // convert to Mbps

    printf("Download Speed: %.2f Mbps\n", speed_mbps);
}

void test_upload_speed(int sockfd) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 'A', sizeof(buffer)); // Fill buffer with dummy data
    struct timeval start_time, end_time;
    size_t total_bytes = 0;
    ssize_t bytes_sent;

    gettimeofday(&start_time, NULL);
    for (int i = 0; i < 100; i++) { // Sending data 100 times
        bytes_sent = send(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_sent < 0) {
            error("Error sending data");
        }
        total_bytes += bytes_sent;
    }
    gettimeofday(&end_time, NULL);

    double time_taken = get_time_diff(start_time, end_time);
    double speed_mbps = (total_bytes * 8) / (time_taken * 1000000); // convert to Mbps

    printf("Upload Speed: %.2f Mbps\n", speed_mbps);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    // Setup the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        error("Invalid address or Address not supported");
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }

    printf("Connected to server. Starting speed test...\n");

    // Test download speed
    test_download_speed(sockfd);
    
    // Test upload speed, we need to reconnect
    close(sockfd);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }

    // Test upload speed
    test_upload_speed(sockfd);

    close(sockfd);
    return 0;
}