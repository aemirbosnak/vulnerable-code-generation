//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFF_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_ADDR "127.0.0.1"

int main(int argc, char *argv[]) {
    int client_socket, server_socket;
    struct sockaddr_in client_addr, server_addr;
    socklen_t client_len, server_len;
    char buffer[BUFF_SIZE];

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
        exit(1);
    }

    while (1) {
        client_len = sizeof(client_addr);
        if (accept(client_socket, (struct sockaddr *)&client_addr, &client_len) == -1) {
            fprintf(stderr, "Error accepting connection: %s\n", strerror(errno));
            exit(1);
        }

        char *request = "GET / HTTP/1.1\r\nHost: 127.0.0.1\r\nConnection: close\r\n\r\n";
        if (send(server_socket, request, strlen(request), 0) == -1) {
            fprintf(stderr, "Error sending request: %s\n", strerror(errno));
            exit(1);
        }

        memset(buffer, 0, BUFF_SIZE);
        while (recv(server_socket, buffer, BUFF_SIZE, 0) > 0) {
            send(client_socket, buffer, strlen(buffer), 0);
        }

        close(client_socket);
    }

    close(server_socket);
    return 0;
}