//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main() {
    int sockfd;
    struct addrinfo *server_info;
    struct addrinfo hints = {
       .ai_family = AF_INET,
       .ai_socktype = SOCK_STREAM
    };
    char *host = "localhost";
    char *service = "8080";

    if (getaddrinfo(host, service, &hints, &server_info)!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(errno));
        exit(1);
    }

    sockfd = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);

    if (sockfd == -1) {
        fprintf(stderr, "socket: %s\n", strerror(errno));
        exit(1);
    }

    if (connect(sockfd, server_info->ai_addr, server_info->ai_addrlen)!= 0) {
        fprintf(stderr, "connect: %s\n", strerror(errno));
        exit(1);
    }

    freeaddrinfo(server_info);

    char buffer[1024];
    while (1) {
        memset(buffer, 0, 1024);
        ssize_t bytes_read = read(sockfd, buffer, 1024);
        if (bytes_read == 0) {
            fprintf(stderr, "Connection closed by server\n");
            break;
        }
        if (bytes_read == -1) {
            fprintf(stderr, "read: %s\n", strerror(errno));
            exit(1);
        }

        printf("Received from server: %s", buffer);
    }

    close(sockfd);
    return 0;
}