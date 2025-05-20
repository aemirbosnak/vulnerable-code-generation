//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: simpleproxy <listen_port> <server_port>\n");
        exit(EXIT_FAILURE);
    }

    int listen_port = atoi(argv[1]);
    int server_port = atoi(argv[2]);

    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in listen_addr = {0};
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    listen_addr.sin_port = htons(listen_port);

    if (bind(listen_fd, (struct sockaddr*)&listen_addr, sizeof(listen_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(listen_fd, 1) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct hostent* server = gethostbyname("localhost");
    if (server == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = *((unsigned long*)server->h_addr);
    server_addr.sin_port = htons(server_port);

    if (connect(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "Simple proxy listening on port %d and connected to server on port %d\n", listen_port, server_port);

    while (true) {
        struct sockaddr_in client_addr = {0};
        socklen_t client_size = sizeof(client_addr);

        int client_fd = accept(listen_fd, (struct sockaddr*)&client_addr, &client_size);
        if (client_fd == -1) {
            perror("accept");
            continue;
        }

        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            continue;
        }

        if (pid == 0) { // child process
            if (close(listen_fd) == -1) {
                perror("close");
                exit(EXIT_FAILURE);
            }

            char buffer[BUFFER_SIZE] = {0};
            int num_bytes = recv(client_fd, buffer, BUFFER_SIZE, MSG_DONTWAIT);
            while (num_bytes != -1 && num_bytes != 0) {
                if (send(server_fd, buffer, num_bytes, MSG_DONTWAIT) == -1) {
                    perror("send");
                    exit(EXIT_FAILURE);
                }

                num_bytes = recv(client_fd, buffer, BUFFER_SIZE, MSG_DONTWAIT);
            }

            if (close(client_fd) == -1) {
                perror("close");
                exit(EXIT_FAILURE);
            }

            exit(EXIT_SUCCESS);
        }

        if (pid > 0) { // parent process
            if (close(client_fd) == -1) {
                perror("close");
                continue;
            }
        }
    }

    return 0;
}