//Falcon-180B DATASET v1.0 Category: Chat server ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int clients[MAX_CLIENTS];
int num_clients = 0;

void broadcast(int sender_socket, char *message) {
    for (int i = 0; i < num_clients; i++) {
        if (clients[i]!= sender_socket) {
            send(clients[i], message, strlen(message), 0);
        }
    }
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            close(client_socket);
            clients[client_socket] = -1;
            num_clients--;
            break;
        }
        broadcast(client_socket, buffer);
    }
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "0.0.0.0", &server_addr.sin_addr);

    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_socket, MAX_CLIENTS);

    printf("Chat server started on port 8080\n");

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }
        clients[client_socket] = client_socket;
        num_clients++;
        printf("Client connected, total clients: %d\n", num_clients);
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, (void *)handle_client, (void *)client_socket);
    }

    close(server_socket);
    return 0;
}