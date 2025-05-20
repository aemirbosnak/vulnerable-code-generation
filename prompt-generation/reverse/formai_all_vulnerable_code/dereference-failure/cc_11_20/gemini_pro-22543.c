//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: decentralized
#define _GNU_SOURCE

#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <poll.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_LINE_LEN 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse command line arguments.
    const char *host = argv[1];
    const char *port = argv[2];

    // Get the IP address of the host.
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_CANONNAME;

    struct addrinfo *result;
    int err = getaddrinfo(host, port, &hints, &result);
    if (err != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(err));
        return EXIT_FAILURE;
    }

    // Create a socket.
    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the POP3 server.
    err = connect(sockfd, result->ai_addr, result->ai_addrlen);
    if (err == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the USER command.
    char buf[MAX_LINE_LEN];
    snprintf(buf, sizeof(buf), "USER %s\r\n", "username");
    err = send(sockfd, buf, strlen(buf), 0);
    if (err == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response.
    err = recv(sockfd, buf, sizeof(buf), 0);
    if (err == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    printf("%s", buf);

    // Send the PASS command.
    snprintf(buf, sizeof(buf), "PASS %s\r\n", "password");
    err = send(sockfd, buf, strlen(buf), 0);
    if (err == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response.
    err = recv(sockfd, buf, sizeof(buf), 0);
    if (err == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    printf("%s", buf);

    // Send the STAT command.
    snprintf(buf, sizeof(buf), "STAT\r\n");
    err = send(sockfd, buf, strlen(buf), 0);
    if (err == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response.
    err = recv(sockfd, buf, sizeof(buf), 0);
    if (err == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    printf("%s", buf);

    // Send the LIST command.
    snprintf(buf, sizeof(buf), "LIST\r\n");
    err = send(sockfd, buf, strlen(buf), 0);
    if (err == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response.
    while (1) {
        err = recv(sockfd, buf, sizeof(buf), 0);
        if (err == -1) {
            perror("recv");
            return EXIT_FAILURE;
        }

        if (err == 0) {
            break;
        }

        printf("%s", buf);
    }

    // Send the QUIT command.
    snprintf(buf, sizeof(buf), "QUIT\r\n");
    err = send(sockfd, buf, strlen(buf), 0);
    if (err == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}