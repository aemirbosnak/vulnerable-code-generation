//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <time.h>

#define SERVER_IP "1.1.1.1" // Cloudflare DNS as a test server
#define SERVER_PORT 80 // HTTP port
#define BUFFER_SIZE 1024

void displaySpeed(double downloadSpeed, double uploadSpeed) {
    printf("===========================================\n");
    printf("              Speed Test Results           \n");
    printf("===========================================\n");
    printf("Download Speed: %.2f Mbps\n", downloadSpeed);
    printf("Upload Speed: %.2f Mbps\n", uploadSpeed);
    printf("===========================================\n");
}

double calculateSpeed(int bytesTransferred, double timeTaken) {
    return (bytesTransferred * 8.0) / (timeTaken * 1000000); // Convert to Mbps
}

void downloadTest() {
    int sockfd;
    struct sockaddr_in serverAddr;
    char buffer[BUFFER_SIZE];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &serverAddr.sin_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Connection to the server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Send a GET request
    char *request = "GET / HTTP/1.1\r\nHost: 1.1.1.1\r\nConnection: close\r\n\r\n";
    send(sockfd, request, strlen(request), 0);

    // Start measuring time
    clock_t startTime = clock();

    int bytesRead;
    int totalBytesRead = 0;
    while ((bytesRead = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        totalBytesRead += bytesRead;
    }

    // Measure end time
    clock_t endTime = clock();

    // Close the socket
    close(sockfd);

    double timeTaken = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    double downloadSpeed = calculateSpeed(totalBytesRead, timeTaken);
    
    printf("Finished Download Test.\n");
    displaySpeed(downloadSpeed, 0);
}

void uploadTest() {
    int sockfd;
    struct sockaddr_in serverAddr;
    char buffer[BUFFER_SIZE];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &serverAddr.sin_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Connection to the server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Create a sample payload for upload
    for (int i = 0; i < BUFFER_SIZE - 1; i++) {
        buffer[i] = 'A'; // Fill buffer with 'A's
    }
    buffer[BUFFER_SIZE - 1] = '\0'; // Null terminate the string

    // Start measuring time
    clock_t startTime = clock();
    
    int bytesSent;
    double uploadSpeed = 0;
    for (int i = 0; i < 20; i++) { // Upload in chunks
        bytesSent = send(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytesSent < 0) {
            perror("Upload failed");
            break;
        }
    }

    // Measure end time
    clock_t endTime = clock();

    // Close the socket
    close(sockfd);

    double timeTaken = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    uploadSpeed = calculateSpeed(20 * BUFFER_SIZE, timeTaken); // Total bytes uploaded

    printf("Finished Upload Test.\n");
    displaySpeed(0, uploadSpeed);
}

int main() {
    printf("\n=============================\n");
    printf("        Speed Test App       \n");
    printf("=============================\n");
    
    // Run download test
    downloadTest();

    // Brief pause for user experience
    printf("Please wait...\n");
    sleep(3);

    // Run upload test
    uploadTest();
    
    return 0;
}