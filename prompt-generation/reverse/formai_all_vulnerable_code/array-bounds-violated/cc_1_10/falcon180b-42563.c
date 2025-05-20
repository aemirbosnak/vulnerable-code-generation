//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024
#define PORT 8080
#define SERVER_IP "127.0.0.1"

int clients[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received = 0;
    while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Client %d sent: %s\n", client_socket, buffer);
    }
    close(client_socket);
    return NULL;
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Web server started on port %d\n", PORT);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        if (num_clients >= MAX_CLIENTS) {
            close(client_socket);
            printf("Maximum number of clients reached\n");
            continue;
        }

        clients[num_clients] = client_socket;
        num_clients++;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *)client_socket);
    }

    return 0;
}