//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LINE 1024
#define BACKLOG 10

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd;
    struct sockaddr_in listen_addr, conn_addr;
    int opt = 1;
    int addrlen;
    char buffer[MAX_LINE];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <port> <host>\n", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        fprintf(stderr, "socket() failed: %s\n", strerror(errno));
        exit(1);
    }

    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = INADDR_ANY;
    listen_addr.sin_port = htons(atoi(argv[1]));

    if (bind(listen_fd, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) == -1) {
        fprintf(stderr, "bind() failed: %s\n", strerror(errno));
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        fprintf(stderr, "listen() failed: %s\n", strerror(errno));
        exit(1);
    }

    addrlen = sizeof(conn_addr);

    while (1) {
        conn_fd = accept(listen_fd, (struct sockaddr *)&conn_addr, &addrlen);
        if (conn_fd == -1) {
            fprintf(stderr, "accept() failed: %s\n", strerror(errno));
            continue;
        }

        fprintf(stdout, "Connection from %s:%d\n", inet_ntoa(conn_addr.sin_addr), ntohs(conn_addr.sin_port));

        while (1) {
            memset(buffer, 0, MAX_LINE);
            ssize_t bytes_received = recv(conn_fd, buffer, MAX_LINE, 0);

            if (bytes_received <= 0) {
                if (bytes_received == 0) {
                    fprintf(stdout, "Client disconnected\n");
                } else {
                    fprintf(stdout, "recv() failed: %s\n", strerror(errno));
                }
                break;
            }

            fprintf(stdout, "Received: %s", buffer);

            ssize_t bytes_sent = send(conn_fd, buffer, strlen(buffer), 0);

            if (bytes_sent <= 0) {
                if (bytes_sent == 0) {
                    fprintf(stdout, "Client disconnected\n");
                } else {
                    fprintf(stdout, "send() failed: %s\n", strerror(errno));
                }
                break;
            }
        }

        close(conn_fd);
    }

    close(listen_fd);

    return 0;
}