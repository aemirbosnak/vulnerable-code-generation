//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <time.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 512

int main(int argc, char *argv[]) {
    int server_socket, new_socket, client_socket[MAX_CLIENTS], max_clients = 0, activity;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    fd_set master_fds, read_fds;

    if (argc!= 2) {
        printf("Usage:./server <port>\n");
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    FD_ZERO(&master_fds);
    FD_ZERO(&read_fds);

    FD_SET(server_socket, &master_fds);
    max_clients = server_socket;

    while (1) {
        read_fds = master_fds;
        activity = select(max_clients + 1, &read_fds, NULL, NULL, NULL);

        if (activity == -1) {
            printf("Error with select\n");
            exit(1);
        }

        if (FD_ISSET(server_socket, &read_fds)) {
            new_socket = accept(server_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));

            if (new_socket == -1) {
                printf("Error accepting connection\n");
                exit(1);
            }

            printf("New client connected on socket %d\n", new_socket);

            FD_SET(new_socket, &master_fds);
            max_clients++;
        }

        for (int i = 0; i <= max_clients; i++) {
            if (FD_ISSET(i, &read_fds)) {
                memset(buffer, 0, BUFFER_SIZE);
                if (recv(i, buffer, BUFFER_SIZE, 0) <= 0) {
                    close(i);
                    FD_CLR(i, &master_fds);
                    max_clients--;
                    printf("Client %d disconnected\n", i);
                } else {
                    printf("Received message from client %d: %s\n", i, buffer);
                }
            }
        }
    }

    return 0;
}