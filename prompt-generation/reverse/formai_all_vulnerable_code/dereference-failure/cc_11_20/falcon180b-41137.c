//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

int main(int argc, char *argv[]) {
    int server_socket, client_socket[MAX_CLIENTS], max_socket, new_socket, client_len, i;
    struct sockaddr_in server_addr, client_addr[MAX_CLIENTS];
    char buffer[BUFFER_SIZE];
    fd_set master_fds, read_fds;

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    FD_ZERO(&master_fds);
    FD_SET(server_socket, &master_fds);
    max_socket = server_socket;

    while (1) {
        read_fds = master_fds;
        if (select(max_socket + 1, &read_fds, NULL, NULL, NULL) == -1) {
            printf("Error with select\n");
            exit(1);
        }

        for (i = 0; i <= max_socket; i++) {
            if (FD_ISSET(i, &read_fds)) {
                if (i == server_socket) {
                    client_len = sizeof(client_addr[0]);
                    new_socket = accept(server_socket, (struct sockaddr *)&client_addr[0], &client_len);

                    if (new_socket!= -1) {
                        FD_SET(new_socket, &master_fds);
                        max_socket = new_socket;
                    } else {
                        printf("Error accepting connection\n");
                    }
                } else {
                    memset(buffer, 0, BUFFER_SIZE);
                    if (recv(i, buffer, BUFFER_SIZE, 0) == 0) {
                        close(i);
                        FD_CLR(i, &master_fds);
                    } else {
                        for (int j = 0; j < MAX_CLIENTS; j++) {
                            if (client_socket[j]!= -1 && i!= client_socket[j]) {
                                send(client_socket[j], buffer, strlen(buffer), 0);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}