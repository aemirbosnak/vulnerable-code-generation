//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_CLIENTS 10
#define MAX_MSG_SIZE 1024

int clients[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[MAX_MSG_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_socket, buffer, MAX_MSG_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Client %d: %s\n", client_socket, buffer);
    }

    close(client_socket);
    return NULL;
}

void accept_connections(int server_socket) {
    while (num_clients < MAX_CLIENTS) {
        int client_socket = accept(server_socket, NULL, NULL);

        if (client_socket < 0) {
            printf("Error accepting connection\n");
            continue;
        }

        clients[num_clients++] = client_socket;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, &clients[num_clients - 1]);
    }
}

int main() {
    int server_socket, opt = 1;
    struct sockaddr_in server_addr;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == 0) {
        printf("Error creating socket\n");
        return 1;
    }

    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(server_socket, 3) < 0) {
        printf("Error listening\n");
        return 1;
    }

    printf("Server started on port 8080\n");

    accept_connections(server_socket);

    return 0;
}