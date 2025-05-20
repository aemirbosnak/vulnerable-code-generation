//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: high level of detail
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[])
{
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <hostname> <port> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *hostname = argv[1];
    uint16_t port = atoi(argv[2]);
    char *username = argv[3];
    char *password = argv[4];

    struct addrinfo hints = {
        .ai_family = AF_UNSPEC,
        .ai_socktype = SOCK_STREAM,
        .ai_protocol = IPPROTO_TCP,
    };

    struct addrinfo *result;
    if (getaddrinfo(hostname, argv[2], &hints, &result) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(errno));
        return EXIT_FAILURE;
    }

    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        freeaddrinfo(result);
        return EXIT_FAILURE;
    }

    if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
        perror("connect");
        freeaddrinfo(result);
        close(sockfd);
        return EXIT_FAILURE;
    }

    freeaddrinfo(result);

    char buffer[MAX_LINE_LENGTH];

    // Send the LOGIN command
    snprintf(buffer, sizeof(buffer), "LOGIN %s %s\r\n", username, password);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Receive the LOGIN response
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Check the LOGIN response
    if (strncmp(buffer, "+OK LOGIN successful", strlen("+OK LOGIN successful")) != 0) {
        fprintf(stderr, "LOGIN failed: %s\n", buffer);
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Send the LIST command
    snprintf(buffer, sizeof(buffer), "LIST \"\"\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Receive the LIST response
    memset(buffer, 0, sizeof(buffer));
    int bytes_received = 0;
    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        printf("%s", buffer);
        memset(buffer, 0, sizeof(buffer));
    }

    if (bytes_received == -1) {
        perror("recv");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Send the QUIT command
    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Receive the QUIT response
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Check the QUIT response
    if (strncmp(buffer, "+OK LOGOUT successful", strlen("+OK LOGOUT successful")) != 0) {
        fprintf(stderr, "LOGOUT failed: %s\n", buffer);
        close(sockfd);
        return EXIT_FAILURE;
    }

    close(sockfd);

    return EXIT_SUCCESS;
}