//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define SERVER_ADDRESS "speed.hetzner.de" // A public speed test server
#define SERVER_PORT 3000
#define TEST_SIZE (50 * 1024 * 1024) // 50 MB for testing

// Function to get the current time in milliseconds
long long current_time_millis() {
    struct timeval te;
    gettimeofday(&te, NULL); // Get current time
    long long milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000; // Convert to milliseconds
    return milliseconds;
}

// Function to perform download speed test
double download_test() {
    int sockfd;
    char *buffer;
    struct sockaddr_in server_addr;
    long long start_time, end_time;

    buffer = (char *)malloc(TEST_SIZE);
    if (buffer == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        free(buffer);
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDRESS, &server_addr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        free(buffer);
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Start downloading
    start_time = current_time_millis();
    ssize_t bytes_received = recv(sockfd, buffer, TEST_SIZE, 0);
    end_time = current_time_millis();

    if (bytes_received < 0) {
        perror("Download failed");
    }

    // Calculate download speed (in Mbps)
    double time_taken = (end_time - start_time) / 1000.0; // time in seconds
    double speed_mbps = (bytes_received * 8) / (time_taken * 1024 * 1024); // convert bytes to Megabits

    // Cleanup
    free(buffer);
    close(sockfd);

    return speed_mbps;
}

// Function to perform upload speed test
double upload_test() {
    int sockfd;
    char *buffer;
    struct sockaddr_in server_addr;
    long long start_time, end_time;

    buffer = (char *)malloc(TEST_SIZE);
    if (buffer == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    memset(buffer, 'A', TEST_SIZE); // Fill buffer with 'A'

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        free(buffer);
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDRESS, &server_addr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        free(buffer);
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Start uploading
    start_time = current_time_millis();
    ssize_t bytes_sent = send(sockfd, buffer, TEST_SIZE, 0);
    end_time = current_time_millis();

    if (bytes_sent < 0) {
        perror("Upload failed");
    }

    // Calculate upload speed (in Mbps)
    double time_taken = (end_time - start_time) / 1000.0; // time in seconds
    double speed_mbps = (bytes_sent * 8) / (time_taken * 1024 * 1024); // convert bytes to Megabits

    // Cleanup
    free(buffer);
    close(sockfd);

    return speed_mbps;
}

int main() {
    printf("=== Welcome to the C Internet Speed Test ===\n");

    double download_speed = download_test();
    printf("Download Speed: %.2f Mbps\n", download_speed);

    double upload_speed = upload_test();
    printf("Upload Speed: %.2f Mbps\n", upload_speed);

    printf("=== Thank you for using the Speed Test! ===\n");
    return 0;
}