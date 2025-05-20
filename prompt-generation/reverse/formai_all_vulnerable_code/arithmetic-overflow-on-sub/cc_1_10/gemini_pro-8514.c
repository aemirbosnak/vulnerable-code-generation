//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    // Check if we have the right number of arguments.
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server IP> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Parse the server IP and port.
    char *server_ip = argv[1];
    int port = atoi(argv[2]);

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Connect to the server.
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Get the current time.
    struct timeval start_time;
    gettimeofday(&start_time, NULL);

    // Send a request to the server.
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request), "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", server_ip);
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the response from the server.
    char response[BUFFER_SIZE];
    int bytes_received = 0;
    while ((bytes_received = recv(sockfd, response, sizeof(response), 0)) > 0) {
        // Do nothing.
    }
    if (bytes_received < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Get the current time.
    struct timeval end_time;
    gettimeofday(&end_time, NULL);

    // Calculate the time taken for the request and response.
    double time_taken = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;

    // Calculate the download speed.
    double download_speed = bytes_received / time_taken;

    // Print the download speed.
    printf("Download speed: %.2f KB/s\n", download_speed);

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}