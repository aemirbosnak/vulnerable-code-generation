//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>

#define SERVER_IP "www.google.com"
#define SERVER_PORT 80
#define REQUEST "HEAD / HTTP/1.1\r\nHost: " SERVER_IP "\r\n\r\n"

int main() {
    // Initialize variables
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buffer[1024];
    float download_speed;
    clock_t start, end;
    double time_taken;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERVER_PORT);
    servaddr.sin_addr.s_addr = inet_addr(SERVER_IP);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send the HTTP request
    n = write(sockfd, REQUEST, strlen(REQUEST));
    if (n < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Start the timer
    start = clock();

    // Receive the response from the server
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    // Stop the timer
    end = clock();

    // Calculate the time taken
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Calculate the download speed
    download_speed = ((float)n / 1024) / time_taken;

    // Print the download speed
    printf("Download speed: %f KB/s\n", download_speed);

    // Close the socket
    close(sockfd);

    return 0;
}