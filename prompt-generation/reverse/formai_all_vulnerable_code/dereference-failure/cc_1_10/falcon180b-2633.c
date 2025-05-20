//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>

void sigchld_handler(int signum) {
    while (waitpid(-1, NULL, WNOHANG) > 0) {
        // do nothing
    }
}

int main(int argc, char *argv[]) {
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(client_addr);
    pid_t childpid;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        perror("socket");
        exit(1);
    }

    setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(listen_socket, 5) == -1) {
        perror("listen");
        exit(1);
    }

    while (1) {
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &addrlen);
        if (client_socket == -1) {
            perror("accept");
            exit(1);
        }

        childpid = fork();
        if (childpid == -1) {
            perror("fork");
            exit(1);
        } else if (childpid == 0) {
            // child process
            close(listen_socket);
            dup2(client_socket, 0);
            dup2(client_socket, 1);
            dup2(client_socket, 2);
            execlp("cat", "cat", NULL);
            perror("execlp");
            exit(1);
        } else {
            // parent process
            close(client_socket);
        }
    }

    return 0;
}