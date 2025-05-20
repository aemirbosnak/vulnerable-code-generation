//Falcon-180B DATASET v1.0 Category: Chat server ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd;
    struct sockaddr_in serv_addr, cli_addr;
    char buf[BUF_SIZE];
    int opt = TRUE;

    if (argc!= 2) {
        printf("Usage:./chat_server <port>\n");
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        printf("socket failed\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(listen_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("bind failed\n");
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) < 0) {
        printf("listen failed\n");
        exit(1);
    }

    while (opt) {
        memset(buf, 0, BUF_SIZE);
        conn_fd = accept(listen_fd, (struct sockaddr *) NULL, NULL);
        if (conn_fd < 0) {
            printf("accept failed\n");
            exit(1);
        }

        printf("New connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (1) {
            bzero(buf, BUF_SIZE);
            fgets(buf, BUF_SIZE, stdin);

            send(conn_fd, buf, strlen(buf), 0);

            if (strcmp(buf, "bye\n") == 0) {
                printf("Connection closed by client\n");
                opt = FALSE;
                break;
            }
        }

        close(conn_fd);
    }

    close(listen_fd);
    exit(0);
}