//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

#define SERVER "example.com"
#define PORT 80
#define REQUEST "GET / HTTP/1.1\r\nUser-Agent: Mozilla/5.0\r\n\r\n"
#define BUFFER_SIZE 4096

int main() {
    int sockfd, flags, bytes_received, total_bytes = 0;
    struct sockaddr_in server_addr;
    char request[BUFFER_SIZE], response[BUFFER_SIZE], buffer[BUFFER_SIZE];
    double speed;
    clock_t start;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket error");
        exit(1);
    }

    // Set socket as non-blocking
    flags = fcntl(sockfd, F_GETFL, 0);
    fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);

    // Initialize server address details
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER);
    server_addr.sin_port = htons(PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection error");
        exit(1);
    }

    // Construct HTTP request and send to server
    sprintf(request, REQUEST);
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("Send error");
        exit(1);
    }

    // Start timer
    start = clock();

    while (1) {
        // Attempt to receive response from server
        bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);

        // Handle error or no data received
        if (bytes_received < 0) {
            perror("Receive error");
            exit(1);
        } else if (bytes_received == 0) {
            break;
        }

        // Add received bytes to total and clear buffer
        total_bytes += bytes_received;
        memset(buffer, 0, BUFFER_SIZE);
    }

    // Calculate speed and print result
    speed = (double) total_bytes / ((double)(clock() - start) / CLOCKS_PER_SEC) / 1000;
    printf("Your internet speed is: %.2f kB/s\n", speed);

    // Close socket
    close(sockfd);

    return 0;
}