//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

double get_time_diff(struct timeval start, struct timeval end) {
    return (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;
}

void download_speed_test(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_read;
    struct timeval start, end;
    int total_bytes = 0;

    // Start timing
    gettimeofday(&start, NULL);
    
    while ((bytes_read = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        total_bytes += bytes_read;
    }

    // End timing
    gettimeofday(&end, NULL);
    
    double time_taken = get_time_diff(start, end);
    double speed_mbps = (total_bytes * 8) / (time_taken * 1000 * 1000);
    printf("Download speed: %.2f Mbps\n", speed_mbps);
}

void upload_speed_test(int sockfd) {
    char buffer[BUFFER_SIZE];
    struct timeval start, end;
    int bytes_written;
    int total_bytes = 0;

    // Fill buffer
    memset(buffer, 'A', sizeof(buffer));
    
    // Start timing
    gettimeofday(&start, NULL);

    while (total_bytes < (1024 * 1024)) { // Upload 1MB
        bytes_written = send(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_written < 0) {
            error("Error writing to socket");
        }
        total_bytes += bytes_written;
    }

    // End timing
    gettimeofday(&end, NULL);
    
    double time_taken = get_time_diff(start, end);
    double speed_mbps = (total_bytes * 8) / (time_taken * 1000 * 1000);
    printf("Upload speed: %.2f Mbps\n", speed_mbps);
}

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_ip> <server_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        error("Invalid address");
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }

    printf("Starting download speed test...\n");
    download_speed_test(sockfd);
    
    printf("Starting upload speed test...\n");
    upload_speed_test(sockfd);

    close(sockfd);
    return 0;
}