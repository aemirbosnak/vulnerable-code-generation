//Falcon-180B DATASET v1.0 Category: Educational ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define MAX_MSG_SIZE 1024

int client_sockets[MAX_CLIENTS];
int num_clients = 0;

void broadcast_message(int sender_socket, char* message) {
    for (int i = 0; i < num_clients; i++) {
        if (client_sockets[i]!= sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
}

void handle_client(int client_socket) {
    char buffer[MAX_MSG_SIZE];
    while (1) {
        memset(buffer, 0, MAX_MSG_SIZE);
        int bytes_received = recv(client_socket, buffer, MAX_MSG_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        buffer[bytes_received] = '\0';
        broadcast_message(client_socket, buffer);
    }
    close(client_socket);
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }

    printf("Server started on port %d\n", PORT);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_size = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_size);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        if (num_clients >= MAX_CLIENTS) {
            send(client_socket, "Server is full. Please try again later.\n", strlen("Server is full. Please try again later.\n"), 0);
            close(client_socket);
            continue;
        }

        client_sockets[num_clients++] = client_socket;
        printf("Client %d connected\n", num_clients - 1);

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, (void*)handle_client, (void*)client_socket);
    }

    return 0;
}