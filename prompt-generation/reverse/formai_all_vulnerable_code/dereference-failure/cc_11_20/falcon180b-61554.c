//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_LINE 1024
#define BACKLOG 5

int main(int argc, char **argv) {
    int listen_sock, conn_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_LINE];
    int addrlen;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <port> <host>\n", argv[0]);
        exit(1);
    }

    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock == -1) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    inet_pton(AF_INET, argv[2], &server_addr.sin_addr);

    if (bind(listen_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(listen_sock, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Proxy server started on port %s\n", argv[1]);

    while (1) {
        addrlen = sizeof(client_addr);
        conn_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &addrlen);
        if (conn_sock == -1) {
            perror("accept");
            continue;
        }

        client_sock = socket(AF_INET, SOCK_STREAM, 0);
        if (client_sock == -1) {
            perror("socket");
            close(conn_sock);
            continue;
        }

        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(80);
        inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

        if (connect(client_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
            perror("connect");
            close(client_sock);
            close(conn_sock);
            continue;
        }

        while (1) {
            memset(buffer, 0, MAX_LINE);
            if (recv(conn_sock, buffer, MAX_LINE, 0) <= 0) {
                break;
            }

            if (send(client_sock, buffer, strlen(buffer), 0) <= 0) {
                break;
            }

            if (recv(client_sock, buffer, MAX_LINE, 0) <= 0) {
                break;
            }

            if (send(conn_sock, buffer, strlen(buffer), 0) <= 0) {
                break;
            }
        }

        close(client_sock);
        close(conn_sock);
    }

    return 0;
}