//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo server_info, client_info;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;
    int opt = 1;

    if (argc!= 3) {
        printf("Usage: %s <port> <message>\n", argv[0]);
        return 1;
    }

    memset(&server_info, 0, sizeof(server_info));
    server_info.ai_family = AF_UNSPEC;
    server_info.ai_socktype = SOCK_STREAM;
    server_info.ai_protocol = IPPROTO_TCP;
    server_info.ai_flags = AI_PASSIVE;

    if (getaddrinfo(NULL, argv[1], &server_info, NULL)!= 0) {
        printf("Error: %s\n", gai_strerror(errno));
        return 1;
    }

    sockfd = socket(server_info.ai_family, server_info.ai_socktype, server_info.ai_protocol);
    if (sockfd == -1) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    if (bind(sockfd, server_info.ai_addr, server_info.ai_addrlen) == -1) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    if (listen(sockfd, 5) == -1) {
        printf("Error: %s\n", strerror(errno));
        return 1;
    }

    while (1) {
        memset(&client_info, 0, sizeof(client_info));
        client_info.ai_family = AF_UNSPEC;
        client_info.ai_socktype = SOCK_STREAM;
        client_info.ai_protocol = IPPROTO_TCP;

        if (getaddrinfo(NULL, NULL, &client_info, NULL)!= 0) {
            printf("Error: %s\n", gai_strerror(errno));
            return 1;
        }

        sockfd = accept(sockfd, client_info.ai_addr, &client_info.ai_addrlen);
        if (sockfd == -1) {
            printf("Error: %s\n", strerror(errno));
            continue;
        }

        bytes_received = send(sockfd, argv[2], strlen(argv[2]), 0);
        if (bytes_received == -1) {
            printf("Error: %s\n", strerror(errno));
            close(sockfd);
            continue;
        }

        close(sockfd);
    }

    return 0;
}