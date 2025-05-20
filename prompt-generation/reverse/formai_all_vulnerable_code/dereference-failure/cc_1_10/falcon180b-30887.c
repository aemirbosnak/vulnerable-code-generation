//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 4096

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUF_SIZE];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <port> <host>\n", argv[0]);
        return 1;
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        error("socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    inet_pton(AF_INET, argv[2], &server_addr.sin_addr);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error("bind");
    }

    if (listen(listen_socket, 5) == -1) {
        error("listen");
    }

    printf("Proxy listening on port %s\n", argv[1]);

    while (1) {
        socklen_t addr_size;
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &addr_size);
        if (client_socket == -1) {
            error("accept");
        }

        printf("Client connected\n");

        while (1) {
            memset(buffer, 0, BUF_SIZE);
            ssize_t bytes_received = recv(client_socket, buffer, BUF_SIZE, 0);
            if (bytes_received <= 0) {
                break;
            }

            ssize_t bytes_sent = send(client_socket, buffer, bytes_received, 0);
            if (bytes_sent <= 0) {
                break;
            }
        }

        close(client_socket);
    }

    close(listen_socket);
    return 0;
}