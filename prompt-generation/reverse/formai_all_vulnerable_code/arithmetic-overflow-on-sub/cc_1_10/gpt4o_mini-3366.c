//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define TEST_SIZE (1024 * 1024 * 10) // 10 Megabytes for testing

void calculate_speed(double time_taken, int data_size, const char* direction) {
    double speed = (data_size / (1024.0 * 1024.0)) / time_taken; // speed in MBps
    printf("Your %s speed: %.2f MB/s\n", direction, speed);
}

void simulate_download(int sockfd) {
    char *buffer = (char *)malloc(BUFFER_SIZE);
    int total_received = 0;
    struct timeval start, end;

    gettimeofday(&start, NULL);
    
    while (total_received < TEST_SIZE) {
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        total_received += bytes_received;
    }

    gettimeofday(&end, NULL);
    
    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    calculate_speed(time_taken, total_received, "download");

    free(buffer);
}

void simulate_upload(int sockfd) {
    char *buffer = (char *)malloc(BUFFER_SIZE);
    memset(buffer, 'x', BUFFER_SIZE); // Fill the buffer with dummy data
    int total_sent = 0;
    struct timeval start, end;

    gettimeofday(&start, NULL);
    
    while (total_sent < TEST_SIZE) {
        int bytes_sent = send(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_sent <= 0) {
            break;
        }
        total_sent += bytes_sent;
    }

    gettimeofday(&end, NULL);
    
    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    calculate_speed(time_taken, total_sent, "upload");

    free(buffer);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080); // Change port number as needed
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr); // Change to server IP

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Starting download speed test...\n");
    simulate_download(sockfd);

    printf("Starting upload speed test...\n");
    simulate_upload(sockfd);

    close(sockfd);
    
    return 0;
}