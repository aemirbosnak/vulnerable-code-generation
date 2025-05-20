//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_LINE 1024
#define BACKLOG 10

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd, port = 8080, addrlen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX_LINE];
    pid_t child_pid;

    if (argc > 1) {
        port = atoi(argv[1]);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int));

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(port);

    if (bind(listen_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Proxy server started on port %d\n", port);

    while (1) {
        addrlen = sizeof(cli_addr);
        conn_fd = accept(listen_fd, (struct sockaddr *)&cli_addr, &addrlen);
        if (conn_fd == -1) {
            perror("accept failed");
            continue;
        }

        child_pid = fork();
        if (child_pid == 0) {
            close(listen_fd);
            dup2(conn_fd, 0);
            dup2(conn_fd, 1);
            dup2(conn_fd, 2);
            execlp("curl", "curl", "-v", NULL);
            perror("execlp failed");
            exit(EXIT_FAILURE);
        } else {
            close(conn_fd);
        }
    }

    return 0;
}