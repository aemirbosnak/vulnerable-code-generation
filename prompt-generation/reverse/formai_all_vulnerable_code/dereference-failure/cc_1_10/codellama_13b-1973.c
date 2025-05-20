//Code Llama-13B DATASET v1.0 Category: Simple HTTP Proxy ; Style: scientific
/*
 * Simple HTTP Proxy Example
 *
 * Usage: ./proxy [port]
 *
 * This program listens on a given port and acts as a simple HTTP proxy.
 * It receives HTTP requests, sends them to the destination server,
 * and returns the response to the client.
 *
 * Compile with: gcc -o proxy proxy.c -lpthread
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_REQUEST_SIZE 1024

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int listen_fd, connect_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char request[MAX_REQUEST_SIZE], response[MAX_REQUEST_SIZE];
    int request_len, response_len;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s [port]\n", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        error("socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error("bind");
    }

    if (listen(listen_fd, 1) == -1) {
        error("listen");
    }

    printf("Listening on port %s\n", argv[1]);

    while (1) {
        connect_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &client_len);
        if (connect_fd == -1) {
            error("accept");
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        request_len = read(connect_fd, request, MAX_REQUEST_SIZE);
        if (request_len == -1) {
            error("read");
        }

        if (send(connect_fd, request, request_len, 0) == -1) {
            error("send");
        }

        response_len = recv(connect_fd, response, MAX_REQUEST_SIZE, 0);
        if (response_len == -1) {
            error("recv");
        }

        if (send(connect_fd, response, response_len, 0) == -1) {
            error("send");
        }

        close(connect_fd);
    }

    close(listen_fd);
    return 0;
}