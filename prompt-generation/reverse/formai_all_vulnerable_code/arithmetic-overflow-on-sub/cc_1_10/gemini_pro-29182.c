//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define BUF_SIZE 1024

int main() {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char recvline[BUF_SIZE];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80);
    if (inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send a request to the server
    char request[] = "GET / HTTP/1.1\nHost: 127.0.0.1\n\n";
    n = send(sockfd, request, strlen(request), 0);
    if (n < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the response from the server
    n = recv(sockfd, recvline, BUF_SIZE, 0);
    if (n < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Measure the time it took to receive the response
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    while (n > 0) {
        n = recv(sockfd, recvline, BUF_SIZE, 0);
        if (n < 0) {
            perror("recv");
            exit(EXIT_FAILURE);
        }
    }
    clock_gettime(CLOCK_MONOTONIC, &end);

    // Calculate the download speed
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    double bytes_received = strlen(recvline);
    double speed = bytes_received / elapsed;

    // Print the download speed
    printf("Download speed: %.2f kB/s\n", speed / 1000);

    // Close the socket
    close(sockfd);

    return 0;
}