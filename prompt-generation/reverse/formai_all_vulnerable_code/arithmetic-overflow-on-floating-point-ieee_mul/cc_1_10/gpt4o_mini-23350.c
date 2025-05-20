//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080
#define BUFFER_SIZE 1024*1024 // Buffer size of 1 MB for testing
#define TEST_DURATION 5 // Test duration in seconds

void speedTest();

int main() {
    printf("=== Internet Speed Test ===\n");
    printf("Testing download and upload speeds, please wait...\n\n");
    speedTest();
    return 0;
}

void speedTest() {
    int sock;
    struct sockaddr_in server_addr;
    char *buffer;
    long total_bytes_downloaded = 0;
    long total_bytes_uploaded = 0;

    buffer = (char *)malloc(BUFFER_SIZE);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    memset(buffer, 'A', BUFFER_SIZE); // Fill buffer with dummy data
    
    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        free(buffer);
        exit(EXIT_FAILURE);
    }

    // Set up server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to the server failed");
        close(sock);
        free(buffer);
        exit(EXIT_FAILURE);
    }

    // Download speed test
    time_t start_time = time(NULL);
    while (difftime(time(NULL), start_time) < TEST_DURATION) {
        ssize_t bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        total_bytes_downloaded += bytes_received;
    }
    double download_time = difftime(time(NULL), start_time);

    // Upload speed test
    start_time = time(NULL);
    while (difftime(time(NULL), start_time) < TEST_DURATION) {
        ssize_t bytes_sent = send(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_sent <= 0) {
            break;
        }
        total_bytes_uploaded += bytes_sent;
    }
    double upload_time = difftime(time(NULL), start_time);
    
    // Close the socket
    close(sock);
    free(buffer);

    // Calculate speeds
    double download_speed = (total_bytes_downloaded * 8) / (download_time * 1000000); // Mbps
    double upload_speed = (total_bytes_uploaded * 8) / (upload_time * 1000000); // Mbps

    // Report results
    printf("=== Speed Test Results ===\n");
    printf("Download Speed: %.2f Mbps\n", download_speed);
    printf("Upload Speed: %.2f Mbps\n", upload_speed);
}