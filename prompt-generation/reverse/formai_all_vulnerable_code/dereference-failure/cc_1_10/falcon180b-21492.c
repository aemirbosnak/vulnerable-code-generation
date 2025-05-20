//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_DATA_SIZE 1024
#define PORT 8080
#define BACKLOG 10
#define MAX_CLIENTS 10

int clients[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *socket) {
    char buffer[MAX_DATA_SIZE];
    int bytes_received;

    while ((bytes_received = recv(*((int *) socket), buffer, MAX_DATA_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Client %d sent message: %s\n", *((int *) socket), buffer);
    }

    close(*((int *) socket));
    num_clients--;
}

void accept_connections(int server_socket) {
    while (num_clients < MAX_CLIENTS) {
        int client_socket = accept(server_socket, NULL, NULL);

        if (client_socket == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
        } else {
            clients[num_clients] = client_socket;
            num_clients++;

            pthread_t thread_id;
            pthread_create(&thread_id, NULL, handle_client, &clients[num_clients - 1]);
        }
    }
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket: %s\n", strerror(errno));
        return 1;
    }

    if (listen(server_socket, BACKLOG) == -1) {
        printf("Error listening on socket: %s\n", strerror(errno));
        return 1;
    }

    printf("Server started on port %d\n", PORT);

    accept_connections(server_socket);

    return 0;
}