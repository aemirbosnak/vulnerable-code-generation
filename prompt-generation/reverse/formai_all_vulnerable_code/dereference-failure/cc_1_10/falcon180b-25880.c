//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LINE 1024
#define BACKLOG 10

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(client_addr);

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <port> <ip>\n", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        fprintf(stderr, "socket failed: %s\n", strerror(errno));
        exit(1);
    }

    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    inet_pton(AF_INET, argv[2], &server_addr.sin_addr);

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "bind failed: %s\n", strerror(errno));
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        fprintf(stderr, "listen failed: %s\n", strerror(errno));
        exit(1);
    }

    while (1) {
        conn_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &addrlen);
        if (conn_fd == -1) {
            fprintf(stderr, "accept failed: %s\n", strerror(errno));
            continue;
        }

        printf("Accepted connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        char buf[MAX_LINE];
        while (1) {
            memset(buf, 0, MAX_LINE);
            int bytes_received = recv(conn_fd, buf, MAX_LINE, 0);
            if (bytes_received <= 0) {
                if (bytes_received == 0) {
                    fprintf(stderr, "Connection closed by client\n");
                } else {
                    fprintf(stderr, "recv failed: %s\n", strerror(errno));
                }
                break;
            }

            printf("Received: %s", buf);

            send(conn_fd, buf, strlen(buf), 0);
        }

        close(conn_fd);
    }

    close(listen_fd);
    return 0;
}