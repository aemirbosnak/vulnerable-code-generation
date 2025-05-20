//Falcon-180B DATASET v1.0 Category: Firewall ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_LINE 1024
#define BACKLOG 10
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd, ret, opt = TRUE;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t addr_len = sizeof(cli_addr);
    char buffer[MAX_LINE];

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

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[1]));
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listen_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    while (TRUE) {
        conn_fd = accept(listen_fd, (struct sockaddr *)&cli_addr, &addr_len);
        if (conn_fd == -1) {
            perror("accept");
            exit(1);
        }

        printf("Connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        ret = fork();
        if (ret == -1) {
            perror("fork");
            exit(1);
        } else if (ret == 0) {
            close(listen_fd);

            while (TRUE) {
                memset(buffer, 0, MAX_LINE);
                ret = read(conn_fd, buffer, MAX_LINE);
                if (ret <= 0) {
                    break;
                }

                write(STDOUT_FILENO, buffer, ret);
            }

            close(conn_fd);
            exit(0);
        } else {
            close(conn_fd);
        }
    }

    return 0;
}