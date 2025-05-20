//Falcon-180B DATASET v1.0 Category: Email Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024
#define PORT 8080

int clients[MAX_CLIENTS];
int client_count = 0;

void broadcast(int sender_socket, char message[BUFFER_SIZE]) {
    for (int i = 0; i < client_count; i++) {
        if (clients[i]!= sender_socket) {
            send(clients[i], message, strlen(message), 0);
        }
    }
}

void handle_client(int client_socket) {
    char message[BUFFER_SIZE];
    while (1) {
        memset(message, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, message, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        message[bytes_received] = '\0';
        broadcast(client_socket, message);
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
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }

    printf("Email client server started on port %d\n", PORT);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }
        if (client_count >= MAX_CLIENTS) {
            send(client_socket, "Server is full. Please try again later.\n", 44, 0);
            close(client_socket);
            continue;
        }
        clients[client_count] = client_socket;
        client_count++;
        printf("Client connected: %d\n", client_socket);
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, (void *)handle_client, (void *)client_socket);
    }

    return 0;
}