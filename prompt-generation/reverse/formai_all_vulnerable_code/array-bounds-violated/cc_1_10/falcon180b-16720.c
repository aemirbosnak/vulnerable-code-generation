//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 8192
#define PROXY_PORT 8080
#define HTTP_REQUEST "GET / HTTP/1.1\r\nHost:\r\nConnection: close\r\n\r\n"

int main(int argc, char *argv[]) {
    int proxy_socket, client_socket, bytes_received, bytes_sent;
    struct sockaddr_in proxy_addr, client_addr;
    char buffer[BUFFER_SIZE];

    proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket == -1) {
        perror("socket");
        exit(1);
    }

    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_port = htons(PROXY_PORT);
    proxy_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(proxy_socket, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(proxy_socket, 5) == -1) {
        perror("listen");
        exit(1);
    }

    while (1) {
        client_socket = accept(proxy_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            close(client_socket);
            continue;
        }

        buffer[bytes_received] = '\0';
        if (strncmp(buffer, "GET", 3) == 0) {
            send(client_socket, HTTP_REQUEST, strlen(HTTP_REQUEST), 0);
        } else {
            send(client_socket, buffer, bytes_received, 0);
        }

        close(client_socket);
    }

    return 0;
}