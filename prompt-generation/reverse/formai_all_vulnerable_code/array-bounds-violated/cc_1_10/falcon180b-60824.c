//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int clients[MAX_CLIENTS];
int client_count = 0;

void *handle_client(void *socket) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    while (1) {
        int bytes = recv(clients[client_count], buffer, BUFFER_SIZE, 0);
        if (bytes <= 0) {
            break;
        }

        printf("Client %d sent: %s\n", client_count, buffer);
        send(clients[client_count], buffer, strlen(buffer), 0);
    }

    close(clients[client_count]);
    client_count--;

    return NULL;
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
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 2;
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        return 3;
    }

    printf("Server listening on port 8080\n");

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_size = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_size);

        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        if (client_count >= MAX_CLIENTS) {
            send(client_socket, "Server is full\n", strlen("Server is full\n"), 0);
            close(client_socket);
            continue;
        }

        clients[client_count] = client_socket;
        client_count++;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *)client_socket);
    }

    close(server_socket);
    return 0;
}