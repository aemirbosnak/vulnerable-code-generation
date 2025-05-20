//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_ADDRESS "www.example.com"
#define SERVER_PORT 80
#define REQUEST_SIZE 1024
#define BUFFER_SIZE 1024

int main() {
    // Create a socket for communication with the server.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket()");
        return EXIT_FAILURE;
    }

    // Specify the server's address and port.
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);

    // Connect to the server.
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect()");
        return EXIT_FAILURE;
    }

    // Send a request to the server.
    char request[REQUEST_SIZE];
    memset(request, 0, REQUEST_SIZE);
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", SERVER_ADDRESS);
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send()");
        return EXIT_FAILURE;
    }

    // Receive the server's response.
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("recv()");
        return EXIT_FAILURE;
    }

    // Calculate the time taken to receive the response.
    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);
    gettimeofday(&end_time, NULL);
    long int milliseconds = (end_time.tv_sec - start_time.tv_sec) * 1000 + (end_time.tv_usec - start_time.tv_usec) / 1000;

    // Calculate the download speed.
    double download_speed = (double) bytes_received / milliseconds * 1000;

    // Print the download speed.
    printf("Download speed: %.2f kbps\n", download_speed);

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}