//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <fcntl.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket[MAX_CLIENTS], max_socket, addrlen, new_socket, i;
    struct sockaddr_in server_addr, client_addr[MAX_CLIENTS];
    char buffer[BUFFER_SIZE];
    fd_set master_socket, read_socket;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        fprintf(stderr, "Error listening on socket\n");
        exit(1);
    }

    FD_ZERO(&master_socket);
    FD_SET(server_socket, &master_socket);
    max_socket = server_socket;

    while (1) {
        read_socket = master_socket;
        if (select(max_socket + 1, &read_socket, NULL, NULL, NULL) == -1) {
            fprintf(stderr, "Error with select\n");
            exit(1);
        }

        for (i = 0; i <= max_socket; i++) {
            if (FD_ISSET(i, &read_socket)) {
                if (i == server_socket) {
                    addrlen = sizeof(client_addr[MAX_CLIENTS - 1]);
                    new_socket = accept(server_socket, (struct sockaddr *)&client_addr[MAX_CLIENTS - 1], &addrlen);

                    if (new_socket!= -1) {
                        FD_SET(new_socket, &master_socket);
                        max_socket = new_socket;

                        printf("New client connected on socket %d\n", new_socket);
                    } else {
                        printf("Error accepting connection\n");
                    }
                } else {
                    memset(buffer, 0, BUFFER_SIZE);
                    if (recv(i, buffer, BUFFER_SIZE, 0) == -1) {
                        fprintf(stderr, "Error receiving data\n");
                        exit(1);
                    } else {
                        printf("Received message from client: %s\n", buffer);
                    }
                }
            }
        }
    }

    return 0;
}