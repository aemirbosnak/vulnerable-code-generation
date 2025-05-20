//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SERVER_IP "1.1.1.1" // Cloudflare DNS server for latency testing
#define PORT 80
#define BUFFER_SIZE 8192

void calculate_speed(struct timeval start, struct timeval end, size_t bytes) {
    double elapsed_time_sec = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
    double speed_mbps = (bytes * 8) / (elapsed_time_sec * 1e6); // Convert to Mbps
    printf("Download speed: %.2f Mbps\n", speed_mbps);
}

size_t perform_download_test() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    const char *request = "GET / HTTP/1.1\r\nHost: " SERVER_IP "\r\nConnection: close\r\n\r\n";
    size_t total_bytes_read = 0;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        perror("Invalid address/Address not supported");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    send(sockfd, request, strlen(request), 0);
    struct timeval start, end;
    gettimeofday(&start, NULL);

    ssize_t bytes_read;
    while ((bytes_read = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        total_bytes_read += bytes_read;
    }

    gettimeofday(&end, NULL);
    close(sockfd);

    if (bytes_read < 0) {
        perror("Recv failed");
        exit(EXIT_FAILURE);
    }

    return total_bytes_read;
}

void print_usage() {
    printf("Usage: ./speed_test\n");
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        print_usage();
        return EXIT_FAILURE;
    }

    printf("Starting internet speed test...\n");
    
    size_t bytes_downloaded = perform_download_test();
    printf("Total data downloaded: %zu bytes\n", bytes_downloaded);
    
    struct timeval start, end;
    gettimeofday(&start, NULL);
    usleep(1000000); // 1 second wait
    gettimeofday(&end, NULL);

    calculate_speed(start, end, bytes_downloaded);

    printf("Internet speed test completed.\n");
    return EXIT_SUCCESS;
}