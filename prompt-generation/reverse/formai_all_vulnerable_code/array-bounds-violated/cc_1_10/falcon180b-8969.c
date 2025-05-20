//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int client_sockets[MAX_CLIENTS];
int num_clients = 0;

void broadcast(int sender_socket, char* message) {
    for (int i = 0; i < num_clients; i++) {
        if (i!= sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
}

void *handle_client(void *socket_ptr) {
    int client_socket = *(int *) socket_ptr;
    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        buffer[bytes_received] = '\0';
        broadcast(client_socket, buffer);
    }
    close(client_socket);
    return NULL;
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);
    bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(server_socket, MAX_CLIENTS);

    printf("Server is running on %s:%d\n", SERVER_IP, SERVER_PORT);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (num_clients >= MAX_CLIENTS) {
            send(client_socket, "Server is full.", strlen("Server is full."), 0);
            close(client_socket);
        } else {
            client_sockets[num_clients] = client_socket;
            num_clients++;
            pthread_t thread_id;
            pthread_create(&thread_id, NULL, handle_client, (void *) &client_socket);
        }
    }

    return 0;
}