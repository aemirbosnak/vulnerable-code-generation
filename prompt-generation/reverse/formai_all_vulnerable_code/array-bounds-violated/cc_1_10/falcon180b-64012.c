//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Global variables
int server_socket;
int client_sockets[MAX_CLIENTS];
int num_clients;

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        if (recv(client_socket, buffer, BUFFER_SIZE, 0) <= 0) {
            close(client_socket);
            client_sockets[--num_clients] = -1;
            break;
        }
        printf("Client %d: %s", client_socket, buffer);
        send(client_socket, buffer, strlen(buffer), 0);
    }
}

int main() {
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in server_addr, client_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(server_socket, MAX_CLIENTS) < 0) {
        printf("Error listening on socket\n");
        return 1;
    }

    printf("Server started on port 8080\n");

    while (1) {
        socklen_t addr_size;
        int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_size);
        if (client_socket < 0) {
            printf("Error accepting connection\n");
            continue;
        }

        if (num_clients >= MAX_CLIENTS) {
            close(client_socket);
            printf("Too many clients\n");
            continue;
        }

        client_sockets[num_clients] = client_socket;
        num_clients++;

        printf("Client connected: %d\n", client_socket);

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, (void *)handle_client, (void *)client_socket);
    }

    return 0;
}