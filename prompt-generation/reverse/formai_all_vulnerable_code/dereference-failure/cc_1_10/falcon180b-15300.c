//Falcon-180B DATASET v1.0 Category: Chat server ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 50
#define MAX_MESSAGE_LENGTH 1024
#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"

int server_socket;
int client_sockets[MAX_CLIENTS];
int num_clients = 0;
int max_clients = MAX_CLIENTS;

void *handle_client(void *client_socket) {
    char buffer[MAX_MESSAGE_LENGTH];
    while (1) {
        bzero(buffer, MAX_MESSAGE_LENGTH);
        int bytes_received = recv(client_socket, buffer, MAX_MESSAGE_LENGTH, 0);
        if (bytes_received <= 0) {
            break;
        }
        send(client_socket, buffer, bytes_received, 0);
    }
    close(client_socket);
    pthread_exit(NULL);
}

void accept_connections() {
    while (num_clients < max_clients) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            printf("Accept failed: %s\n", strerror(errno));
            continue;
        }
        client_sockets[num_clients++] = client_socket;
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *)client_socket);
    }
}

int main() {
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Bind failed: %s\n", strerror(errno));
        exit(1);
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Listen failed: %s\n", strerror(errno));
        exit(1);
    }

    printf("Server started on port %d\n", SERVER_PORT);

    accept_connections();

    return 0;
}