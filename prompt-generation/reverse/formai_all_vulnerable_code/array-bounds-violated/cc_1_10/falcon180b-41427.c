//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define BACKLOG 10
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd;
    struct sockaddr_in server_addr, client_addr;
    int opt = TRUE;
    int addrlen;
    char buf[BUF_SIZE];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        perror("socket");
        exit(1);
    }

    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Server is listening on port %s...\n", argv[1]);

    while (TRUE) {
        addrlen = sizeof(client_addr);
        conn_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &addrlen);
        if (conn_fd == -1) {
            perror("accept");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (TRUE) {
            memset(buf, 0, BUF_SIZE);
            ssize_t bytes_received = recv(conn_fd, buf, BUF_SIZE, 0);
            if (bytes_received == 0) {
                break;
            } else if (bytes_received == -1) {
                perror("recv");
                break;
            }

            buf[bytes_received] = '\0';
            printf("Received: %s", buf);

            send(conn_fd, buf, strlen(buf), 0);
        }

        close(conn_fd);
    }

    close(listen_fd);
    return 0;
}