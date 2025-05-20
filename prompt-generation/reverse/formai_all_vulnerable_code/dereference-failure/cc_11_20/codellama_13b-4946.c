//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: calm
/*
 * Unique C Network Ping Test Program
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PING_SIZE 64
#define PING_DELAY 1
#define PING_TIMEOUT 2

int main(int argc, char **argv) {
    char *host, *port;
    struct addrinfo hints, *servinfo, *p;
    struct sockaddr_storage their_addr;
    socklen_t sin_size;
    int sockfd, numbytes;
    char buffer[PING_SIZE];
    struct timeval timeout;
    fd_set readfds;
    int i, error;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s host port\n", argv[0]);
        return 1;
    }

    host = argv[1];
    port = argv[2];

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if ((error = getaddrinfo(host, port, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(error));
        return 1;
    }

    for (p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Failed to connect to %s\n", host);
        return 1;
    }

    freeaddrinfo(servinfo);

    printf("Connected to %s\n", host);

    while (1) {
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);

        timeout.tv_sec = PING_DELAY;
        timeout.tv_usec = 0;

        if (select(sockfd + 1, &readfds, NULL, NULL, &timeout) == -1) {
            perror("select");
            break;
        }

        if (FD_ISSET(sockfd, &readfds)) {
            if ((numbytes = recv(sockfd, buffer, PING_SIZE, 0)) == -1) {
                perror("recv");
                break;
            }

            printf("Received %d bytes\n", numbytes);
        }
    }

    close(sockfd);

    return 0;
}