//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 3000
#define BACKLOG 10
#define TRUE 1
#define FALSE 0
#define MAX_LINE 1024
#define DELIM " "

int main(int argc, char *argv[]) {
    int listen_socket, accept_socket;
    struct sockaddr_in server_addr, client_addr;
    int addrlen = sizeof(client_addr);
    char buffer[MAX_LINE];
    pid_t childpid;

    if (argc < 2) {
        printf("Usage: %s <port_number>\n", argv[0]);
        exit(1);
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(listen_socket, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Server is listening on port %d\n", atoi(argv[1]));

    while (TRUE) {
        if ((accept_socket = accept(listen_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) == -1) {
            perror("accept");
            exit(1);
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        childpid = fork();
        if (childpid == -1) {
            perror("fork");
            exit(1);
        } else if (childpid == 0) {
            // Child process
            close(listen_socket);
            dup2(accept_socket, 0);
            dup2(accept_socket, 1);
            dup2(accept_socket, 2);
            close(accept_socket);

            execlp("sh", "sh", NULL);
            perror("execlp");
            exit(1);
        } else {
            // Parent process
            close(accept_socket);
        }
    }

    return 0;
}