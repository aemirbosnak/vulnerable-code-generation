//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int server_socket;
int client_sockets[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(*((int *) client_socket), buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Client %d sent message: %s\n", num_clients, buffer);
        for (int i = 0; i < num_clients; i++) {
            if (i!= num_clients - 1) {
                send(client_sockets[i], buffer, strlen(buffer), 0);
            }
        }
    }

    close(*((int *) client_socket));
    printf("Client %d disconnected\n", num_clients);

    return NULL;
}

int main() {
    int opt = 1;
    struct sockaddr_in server_addr, client_addr;
    pthread_t threads[MAX_CLIENTS];

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(5000);

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }

    printf("Server listening on port 5000\n");

    while (1) {
        socklen_t addr_size = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &addr_size);

        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        if (num_clients >= MAX_CLIENTS) {
            printf("Maximum number of clients reached\n");
            close(client_socket);
            continue;
        }

        client_sockets[num_clients] = client_socket;
        num_clients++;

        pthread_create(&threads[num_clients - 1], NULL, handle_client, (void *) &client_socket);
    }

    return 0;
}