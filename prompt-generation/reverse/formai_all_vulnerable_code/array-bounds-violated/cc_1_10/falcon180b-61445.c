//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 5
#define PORT 8080

int server_socket;
int client_sockets[MAX_CLIENTS];
int num_clients;

void *handle_client(void *arg) {
    int client_socket = *(int *) arg;
    char buffer[1024];
    while (1) {
        bzero(buffer, 1024);
        int bytes_received = recv(client_socket, buffer, 1024, 0);
        if (bytes_received <= 0) {
            close(client_socket);
            return NULL;
        }
        buffer[bytes_received] = '\0';
        printf("Client %d sent: %s\n", client_socket, buffer);
    }
}

int main() {
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in server_addr, client_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(server_socket, 3);

    printf("Server listening on port %d\n", PORT);

    while (1) {
        socklen_t client_size = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_size);

        if (num_clients >= MAX_CLIENTS) {
            close(client_socket);
            continue;
        }

        client_sockets[num_clients] = client_socket;
        num_clients++;

        pthread_t thread_id;
        int rc = pthread_create(&thread_id, NULL, handle_client, (void *) &client_socket);
        if (rc) {
            close(client_socket);
            printf("Error: unable to create thread, %s\n", strerror(rc));
        }
    }

    return 0;
}