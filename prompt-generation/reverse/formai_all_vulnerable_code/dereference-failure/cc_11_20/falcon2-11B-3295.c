//Falcon2-11B DATASET v1.0 Category: System administration ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int server_socket, new_socket;
    struct sockaddr_in server_address;
    int listen_backlog = 5;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(atoi(argv[1]));

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(server_socket, listen_backlog) == -1) {
        perror("listen");
        exit(1);
    }

    while (1) {
        new_socket = accept(server_socket, NULL, NULL);
        if (new_socket == -1) {
            perror("accept");
            exit(1);
        }

        int child_pid;
        pid_t parent_pid = getpid();

        child_pid = fork();
        if (child_pid == -1) {
            perror("fork");
            exit(1);
        }

        if (child_pid == 0) {
            // Child process
            close(0);
            dup(new_socket);
            close(new_socket);

            char buffer[256];
            while (1) {
                if (read(new_socket, buffer, sizeof(buffer)) == -1) {
                    perror("read");
                    exit(1);
                }

                if (buffer[0] == '\0') {
                    break;
                }

                write(new_socket, "Parent: ", 9);
                write(new_socket, buffer, strlen(buffer));
                write(new_socket, "\n", 1);
            }

            exit(0);
        } else {
            // Parent process
            close(1);
            close(2);
            dup(new_socket);
            close(new_socket);

            while (1) {
                if (waitpid(child_pid, NULL, WNOHANG) == -1) {
                    perror("waitpid");
                    exit(1);
                }

                if (WIFEXITED(WEXITSTATUS(child_pid))) {
                    break;
                }
            }

            exit(0);
        }
    }
}