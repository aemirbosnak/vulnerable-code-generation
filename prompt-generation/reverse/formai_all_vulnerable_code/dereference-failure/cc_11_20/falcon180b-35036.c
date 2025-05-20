//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BACKLOG 10
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUF_SIZE];
    int addrlen;

    if (argc!= 1) {
        fprintf(stderr, "Usage: %s\n", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        perror("socket failed");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(listen_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("bind failed");
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    while (1) {
        addrlen = sizeof(cli_addr);
        conn_fd = accept(listen_fd, (struct sockaddr *)&cli_addr, &addrlen);
        if (conn_fd == -1) {
            perror("accept");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (1) {
            bzero(buffer, BUF_SIZE);
            memset(buffer, 0, BUF_SIZE);
            if ((recv(conn_fd, buffer, BUF_SIZE, 0)) <= 0) {
                if (errno!= EAGAIN) {
                    perror("recv");
                }
                break;
            }

            printf("Received data: %s\n", buffer);

            if (send(conn_fd, buffer, strlen(buffer), 0)!= strlen(buffer)) {
                perror("send");
            }
        }

        close(conn_fd);
    }

    close(listen_fd);
    return 0;
}