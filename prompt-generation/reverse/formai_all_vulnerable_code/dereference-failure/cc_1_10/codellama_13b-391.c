//Code Llama-13B DATASET v1.0 Category: Simple HTTP Proxy ; Style: authentic
// Simple HTTP Proxy in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        return 1;
    }

    if (listen(sock, 1) < 0) {
        perror("listen");
        return 1;
    }

    printf("Listening on port %d\n", port);

    while (1) {
        struct sockaddr_in client;
        socklen_t client_len = sizeof(client);
        int client_sock = accept(sock, (struct sockaddr *)&client, &client_len);
        if (client_sock < 0) {
            perror("accept");
            return 1;
        }

        char *buffer = malloc(BUFSIZE);
        if (!buffer) {
            perror("malloc");
            return 1;
        }

        int n = recv(client_sock, buffer, BUFSIZE, 0);
        if (n < 0) {
            perror("recv");
            return 1;
        }

        printf("Received %d bytes from client\n", n);

        char *response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body>Hello, world!</body></html>";
        n = send(client_sock, response, strlen(response), 0);
        if (n < 0) {
            perror("send");
            return 1;
        }

        printf("Sent %d bytes to client\n", n);

        free(buffer);
        close(client_sock);
    }

    return 0;
}