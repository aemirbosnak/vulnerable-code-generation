//Code Llama-13B DATASET v1.0 Category: Building a HTTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define HTTP_PORT 80
#define BUFSIZE 1024

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }

    char *url = argv[1];
    char *host = strtok(url, ":");
    char *port = strtok(NULL, ":");
    char *path = strtok(NULL, " ");

    if (port == NULL) {
        port = "80";
    }

    struct addrinfo hints;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    struct addrinfo *result;
    if (getaddrinfo(host, port, &hints, &result) != 0) {
        perror("getaddrinfo");
        return 1;
    }

    int sock = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    if (connect(sock, result->ai_addr, result->ai_addrlen) == -1) {
        perror("connect");
        return 1;
    }

    freeaddrinfo(result);

    char request[BUFSIZE];
    snprintf(request, BUFSIZE, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);

    if (send(sock, request, strlen(request), 0) == -1) {
        perror("send");
        return 1;
    }

    char buf[BUFSIZE];
    int bytes_read = recv(sock, buf, BUFSIZE, 0);
    if (bytes_read == -1) {
        perror("recv");
        return 1;
    }

    printf("%s\n", buf);

    close(sock);

    return 0;
}