//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define SERVER_IP "ipv4-server.example.com" // Replace with an actual server
#define SERVER_PORT 80
#define BUFFER_SIZE 8192

void error_exit(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

double get_download_speed(size_t bytes_received, double duration) {
    return (bytes_received / 1024.0) / duration; // Speed in KB/s
}

void perform_speed_test() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received = 0;

    const char *request_template = "GET /test-file HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n";
    char request[256];

    sprintf(request, request_template, SERVER_IP);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error_exit("Socket creation failed");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        error_exit("Invalid address or Address not supported");
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error_exit("Connection failed");
    }

    // Send request
    send(sockfd, request, strlen(request), 0);

    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

    // Read response
    while ((bytes_received += recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        // You can process the buffer if needed
    }

    gettimeofday(&end_time, NULL);
    close(sockfd);

    double duration = (end_time.tv_sec - start_time.tv_sec) + 
                      (end_time.tv_usec - start_time.tv_usec) / 1000000.0;

    double speed = get_download_speed(bytes_received, duration);

    printf("Downloaded %d bytes in %.2f seconds\n", bytes_received, duration);
    printf("Download speed: %.2f KB/s\n", speed);
}

int main() {
    printf("Starting Internet Speed Test...\n");
    perform_speed_test();
    printf("Speed Test Completed.\n");
    return 0;
}