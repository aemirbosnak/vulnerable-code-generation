//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define SERVER_IP "127.0.0.1" // Change this to your server's IP
#define SERVER_PORT 8080
#define BUFFER_SIZE 1048576 // 1 MB Buffer

void error(const char *msg) {
    perror(msg);
    exit(1);
}

double get_speed(size_t bytes, double time_taken) {
    return (bytes / 1024.0 / 1024.0) / time_taken; // Convert to MB/s
}

void download_test(int sockfd) {
    char *buffer = malloc(BUFFER_SIZE);
    struct timeval start, end;
    double time_taken;

    // Mark the start time
    gettimeofday(&start, NULL);

    size_t total_bytes_received = 0;
    ssize_t bytes_received = 0;

    while (1) {
        bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break; // No more data, exit loop
        }
        total_bytes_received += bytes_received;
    }

    // Mark the end time
    gettimeofday(&end, NULL);

    // Calculate time taken for download
    time_taken = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    printf("Download speed: %.2f MB/s\n", get_speed(total_bytes_received, time_taken));

    free(buffer);
}

void upload_test(int sockfd) {
    char *buffer = malloc(BUFFER_SIZE);
    memset(buffer, 'A', BUFFER_SIZE); // Fill buffer with dummy data
    struct timeval start, end;
    double time_taken;

    // Mark the start time
    gettimeofday(&start, NULL);

    size_t total_bytes_sent = 0;
    ssize_t bytes_sent = 0;

    // Send the data
    while (total_bytes_sent < BUFFER_SIZE) {
        bytes_sent = send(sockfd, buffer + total_bytes_sent, BUFFER_SIZE - total_bytes_sent, 0);
        if (bytes_sent <= 0) {
            break; // Error occurred
        }
        total_bytes_sent += bytes_sent;
    }

    // Mark the end time
    gettimeofday(&end, NULL);

    // Calculate time taken for upload
    time_taken = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    printf("Upload speed: %.2f MB/s\n", get_speed(total_bytes_sent, time_taken));

    free(buffer);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Socket creation failed");
    }

    // Configure server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    
    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        error("Invalid address/Address not supported");
    }

    // Attempt to connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }

    printf("Starting download test...\n");
    download_test(sockfd);

    printf("Starting upload test...\n");
    upload_test(sockfd);

    // Close the socket
    close(sockfd);
    
    return 0;
}