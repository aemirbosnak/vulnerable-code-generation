//Falcon-180B DATASET v1.0 Category: Chat server ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define MAX_MSG_LENGTH 1024
#define SERVER_PORT 8080

int client_sockets[MAX_CLIENTS];
int num_clients = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void broadcast(int sender_socket, char* message) {
    pthread_mutex_lock(&lock);
    for (int i = 0; i < num_clients; i++) {
        if (client_sockets[i]!= sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&lock);
}

void handle_client(int client_socket) {
    char buffer[MAX_MSG_LENGTH];
    while (1) {
        memset(buffer, 0, MAX_MSG_LENGTH);
        int bytes_received = recv(client_socket, buffer, MAX_MSG_LENGTH, 0);
        if (bytes_received <= 0) {
            close(client_socket);
            break;
        }
        buffer[bytes_received] = '\0';
        broadcast(client_socket, buffer);
    }
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_socket, MAX_CLIENTS);

    printf("Server started on port %d\n", SERVER_PORT);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (num_clients >= MAX_CLIENTS) {
            send(client_socket, "Server full", strlen("Server full"), 0);
            close(client_socket);
        } else {
            client_sockets[num_clients] = client_socket;
            num_clients++;
            pthread_t thread_id;
            pthread_create(&thread_id, NULL, (void*)handle_client, (void*)client_socket);
        }
    }

    return 0;
}