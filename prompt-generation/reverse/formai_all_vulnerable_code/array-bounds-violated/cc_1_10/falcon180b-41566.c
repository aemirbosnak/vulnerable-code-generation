//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"

int client_sockets[MAX_CLIENTS];
int num_clients = 0;

void broadcast(int sender_socket, char* message) {
    for (int i = 0; i < num_clients; i++) {
        if (client_sockets[i]!= sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
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
            client_sockets[--num_clients] = 0;
            break;
        }
        buffer[bytes_received] = '\0';
        broadcast(client_socket, buffer);
    }
}

int main(int argc, char* argv[]) {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 2;
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        return 3;
    }

    printf("Server started on port %d\n", SERVER_PORT);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket!= -1) {
            client_sockets[num_clients++] = client_socket;
            printf("Client connected: %d\n", client_socket);
        }
    }

    return 0;
}