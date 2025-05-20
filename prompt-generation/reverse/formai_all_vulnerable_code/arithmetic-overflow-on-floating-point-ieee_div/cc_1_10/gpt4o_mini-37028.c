//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define SERVER_IP "127.0.0.1" // Local server for testing purposes
#define PORT 8080
#define BUFFER_SIZE 1024 * 1024 // 1MB

void displayUsage();
void measureDownloadSpeed(int sockfd);
void measureUploadSpeed(int sockfd);
void reportSpeed(const char *type, double speed);

int main() {
    int sockfd;
    struct sockaddr_in serverAddr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return EXIT_FAILURE;
    }

    // Define server information
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, SERVER_IP, &serverAddr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        return EXIT_FAILURE;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Connection failed");
        return EXIT_FAILURE;
    }

    // Display usage
    displayUsage();

    // Measure download speed
    measureDownloadSpeed(sockfd);

    // Measure upload speed
    measureUploadSpeed(sockfd);

    // Close the socket
    close(sockfd);
    return EXIT_SUCCESS;
}

void displayUsage() {
    printf("=== Internet Speed Test Application ===\n");
    printf("This program measures your download and upload speeds.\n");
    printf("Ensure that a server is running to test speed.\n\n");
}

void measureDownloadSpeed(int sockfd) {
    char buffer[BUFFER_SIZE];
    double totalBytesReceived = 0;
    struct timespec start, end;

    // Request download speed test
    send(sockfd, "DOWNLOAD", strlen("DOWNLOAD"), 0);

    // Start timer
    clock_gettime(CLOCK_MONOTONIC, &start);
    while (1) {
        int bytesReceived = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytesReceived <= 0) {
            break; // Connection closed or error
        }
        totalBytesReceived += bytesReceived;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);

    double elapsedTime = (end.tv_sec - start.tv_sec) + 
                         (end.tv_nsec - start.tv_nsec) / 1e9;
    double speedMbps = (totalBytesReceived * 8 / elapsedTime) / (1024 * 1024);
    
    reportSpeed("Download", speedMbps);
}

void measureUploadSpeed(int sockfd) {
    char buffer[BUFFER_SIZE];
    double totalBytesSent = 0;
    struct timespec start, end;

    // Fill buffer with random data
    memset(buffer, 'A', BUFFER_SIZE);

    // Request upload speed test
    send(sockfd, "UPLOAD", strlen("UPLOAD"), 0);

    // Start timer
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < 100; ++i) { // Send data multiple times
        int bytesSent = send(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytesSent <= 0) {
            break; // Connection closed or error
        }
        totalBytesSent += bytesSent;
    }
    clock_gettime(CLOCK_MONOTONIC, &end);

    double elapsedTime = (end.tv_sec - start.tv_sec) + 
                         (end.tv_nsec - start.tv_nsec) / 1e9;
    double speedMbps = (totalBytesSent * 8 / elapsedTime) / (1024 * 1024);

    reportSpeed("Upload", speedMbps);
}

void reportSpeed(const char *type, double speed) {
    printf("Your %s speed is: %.2f Mbps\n", type, speed);
    if (speed < 5.0) {
        printf("The speed is too low. Consider checking your connection!\n");
    } else if (speed < 25.0) {
        printf("You're within a decent range, but could be better.\n");
    } else {
        printf("Fantastic! You seem to have a solid connection!\n");
    }
}