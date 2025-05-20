//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: future-proof
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/socket.h>

#define BUFFER_SIZE 4096

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <hostname> <port> <message>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Resolve the hostname
    struct hostent *hostent = gethostbyname(argv[1]);
    if (hostent == NULL) {
        fprintf(stderr, "Could not resolve hostname %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Create a TCP socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the TCP keepalive option
    int keepalive = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, &keepalive, sizeof(keepalive)) == -1) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Connect to the SMTP server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr = *(struct in_addr *)hostent->h_addr;

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Read the greeting from the SMTP server
    char buffer[BUFFER_SIZE];
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    // Send the HELO command
    snprintf(buffer, BUFFER_SIZE, "HELO %s\r\n", hostent->h_name);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Read the response from the SMTP server
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    // Send the MAIL FROM command
    snprintf(buffer, BUFFER_SIZE, "MAIL FROM: <%s>\r\n", getenv("USER"));
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Read the response from the SMTP server
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    // Send the RCPT TO command
    snprintf(buffer, BUFFER_SIZE, "RCPT TO: <%s>\r\n", argv[3]);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Read the response from the SMTP server
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    // Send the DATA command
    snprintf(buffer, BUFFER_SIZE, "DATA\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Read the response from the SMTP server
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    // Send the message
    if (send(sockfd, argv[4], strlen(argv[4]), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Send the CRLF to indicate the end of the message
    if (send(sockfd, "\r\n", 2, 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Read the response from the SMTP server
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    // Send the QUIT command
    snprintf(buffer, BUFFER_SIZE, "QUIT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}