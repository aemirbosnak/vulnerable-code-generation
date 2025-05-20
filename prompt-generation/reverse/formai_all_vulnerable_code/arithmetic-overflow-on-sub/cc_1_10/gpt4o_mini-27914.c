//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define SERVER_IP "example.com" // Change to a valid server to test
#define SERVER_PORT 80
#define BUFFER_SIZE 1024
#define TEST_FILE "/1MB.bin" // Placeholder for a larger file

void print_speed(double seconds, size_t file_size) {
    double speed_mbps = (file_size * 8) / (seconds * 1000000.0);
    printf("Download completed in %.2f seconds.\n", seconds);
    printf("Speed: %.2f Mbps\n", speed_mbps);
}

size_t fetch_file(const char *host) {
    int sockfd;
    struct sockaddr_in server_addr;
    char request[256], buffer[BUFFER_SIZE];
    size_t total_bytes = 0;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, host, &server_addr.sin_addr);
    
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", TEST_FILE, host);
    send(sockfd, request, strlen(request), 0);

    while (1) {
        ssize_t bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        total_bytes += bytes_received;
    }

    close(sockfd);
    return total_bytes;
}

int main() {
    printf("Welcome to the Mind-Bending Internet Speed Test!\n");
    printf("This will test your download speed from a given server.\n");

    const char *host = SERVER_IP;
    printf("Fetching the test file from: %s\n\n", host);

    clock_t start_time = clock();
    size_t file_size = fetch_file(host);
    clock_t end_time = clock();

    double seconds = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    if (file_size > 0) {
        print_speed(seconds, file_size);
    } else {
        printf("Failed to retrieve data. Please check the server IP and file path.\n");
    }

    return 0;
}