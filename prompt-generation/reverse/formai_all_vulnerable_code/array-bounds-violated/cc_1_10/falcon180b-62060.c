//Falcon-180B DATASET v1.0 Category: Networking ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define MAX_CLIENTS 10

int server_socket;
struct sockaddr_in server_addr;
int client_sockets[MAX_CLIENTS];

void *handle_client(void *client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(*((int *) client_socket), buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Client %d sent message: %s\n", *((int *) client_socket), buffer);
    }

    close(*((int *) client_socket));
    return NULL;
}

int main() {
    int opt = 1;
    int client_socket;
    struct sockaddr_in client_addr;
    pthread_t thread_id;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *) &client_addr, sizeof(client_addr));

        if (client_socket == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        printf("Client %d connected\n", client_socket);

        client_sockets[client_socket] = client_socket;

        pthread_create(&thread_id, NULL, handle_client, &client_socket);
    }

    return 0;
}