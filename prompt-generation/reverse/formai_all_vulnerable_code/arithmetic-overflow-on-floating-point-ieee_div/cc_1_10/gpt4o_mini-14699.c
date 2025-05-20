//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024
#define DOWNLOAD_FILE_SIZE (100 * 1024 * 1024) // Assume file size is 100MB

void perform_speed_test(const char *server_ip) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;
    size_t total_received = 0;
    time_t start_time, end_time;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Start the speed test
    start_time = time(NULL);
    printf("Starting speed test...\n");

    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        total_received += bytes_received;
        if (total_received >= DOWNLOAD_FILE_SIZE) {
            break;
        }
    }

    end_time = time(NULL);
    close(sockfd);

    // Calculate speed
    double total_time = difftime(end_time, start_time);
    double speed_mbps = (total_received * 8) / (total_time * 1024 * 1024);

    printf("Total bytes received: %zu\n", total_received);
    printf("Time taken: %.2f seconds\n", total_time);
    printf("Download speed: %.2f Mbps\n", speed_mbps);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <server_ip>\n", argv[0]);
        return EXIT_FAILURE;
    }

    perform_speed_test(argv[1]);
    return EXIT_SUCCESS;
}