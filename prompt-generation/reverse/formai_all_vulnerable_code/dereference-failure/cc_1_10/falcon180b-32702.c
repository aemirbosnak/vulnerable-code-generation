//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int server_socket;
int client_sockets[MAX_CLIENTS];
int clients_connected = 0;

void *handle_client(void *client_socket) {
    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        printf("Client %d sent: %s\n", client_socket, buffer);
        for (int i = 0; i < clients_connected; i++) {
            if (client_socket!= client_sockets[i]) {
                send(client_sockets[i], buffer, strlen(buffer), 0);
            }
        }
    }
    close(client_socket);
    clients_connected--;
}

int main() {
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in server_addr, client_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(3000);

    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_socket, MAX_CLIENTS);

    printf("Server is listening on port 3000\n");

    while (1) {
        socklen_t client_size = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_size);
        if (client_socket < 0) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }
        printf("Client %d connected\n", client_socket);

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *)client_socket);
        clients_connected++;
    }

    close(server_socket);
    return 0;
}