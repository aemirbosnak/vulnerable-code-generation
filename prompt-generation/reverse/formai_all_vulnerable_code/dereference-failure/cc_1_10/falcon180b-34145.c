//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUF_SIZE 1024
#define PORT "80"
#define IP_ADDRESS "192.168.1.1"

int main() {
    int sockfd;
    struct addrinfo hints, *res;
    char buffer[BUF_SIZE];
    int bytes_received;
    int status;

    // Initialize hints structure
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    // Get address information
    status = getaddrinfo(IP_ADDRESS, PORT, &hints, &res);
    if (status!= 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(1);
    }

    // Create socket
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        fprintf(stderr, "socket error: %s\n", strerror(errno));
        exit(1);
    }

    // Connect to server
    status = connect(sockfd, res->ai_addr, res->ai_addrlen);
    if (status == -1) {
        fprintf(stderr, "connect error: %s\n", strerror(errno));
        exit(1);
    }

    // Send request
    char request[100] = "GET / HTTP/1.1\r\nHost: ";
    strcat(request, IP_ADDRESS);
    strcat(request, "\r\nConnection: close\r\n\r\n");
    if (send(sockfd, request, strlen(request), 0) == -1) {
        fprintf(stderr, "send error: %s\n", strerror(errno));
        exit(1);
    }

    // Receive response
    bytes_received = recv(sockfd, buffer, BUF_SIZE, 0);
    buffer[bytes_received] = '\0';
    printf("Received %d bytes:\n%s\n", bytes_received, buffer);

    // Close socket
    close(sockfd);

    return 0;
}