//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT 21

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo server_info;
    struct addrinfo *server = NULL;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    memset(&server_info, 0, sizeof(server_info));
    server_info.ai_family = AF_UNSPEC;
    server_info.ai_socktype = SOCK_STREAM;
    server_info.ai_protocol = IPPROTO_TCP;

    if (argc!= 4) {
        printf("Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    server = getaddrinfo(argv[1], NULL, NULL, &server_info);
    if (server == NULL) {
        printf("Error resolving hostname\n");
        exit(2);
    }

    sockfd = socket(server->ai_family, server->ai_socktype, server->ai_protocol);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(3);
    }

    if (connect(sockfd, server->ai_addr, server->ai_addrlen) == -1) {
        printf("Error connecting to server\n");
        exit(4);
    }

    sprintf(buffer, "USER %s\r\n", argv[2]);
    send(sockfd, buffer, strlen(buffer), 0);

    sprintf(buffer, "PASS %s\r\n", argv[3]);
    send(sockfd, buffer, strlen(buffer), 0);

    bytes_read = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_read <= 0) {
        printf("Error reading response\n");
        exit(5);
    }

    printf("Response: %s", buffer);

    close(sockfd);
    freeaddrinfo(server);

    return 0;
}