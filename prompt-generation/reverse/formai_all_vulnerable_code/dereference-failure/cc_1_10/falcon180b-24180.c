//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define TRUE 1
#define FALSE 0
#define BACKLOG 10
#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int listen_fd, conn_fd;
    struct sockaddr_in serv_addr, cli_addr;
    char buf[BUF_SIZE];

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        printf("socket failed\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(listen_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        printf("bind failed\n");
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        printf("listen failed\n");
        exit(1);
    }

    while (TRUE) {
        memset(buf, 0, sizeof(buf));
        conn_fd = accept(listen_fd, (struct sockaddr *)&cli_addr, sizeof(cli_addr));
        if (conn_fd == -1) {
            printf("accept failed\n");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (TRUE) {
            memset(buf, 0, sizeof(buf));
            if (recv(conn_fd, buf, BUF_SIZE, 0) <= 0) {
                printf("Client disconnected\n");
                break;
            }

            printf("Received message: %s\n", buf);

            if (send(conn_fd, buf, strlen(buf), 0)!= strlen(buf)) {
                printf("Send failed\n");
                break;
            }
        }

        close(conn_fd);
    }

    close(listen_fd);
    return 0;
}