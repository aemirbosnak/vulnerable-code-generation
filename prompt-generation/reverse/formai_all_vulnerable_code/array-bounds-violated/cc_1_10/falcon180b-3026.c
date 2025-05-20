//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: optimized
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
    char *message;
    while (1) {
        int bytes_received = recv(*((int *) client_socket), buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        buffer[bytes_received] = '\0';
        message = strdup(buffer);
        send(*((int *) client_socket), message, strlen(message), 0);
        free(message);
    }
    close(*((int *) client_socket));
    pthread_exit(0);
}

int main() {
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in server_addr, client_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(server_socket, MAX_CLIENTS) < 0) {
        printf("Error listening on socket\n");
        return 1;
    }

    printf("Server started on port 8080\n");

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t addr_size = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &addr_size);
        if (client_socket < 0) {
            printf("Error accepting connection\n");
            continue;
        }
        if (num_clients >= MAX_CLIENTS) {
            close(client_socket);
            printf("Maximum clients reached\n");
            continue;
        }
        client_sockets[num_clients++] = client_socket;
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) &client_socket);
    }

    return 0;
}