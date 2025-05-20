//Falcon-180B DATASET v1.0 Category: Chat server ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int sock;
int clients[MAX_CLIENTS];
int num_clients = 0;

void broadcast(int sender_socket, char* message) {
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
            clients[--num_clients] = -1;
            break;
        }
        broadcast(client_socket, buffer);
    }
}

int main() {
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(sock, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }

    printf("Server started on port %d\n", PORT);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_size = sizeof(client_addr);
        int client_socket = accept(sock, (struct sockaddr*)&client_addr, &client_size);
        if (client_socket == -1) {
            printf("Error accepting client\n");
            continue;
        }

        if (num_clients >= MAX_CLIENTS) {
            close(client_socket);
            continue;
        }

        clients[num_clients++] = client_socket;
        printf("Client connected, total clients: %d\n", num_clients);

        pthread_t thread_id;
        int thread_ret = pthread_create(&thread_id, NULL, &handle_client, (void*)client_socket);
        if (thread_ret!= 0) {
            printf("Error creating thread\n");
            close(client_socket);
            clients[--num_clients] = -1;
        }
    }

    close(sock);
    return 0;
}