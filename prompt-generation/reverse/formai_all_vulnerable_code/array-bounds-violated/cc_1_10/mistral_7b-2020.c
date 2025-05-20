//MISTRAL-7B DATASET v1.0 Category: Building a HTTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *host = argv[1];
    int port = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) die("socket");

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, host, &server_addr.sin_addr);
    server_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        die("connect");

    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request), "GET / HTTP/1.1\r\n"
                                       "Host: %s\r\n"
                                       "User-Agent: Simple-HTTP-Client/1.0\r\n"
                                       "Accept: */*\r\n"
                                       "Connection: keep-alive\r\n\r\n", host);

    ssize_t sent = send(sockfd, request, strlen(request), 0);
    if (sent < 0) die("send");

    char response[BUFFER_SIZE];
    ssize_t received;
    while ((received = recv(sockfd, response, BUFFER_SIZE - 1, 0)) > 0) {
        response[received] = '\0';
        printf("%s", response);
        memset(response, 0, BUFFER_SIZE);
    }

    close(sockfd);
    return EXIT_SUCCESS;
}