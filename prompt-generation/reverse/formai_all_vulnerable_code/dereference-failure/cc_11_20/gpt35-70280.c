//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LINE_LEN 256
#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *server_address = argv[1];
    const char *port = argv[2];

    struct addrinfo hints, *servinfo;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    int status = getaddrinfo(server_address, port, &hints, &servinfo);
    if (status != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }

    int sock_fd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    if (sock_fd == -1) {
        perror("socket error");
        exit(EXIT_FAILURE);
    }

    status = connect(sock_fd, servinfo->ai_addr, servinfo->ai_addrlen);
    if (status == -1) {
        perror("connect error");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(servinfo);

    char buffer[MAX_BUFFER_SIZE];

    status = recv(sock_fd, buffer, sizeof(buffer), 0);
    if (status == -1) {
        perror("recv error");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    status = send(sock_fd, "1 login username password\r\n", strlen("1 login username password\r\n"), 0);
    if (status == -1) {
        perror("send error");
        exit(EXIT_FAILURE);
    }

    status = recv(sock_fd, buffer, sizeof(buffer), 0);
    if (status == -1) {
        perror("recv error");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    status = send(sock_fd, "2 select inbox\r\n", strlen("2 select inbox\r\n"), 0);
    if (status == -1) {
        perror("send error");
        exit(EXIT_FAILURE);
    }

    status = recv(sock_fd, buffer, sizeof(buffer), 0);
    if (status == -1) {
        perror("recv error");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    status = send(sock_fd, "3 fetch 1:* (body[header.fields (from to subject date)])\r\n", strlen("3 fetch 1:* (body[header.fields (from to subject date)])\r\n"), 0);
    if (status == -1) {
        perror("send error");
        exit(EXIT_FAILURE);
    }

    status = recv(sock_fd, buffer, sizeof(buffer), 0);
    if (status == -1) {
        perror("recv error");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    status = send(sock_fd, "4 logout\r\n", strlen("4 logout\r\n"), 0);
    if (status == -1) {
        perror("send error");
        exit(EXIT_FAILURE);
    }

    status = recv(sock_fd, buffer, sizeof(buffer), 0);
    if (status == -1) {
        perror("recv error");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    status = close(sock_fd);
    if (status == -1) {
        perror("close error");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}