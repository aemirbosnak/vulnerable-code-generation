//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>

#define BUF_SIZE 1024
#define MAX_CLIENTS 10
#define PROXY_PORT 8080
#define PROXY_HOST "127.0.0.1"

int main() {
    int proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket == -1) {
        fprintf(stderr, "Error creating proxy socket: %s\n", strerror(errno));
        exit(1);
    }

    struct sockaddr_in proxy_addr;
    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_port = htons(PROXY_PORT);
    proxy_addr.sin_addr.s_addr = inet_addr(PROXY_HOST);

    if (bind(proxy_socket, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) == -1) {
        fprintf(stderr, "Error binding proxy socket: %s\n", strerror(errno));
        exit(1);
    }

    if (listen(proxy_socket, MAX_CLIENTS) == -1) {
        fprintf(stderr, "Error listening on proxy socket: %s\n", strerror(errno));
        exit(1);
    }

    fprintf(stdout, "Proxy server started on port %d\n", PROXY_PORT);

    while (1) {
        int client_socket = accept(proxy_socket, NULL, NULL);
        if (client_socket == -1) {
            fprintf(stderr, "Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        fprintf(stdout, "Client connected on socket %d\n", client_socket);

        pid_t pid = fork();
        if (pid == -1) {
            fprintf(stderr, "Error forking: %s\n", strerror(errno));
            close(client_socket);
            continue;
        }

        if (pid == 0) {
            close(proxy_socket);

            char buf[BUF_SIZE];
            int bytes_received, bytes_sent;

            while ((bytes_received = recv(client_socket, buf, BUF_SIZE, 0)) > 0) {
                send(client_socket, buf, bytes_received, 0);
            }

            close(client_socket);
            exit(0);
        }

        close(client_socket);
    }

    return 0;
}