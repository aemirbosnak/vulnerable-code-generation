//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    int listen_socket, conn_socket, port_num;
    struct sockaddr_in server_addr;
    char buffer[256];
    int client_sock, num_read, send_bytes;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port_number>\n", argv[0]);
        return 1;
    }

    port_num = atoi(argv[1]);

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket < 0) {
        perror("socket");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_num);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(listen_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        return 1;
    }

    if (listen(listen_socket, 3) < 0) {
        perror("listen");
        return 1;
    }

    while (1) {
        conn_socket = accept(listen_socket, NULL, NULL);
        if (conn_socket < 0) {
            perror("accept");
            return 1;
        }

        printf("Connected by client\n");

        pid_t child_pid = fork();
        if (child_pid < 0) {
            perror("fork");
            return 1;
        }

        if (child_pid == 0) {
            close(conn_socket);
            client_sock = socket(AF_INET, SOCK_STREAM, 0);
            if (client_sock < 0) {
                perror("socket");
                return 1;
            }

            if (connect(client_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
                perror("connect");
                return 1;
            }

            dup2(conn_socket, STDIN_FILENO);
            dup2(conn_socket, STDOUT_FILENO);
            dup2(conn_socket, STDERR_FILENO);

            execve(argv[0], &argv[0], NULL);

            perror("execve");
            return 1;
        } else {
            break;
        }
    }

    close(conn_socket);

    while (1) {
        client_sock = accept(listen_socket, NULL, NULL);
        if (client_sock < 0) {
            perror("accept");
            return 1;
        }

        printf("Client connected\n");

        int status;
        pid_t child_pid = fork();
        if (child_pid < 0) {
            perror("fork");
            return 1;
        }

        if (child_pid == 0) {
            close(client_sock);
            execve(argv[0], &argv[0], NULL);
            perror("execve");
            return 1;
        }

        waitpid(child_pid, &status, 0);
        close(client_sock);
    }

    close(listen_socket);

    return 0;
}