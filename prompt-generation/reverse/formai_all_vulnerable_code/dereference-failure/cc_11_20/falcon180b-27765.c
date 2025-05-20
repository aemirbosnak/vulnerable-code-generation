//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int listen_socket, client_socket, port;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    pid_t pid;

    if (argc!= 3) {
        printf("Usage: %s <port> <destination>\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[1]);
    if (port <= 0 || port > 65535) {
        printf("Invalid port number\n");
        exit(1);
    }

    if (inet_pton(AF_INET, argv[2], &server_addr.sin_addr) <= 0) {
        printf("Invalid destination address\n");
        exit(1);
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(listen_socket, 5) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (1) {
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        pid = fork();
        if (pid == -1) {
            printf("Error forking process\n");
            close(client_socket);
            continue;
        } else if (pid == 0) {
            close(listen_socket);

            dup2(client_socket, 0);
            dup2(client_socket, 1);

            execlp("nc", "nc", argv[2], NULL);
            perror("execlp");
            exit(1);
        } else {
            close(client_socket);
        }
    }

    close(listen_socket);
    return 0;
}