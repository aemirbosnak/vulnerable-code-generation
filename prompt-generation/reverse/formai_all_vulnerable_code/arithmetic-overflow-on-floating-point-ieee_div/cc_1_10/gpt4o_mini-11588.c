//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024
#define TEST_DURATION 5

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void speedTest(int sockfd) {
    char buffer[BUFFER_SIZE];
    size_t totalBytesSent = 0;
    size_t totalBytesReceived = 0;
    time_t startTime, endTime;

    // Start the timer
    time(&startTime);
    while (1) {
        // Send data
        ssize_t bytesSent = send(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytesSent < 0) {
            error("Error sending data");
        }
        totalBytesSent += bytesSent;

        // Receive data
        ssize_t bytesReceived = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytesReceived < 0) {
            error("Error receiving data");
        }
        totalBytesReceived += bytesReceived;

        // Check elapsed time
        time(&endTime);
        if (difftime(endTime, startTime) >= TEST_DURATION) {
            break;
        }
    }

    double elapsedTime = difftime(endTime, startTime);
    
    // Calculate speeds
    double uploadSpeed = (totalBytesSent * 8) / (elapsedTime * 1000000); // Mbps
    double downloadSpeed = (totalBytesReceived * 8) / (elapsedTime * 1000000); // Mbps

    printf("Upload Speed: %.2f Mbps\n", uploadSpeed);
    printf("Download Speed: %.2f Mbps\n", downloadSpeed);
}

int main() {
    int sockfd;
    struct sockaddr_in serverAddr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    // Configure server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost for testing

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        error("Error connecting to server");
    }

    printf("Connected to the server. Starting speed test...\n");
    
    // Run speed test
    speedTest(sockfd);

    // Close the socket
    close(sockfd);
    
    return 0;
}