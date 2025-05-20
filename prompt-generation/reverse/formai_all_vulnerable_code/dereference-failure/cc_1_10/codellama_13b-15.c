//Code Llama-13B DATASET v1.0 Category: Building a FTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define PORT 21

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <ftp_server_address>\n", argv[0]);
        return 1;
    }

    struct addrinfo hints;
    struct addrinfo *server_info, *p;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    if (getaddrinfo(argv[1], PORT, &hints, &server_info) != 0) {
        printf("getaddrinfo() failed\n");
        return 1;
    }

    int sock = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);
    if (sock == -1) {
        printf("socket() failed\n");
        return 1;
    }

    if (connect(sock, server_info->ai_addr, server_info->ai_addrlen) == -1) {
        printf("connect() failed\n");
        return 1;
    }

    freeaddrinfo(server_info);

    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    if (recv(sock, buffer, sizeof(buffer), 0) == -1) {
        printf("recv() failed\n");
        return 1;
    }

    printf("Server response: %s\n", buffer);

    char command[1024];
    memset(command, 0, sizeof(command));

    printf("Enter FTP command: ");
    fgets(command, sizeof(command), stdin);

    if (send(sock, command, strlen(command), 0) == -1) {
        printf("send() failed\n");
        return 1;
    }

    memset(buffer, 0, sizeof(buffer));

    if (recv(sock, buffer, sizeof(buffer), 0) == -1) {
        printf("recv() failed\n");
        return 1;
    }

    printf("Server response: %s\n", buffer);

    close(sock);

    return 0;
}