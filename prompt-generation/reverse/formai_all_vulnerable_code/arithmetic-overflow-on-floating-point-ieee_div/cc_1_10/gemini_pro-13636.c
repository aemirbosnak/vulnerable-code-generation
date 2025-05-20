//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define PORT 80
#define REQUEST "GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\r\n"

int main() {
    struct sockaddr_in server_addr;
    int sockfd, bytes_received;
    char buffer[1024];
    clock_t start, end;
    double elapsed_time;
    int total_bytes = 0;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("8.8.8.8");

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send the request
    if (send(sockfd, REQUEST, strlen(REQUEST), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Start the timer
    start = clock();

    // Receive the response
    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        total_bytes += bytes_received;
    }

    // Stop the timer
    end = clock();

    // Calculate the elapsed time
    elapsed_time = (double) (end - start) / CLOCKS_PER_SEC;

    // Print the results
    printf("Elapsed time: %f seconds\n", elapsed_time);
    printf("Total bytes received: %d\n", total_bytes);
    printf("Speed: %f bytes per second\n", (double) total_bytes / elapsed_time);

    // Close the socket
    close(sockfd);

    return 0;
}