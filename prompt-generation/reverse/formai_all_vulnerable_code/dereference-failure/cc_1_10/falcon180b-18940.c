//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define BACKLOG 10

int main(int argc, char **argv) {
    int listen_fd, conn_fd, addrlen;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    char buffer[MAX_LINE];

    if (argc!= 3) {
        printf("Usage: %s <port> <ip>\n", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        printf("socket failed\n");
        exit(1);
    }

    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    inet_pton(AF_INET, argv[2], &server_addr.sin_addr);

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("bind failed\n");
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        printf("listen failed\n");
        exit(1);
    }

    printf("Proxy server listening on port %s\n", argv[1]);

    while (1) {
        addrlen = sizeof(client_addr);
        conn_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &addrlen);

        if (conn_fd == -1) {
            printf("accept failed\n");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, MAX_LINE);
            int bytes_received = recv(conn_fd, buffer, MAX_LINE, 0);

            if (bytes_received <= 0) {
                printf("Client disconnected\n");
                break;
            }

            send(conn_fd, buffer, bytes_received, 0);
        }

        close(conn_fd);
    }

    return 0;
}