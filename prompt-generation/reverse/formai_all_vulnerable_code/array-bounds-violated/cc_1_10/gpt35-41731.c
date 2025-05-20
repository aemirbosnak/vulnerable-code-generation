//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <sys/time.h>

#define MAX_BUFFER_SIZE 1024

// This function takes a socket and returns the amount of time it takes to receive a response
double check_response_time(int sockfd) {
    char buffer[MAX_BUFFER_SIZE];
    struct timeval start, stop;
    int nread;

    // Send the request to the server
    if (send(sockfd, "GET / HTTP/1.0\r\n\r\n", strlen("GET / HTTP/1.0\r\n\r\n"), 0) == -1) {
        perror("send");
        return -1;
    }

    // Get the start time for measuring response time
    gettimeofday(&start, NULL);

    // Receive the response from the server
    while ((nread = recv(sockfd, buffer, MAX_BUFFER_SIZE - 1, 0)) > 0) {
        buffer[nread] = '\0';
    }

    // Get the stop time for measuring response time
    gettimeofday(&stop, NULL);

    // Calculate the time it takes to receive the response
    double response_time = (double)(stop.tv_sec - start.tv_sec) * 1000.0 + (double)(stop.tv_usec - start.tv_usec) / 1000.0;
    return response_time;
}

int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 2) {
        printf("Usage: %s <address>\n", argv[0]);
        exit(1);
    }

    // Create a new socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Set the address of the server to connect to
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Set the TCP_NODELAY option
    int optval = 1;
    socklen_t optlen = sizeof(optval);
    if (setsockopt(sockfd, IPPROTO_TCP, TCP_NODELAY, &optval, optlen) == -1) {
        perror("setsockopt TCP_NODELAY");
    }

    // Set the SO_RCVBUF option
    optval = 1024 * 1024;
    optlen = sizeof(optval);
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &optval, optlen) == -1) {
        perror("setsockopt SO_RCVBUF");
    }

    // Measure the response time
    double response_time = check_response_time(sockfd);
    printf("Response time: %.2fms\n", response_time);

    // Close the socket
    close(sockfd);

    return 0;
}