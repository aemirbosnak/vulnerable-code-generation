//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BACKLOG 10
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int clients[MAX_CLIENTS];
int num_clients = 0;
char *messages[MAX_CLIENTS];

void *handle_client(void *arg) {
    int client_socket = *(int *) arg;
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            printf("Client disconnected\n");
            close(client_socket);
            return NULL;
        }

        messages[client_socket] = strdup(buffer);
        printf("Message received from client %d: %s\n", client_socket, messages[client_socket]);
    }
}

int main() {
    int server_socket;
    struct sockaddr_in server_addr;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, BACKLOG) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        int client_socket;
        socklen_t addr_size;

        client_socket = accept(server_socket, NULL, &addr_size);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        num_clients++;
        clients[num_clients - 1] = client_socket;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) &client_socket);
    }

    return 0;
}