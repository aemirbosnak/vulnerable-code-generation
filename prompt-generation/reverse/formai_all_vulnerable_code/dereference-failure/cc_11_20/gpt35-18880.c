//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s <host> <port> <proxy_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *host = argv[1];
    char *port = argv[2];
    char *proxy_port = argv[3];

    int status;
    struct addrinfo hints;
    struct addrinfo *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    if ((status = getaddrinfo(host, port, &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }

    int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0) {
        perror("socket error");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) < 0) {
        perror("connect error");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(res);

    int proxy_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_sockfd < 0) {
        perror("proxy socket error");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in proxy_addr;
    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    proxy_addr.sin_port = htons(atoi(proxy_port));
    if (bind(proxy_sockfd, (const struct sockaddr *) &proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("bind error");
        exit(EXIT_FAILURE);
    }

    if (listen(proxy_sockfd, 1) < 0) {
        perror("listen error");
        exit(EXIT_FAILURE);
    }

    printf("Proxy listening on port %s...\n", proxy_port);

    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_sockfd = accept(proxy_sockfd, (struct sockaddr *) &client_addr, &client_addr_len);
    if (client_sockfd < 0) {
        perror("accept error");
        exit(EXIT_FAILURE);
    }

    printf("Got connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;
    while ((bytes_read = read(client_sockfd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(sockfd, buffer, bytes_read);
        if (bytes_written < 0) {
            perror("write error");
            exit(EXIT_FAILURE);
        }

        bytes_read = read(sockfd, buffer, BUFFER_SIZE);
        if (bytes_read < 0) {
            perror("read error");
            exit(EXIT_FAILURE);
        }

        bytes_written = write(client_sockfd, buffer, bytes_read);
        if (bytes_written < 0) {
            perror("write error");
            exit(EXIT_FAILURE);
        }
    }

    close(sockfd);
    close(proxy_sockfd);
    close(client_sockfd);

    return 0;
}