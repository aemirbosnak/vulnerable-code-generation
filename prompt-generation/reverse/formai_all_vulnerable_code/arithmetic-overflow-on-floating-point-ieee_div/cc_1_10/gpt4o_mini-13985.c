//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define SERVER_IP "your.server.ip" // Replace with actual server IP
#define SERVER_PORT 8080
#define BUFFER_SIZE 8192
#define TEST_DURATION 5

void report_speed(double bits, double time_taken) {
    double speed = bits / time_taken; // Calculate speed in bits/sec
    printf("Your speed: %.2f Mbps\n", speed / 1e6); // Convert to Mbps
}

void test_download_speed() {
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    int sockfd, bytes_received;
    double total_bytes = 0.0;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    time_t start_time = time(NULL);
    while (difftime(time(NULL), start_time) < TEST_DURATION) {
        bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) break;
        total_bytes += bytes_received;
    }

    close(sockfd);
    report_speed(total_bytes * 8, difftime(time(NULL), start_time)); // Convert bytes to bits
}

void test_upload_speed() {
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    int sockfd;
    double total_bytes = 0.0;

    memset(buffer, 'A', sizeof(buffer)); // Fill buffer with dummy data
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    time_t start_time = time(NULL);
    while (difftime(time(NULL), start_time) < TEST_DURATION) {
        send(sockfd, buffer, BUFFER_SIZE, 0);
        total_bytes += BUFFER_SIZE;
    }

    close(sockfd);
    report_speed(total_bytes * 8, difftime(time(NULL), start_time)); // Convert bytes to bits
}

int main() {
    printf("Welcome to the Internet Speed Test Application!\n");
    printf("Starting Download Speed Test...\n");
    test_download_speed();
    printf("Download Speed Test Complete!\n\n");

    printf("Starting Upload Speed Test...\n");
    test_upload_speed();
    printf("Upload Speed Test Complete!\n");

    return 0;
}