//Code Llama-13B DATASET v1.0 Category: Building a HTTP Client ; Style: high level of detail
/*
 * HTTP Client Example
 *
 * This program demonstrates how to build a simple HTTP client in C using the POSIX socket API.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];

    if (argc < 3) {
        fprintf(stderr, "usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    // Initialize server address
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);

    // Convert hostname to IP address
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error resolving hostname\n");
        exit(1);
    }
    memcpy((char *) &serv_addr.sin_addr.s_addr, (char *) server->h_addr, server->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Send request to server
    n = write(sockfd, "GET / HTTP/1.0\r\n\r\n", 16);
    if (n < 0) {
        perror("Error sending request to server");
        exit(1);
    }

    // Receive response from server
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        perror("Error receiving response from server");
        exit(1);
    }

    // Print response
    printf("%s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}