//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define PORT 8080
#define BACKLOG 10

int clients[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *client_socket) {
    char buffer[1024];
    int bytes_received;

    while (1) {
        bytes_received = recv(*((int *) client_socket), buffer, 1024, 0);

        if (bytes_received <= 0) {
            break;
        }

        buffer[bytes_received] = '\0';
        printf("Client %d sent: %s\n", *((int *) client_socket), buffer);

        for (int i = 0; i < num_clients; i++) {
            if (i!= *((int *) client_socket)) {
                send(clients[i], buffer, strlen(buffer), 0);
            }
        }
    }

    close(*((int *) client_socket));
    pthread_exit(0);
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(server_socket, BACKLOG);

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);

        if (num_clients >= MAX_CLIENTS) {
            send(client_socket, "Server is full. Please try again later.", strlen("Server is full. Please try again later."), 0);
            close(client_socket);
        } else {
            clients[num_clients] = client_socket;
            num_clients++;

            pthread_t thread_id;
            pthread_create(&thread_id, NULL, handle_client, (void *) &client_socket);
        }
    }

    return 0;
}