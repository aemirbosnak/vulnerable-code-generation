//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10
#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"

int server_socket;
int client_sockets[MAX_CLIENTS];
int num_clients;

void *handle_client(void *client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(*((int *) client_socket), buffer, BUFFER_SIZE, 0)) > 0) {
        printf("Client %d sent: %s\n", *(int *) client_socket, buffer);
        send(server_socket, buffer, bytes_received, 0);
    }

    close(*((int *) client_socket));
}

void accept_connections() {
    while (num_clients < MAX_CLIENTS) {
        int client_socket = accept(server_socket, NULL, NULL);

        if (client_socket!= -1) {
            client_sockets[num_clients] = client_socket;
            num_clients++;

            pthread_t thread_id;
            pthread_create(&thread_id, NULL, handle_client, &client_socket);
        }
    }
}

int main() {
    int opt = 1;
    struct sockaddr_in server_addr;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server listening on port %d\n", SERVER_PORT);

    accept_connections();

    return 0;
}