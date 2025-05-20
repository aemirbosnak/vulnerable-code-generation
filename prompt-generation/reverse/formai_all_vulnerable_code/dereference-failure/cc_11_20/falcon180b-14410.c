//Falcon-180B DATASET v1.0 Category: Networking ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    struct addrinfo hints, *servinfo, *p;
    char buffer[BUFFER_SIZE];
    int rv;
    int opt = 1;
    char *message = "Hello from client\n";

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <IP address> <Port number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(argv[1], argv[2], &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(EXIT_FAILURE);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
            perror("setsockopt");
            close(sockfd);
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("connect");
            close(sockfd);
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Failed to connect\n");
        exit(EXIT_FAILURE);
    }

    send(sockfd, message, strlen(message), 0);

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        rv = recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (rv == 0) {
            fprintf(stdout, "Connection closed by server\n");
            break;
        } else if (rv == -1) {
            perror("recv");
            exit(EXIT_FAILURE);
        }

        fprintf(stdout, "Received message: %s", buffer);
    }

    close(sockfd);
    exit(EXIT_SUCCESS);
}