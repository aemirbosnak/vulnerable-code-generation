//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define PORT 8080
#define BUFFER_SIZE 1024

int clients[MAX_CLIENTS];
int num_clients = 0;

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        printf("Client %d sent: %s\n", client_socket, buffer);
        send(client_socket, buffer, bytes_received, 0);
    }
    close(client_socket);
    clients[num_clients - 1] = -1;
    num_clients--;
}

void accept_connections() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_socket, MAX_CLIENTS);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }
        printf("Client %d connected\n", client_socket);
        clients[num_clients++] = client_socket;
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, (void *)handle_client, (void *)client_socket);
    }
}

int main() {
    accept_connections();
    return 0;
}