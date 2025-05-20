//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX 1024

int main() {
    int server_socket, client_socket, addrlen, new_socket, max_clients = 5, activity;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX];
    fd_set master_fds, read_fds;

    FD_ZERO(&master_fds);
    FD_ZERO(&read_fds);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, max_clients) < 0) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server is listening on port 8080\n");

    FD_SET(server_socket, &master_fds);
    addrlen = sizeof(client_addr);

    while (1) {
        read_fds = master_fds;

        if (select(FD_SETSIZE, &read_fds, NULL, NULL, NULL) == -1) {
            printf("Error with select()\n");
            exit(1);
        }

        for (int i = 0; i < FD_SETSIZE; i++) {
            if (FD_ISSET(i, &read_fds)) {
                if (i == server_socket) {
                    new_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t *)&addrlen);

                    if (new_socket < 0) {
                        printf("Error accepting connection\n");
                        exit(1);
                    }

                    FD_SET(new_socket, &master_fds);

                    printf("New client connected\n");
                } else {
                    activity = recv(i, buffer, MAX, 0);

                    if (activity <= 0) {
                        close(i);
                        FD_CLR(i, &master_fds);

                        printf("Client disconnected\n");
                    } else {
                        send(i, buffer, strlen(buffer), 0);
                    }
                }
            }
        }
    }

    return 0;
}