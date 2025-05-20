//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    int sockfd;
    struct addrinfo *server_info;
    struct addrinfo hints;
    char *node = argv[1];
    char *port = argv[2];
    int rv;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    rv = getaddrinfo(node, port, &hints, &server_info);
    if (rv!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(EXIT_FAILURE);
    }

    sockfd = socket(server_info->ai_family, server_info->ai_socktype,
        server_info->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, server_info->ai_addr, server_info->ai_addrlen) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    printf("FTP client connected to %s:%s\n", node, port);

    char send_buffer[1024];
    char recv_buffer[1024];

    while (1) {
        printf("Enter command: ");
        fgets(send_buffer, sizeof(send_buffer), stdin);

        send(sockfd, send_buffer, strlen(send_buffer), 0);

        memset(recv_buffer, 0, sizeof(recv_buffer));
        int bytes_received = recv(sockfd, recv_buffer, sizeof(recv_buffer), 0);

        printf("Received: %s\n", recv_buffer);
    }

    close(sockfd);
    freeaddrinfo(server_info);
    return 0;
}