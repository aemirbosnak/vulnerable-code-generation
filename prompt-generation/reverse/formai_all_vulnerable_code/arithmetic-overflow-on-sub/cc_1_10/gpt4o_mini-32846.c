//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define SERVER_IP "speed.hetzner.de" // Example speed test server
#define SERVER_PORT 80
#define BUFFER_SIZE 8192
#define TEST_DURATION 5

void handleError(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

double calculateDownloadSpeed(size_t bytesDownloaded, double timeTaken) {
    return (bytesDownloaded / timeTaken) * 8.0 / 1024.0; // Speed in Kbps
}

double timeElapsed(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
}

int main() {
    int sock;
    struct sockaddr_in serverAddress;
    char request[1024];
    char buffer[BUFFER_SIZE];
    size_t totalBytesDownloaded = 0;

    // Create socket
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        handleError("Socket creation failed");
    }

    // Define server address
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(SERVER_PORT);
    if(inet_pton(AF_INET, SERVER_IP, &serverAddress.sin_addr) <= 0) {
        handleError("Invalid address");
    }

    // Establish connection
    if(connect(sock, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0) {
        handleError("Connection Failed");
    }

    // Create HTTP GET request
    snprintf(request, sizeof(request), "GET /speedtest/random5000x5000.jpg HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", SERVER_IP);
    
    // Sending request to the server
    send(sock, request, strlen(request), 0);
    
    // Start timing for download speed calculation
    struct timespec startTime, endTime;
    clock_gettime(CLOCK_MONOTONIC, &startTime);

    // Reading response from the server
    while(1) {
        ssize_t bytesRead = recv(sock, buffer, BUFFER_SIZE, 0);
        if(bytesRead <= 0) break; // Connection closed or error
        
        totalBytesDownloaded += bytesRead;
    }

    // Get the end time
    clock_gettime(CLOCK_MONOTONIC, &endTime);

    // Calculate total elapsed time and download speed
    double elapsedTime = timeElapsed(startTime, endTime);
    double speedKbps = calculateDownloadSpeed(totalBytesDownloaded, elapsedTime);

    // Display the results
    printf("Total Bytes Downloaded: %zu bytes\n", totalBytesDownloaded);
    printf("Elapsed Time: %.2f seconds\n", elapsedTime);
    printf("Download Speed: %.2f Kbps\n", speedKbps);

    // Close the socket
    close(sock);
    return 0;
}