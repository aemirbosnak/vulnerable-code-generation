//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUF_SIZE 8192

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUF_SIZE];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <port> <ip>\n", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = inet_addr(argv[2]);

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(listen_fd, 5) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Proxy server started on port %d\n", atoi(argv[1]));

    while (1) {
        conn_fd = accept(listen_fd, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if (conn_fd == -1) {
            perror("accept");
            continue;
        }

        client_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (client_fd == -1) {
            perror("socket");
            close(conn_fd);
            continue;
        }

        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(80);
        server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

        if (connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
            perror("connect");
            close(conn_fd);
            close(client_fd);
            continue;
        }

        while (1) {
            memset(buffer, 0, BUF_SIZE);
            ssize_t bytes_received = recv(conn_fd, buffer, BUF_SIZE, 0);
            if (bytes_received <= 0) {
                if (bytes_received == 0) {
                    printf("Connection closed by client\n");
                } else if (errno!= EAGAIN) {
                    perror("recv");
                }
                break;
            }

            ssize_t bytes_sent = send(client_fd, buffer, bytes_received, 0);
            if (bytes_sent <= 0) {
                if (bytes_sent == 0) {
                    printf("Connection closed by server\n");
                } else if (errno!= EAGAIN) {
                    perror("send");
                }
                break;
            }
        }

        close(conn_fd);
        close(client_fd);
    }

    close(listen_fd);
    return 0;
}