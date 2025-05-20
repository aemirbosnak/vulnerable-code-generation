//MISTRAL-7B DATASET v1.0 Category: Building a HTTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SERVER_PORT 80
#define BUFFER_SIZE 4096

typedef struct {
    int socket_desc;
    struct sockaddr_in server;
} client;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    client c = {0};

    if ((c.socket_desc = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation error");
        return 1;
    }

    memset(&c.server, 0, sizeof(c.server));
    c.server.sin_family = AF_INET;
    c.server.sin_port = htons(atoi(argv[2]));

    inet_pton(AF_INET, argv[1], &c.server.sin_addr);

    if (connect(c.socket_desc, (struct sockaddr *)&c.server, sizeof(c.server)) < 0) {
        perror("connection failed");
        return 1;
    }

    char request[BUFFER_SIZE];
    snprintf(request, BUFFER_SIZE, "GET %s HTTP/1.1\r\nHost: %s:%s\r\nUser-Agent: Simple-HTTP-Client/1.0\r\nAccept: */*\r\nConnection: keep-alive\r\n\r\n", argv[1], argv[1], argv[2]);

    send(c.socket_desc, request, strlen(request), 0);

    char response[BUFFER_SIZE];
    ssize_t bytes_received = recv(c.socket_desc, response, BUFFER_SIZE - 1, 0);
    response[bytes_received] = '\0';

    if (bytes_received > 0) {
        printf("Response from server:\n%s\n", response);
    } else {
        perror("Error receiving response from server");
    }

    close(c.socket_desc);

    return 0;
}