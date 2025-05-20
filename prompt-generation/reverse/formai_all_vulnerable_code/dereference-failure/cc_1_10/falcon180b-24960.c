//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    struct addrinfo hints;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    struct addrinfo *result = NULL;
    int gai_error = getaddrinfo(argv[1], NULL, &hints, &result);

    if (gai_error!= 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(gai_error));
        exit(1);
    }

    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

    if (sockfd == -1) {
        fprintf(stderr, "socket error: %s\n", strerror(errno));
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    int bytes_received;

    if (connect(sockfd, result->ai_addr, result->ai_addrlen)!= 0) {
        fprintf(stderr, "connect error: %s\n", strerror(errno));
        exit(1);
    }

    fprintf(stdout, "Connected to %s\n", argv[1]);

    while (1) {
        fprintf(stdout, "Enter message to send (or type 'quit' to exit): ");
        fgets(buffer, BUFFER_SIZE, stdin);
        if (strcmp(buffer, "quit") == 0) {
            break;
        }

        bytes_received = send(sockfd, buffer, strlen(buffer), 0);

        if (bytes_received == -1) {
            fprintf(stderr, "send error: %s\n", strerror(errno));
            exit(1);
        }

        memset(buffer, 0, BUFFER_SIZE);
        bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (bytes_received == 0) {
            fprintf(stdout, "Server disconnected\n");
            break;
        } else if (bytes_received == -1) {
            fprintf(stderr, "recv error: %s\n", strerror(errno));
            exit(1);
        }

        fprintf(stdout, "Received message: %s\n", buffer);
    }

    close(sockfd);
    freeaddrinfo(result);
    return 0;
}