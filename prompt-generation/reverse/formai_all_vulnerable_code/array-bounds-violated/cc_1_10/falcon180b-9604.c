//Falcon-180B DATASET v1.0 Category: Chat server ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int server_socket;
int client_sockets[MAX_CLIENTS];
int num_clients;

void *handle_client(void *client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(*((int*)client_socket), buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Client %d said: %s\n", *((int*)client_socket), buffer);

        // broadcast message to all clients
        for (int i = 0; i < num_clients; i++) {
            if (i!= *((int*)client_socket)) {
                send(*((int*)&client_sockets[i]), buffer, strlen(buffer), 0);
            }
        }
    }

    close(*((int*)client_socket));

    printf("Client %d disconnected\n", *((int*)client_socket));
}

int main() {
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_socket, MAX_CLIENTS);

    printf("Chat server started on port 8080\n");

    while (1) {
        int client_socket;
        socklen_t addr_size;
        char buffer[BUFFER_SIZE];

        addr_size = sizeof(client_socket);
        client_socket = accept(server_socket, (struct sockaddr*)&client_socket, &addr_size);

        if (num_clients >= MAX_CLIENTS) {
            send(client_socket, "Server is full. Please try again later.\n", 43, 0);
            close(client_socket);
        } else {
            client_sockets[num_clients] = client_socket;
            num_clients++;

            printf("Client %d connected\n", client_socket);

            pthread_t thread_id;
            pthread_create(&thread_id, NULL, handle_client, &client_socket);
        }
    }

    return 0;
}