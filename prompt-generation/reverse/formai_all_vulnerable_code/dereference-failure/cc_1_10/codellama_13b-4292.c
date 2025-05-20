//Code Llama-13B DATASET v1.0 Category: Email Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    struct addrinfo hints;
    struct addrinfo *server_info;
    int sockfd;
    int bytes_sent;
    int bytes_received;
    char buffer[BUFSIZE];

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if (getaddrinfo(argv[1], argv[2], &hints, &server_info) != 0) {
        fprintf(stderr, "getaddrinfo() failed\n");
        return 1;
    }

    sockfd = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);
    if (sockfd < 0) {
        fprintf(stderr, "socket() failed\n");
        return 1;
    }

    if (connect(sockfd, server_info->ai_addr, server_info->ai_addrlen) != 0) {
        fprintf(stderr, "connect() failed\n");
        return 1;
    }

    freeaddrinfo(server_info);

    while (fgets(buffer, BUFSIZE, stdin) != NULL) {
        bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
        if (bytes_sent < 0) {
            fprintf(stderr, "send() failed\n");
            return 1;
        }

        bytes_received = recv(sockfd, buffer, BUFSIZE, 0);
        if (bytes_received < 0) {
            fprintf(stderr, "recv() failed\n");
            return 1;
        }

        printf("Received: %s\n", buffer);
    }

    close(sockfd);

    return 0;
}