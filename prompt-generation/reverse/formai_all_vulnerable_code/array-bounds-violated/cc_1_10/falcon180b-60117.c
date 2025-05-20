//Falcon-180B DATASET v1.0 Category: Chat server ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define MAX_MESSAGE_LENGTH 1000

int server_socket;
int client_sockets[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *client_socket) {
    char message[MAX_MESSAGE_LENGTH];
    while (1) {
        memset(message, 0, MAX_MESSAGE_LENGTH);
        int bytes_received = recv(*((int *) client_socket), message, MAX_MESSAGE_LENGTH, 0);
        if (bytes_received <= 0) {
            break;
        }
        message[bytes_received] = '\0';
        printf("Client %d sent message: %s\n", *((int *) client_socket), message);
        for (int i = 0; i < num_clients; i++) {
            if (i!= *((int *) client_socket)) {
                send(client_sockets[i], message, strlen(message), 0);
            }
        }
    }
    close(*((int *) client_socket));
    num_clients--;
}

int main(int argc, char *argv[]) {
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(server_socket, 3) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }

    printf("Server started on port 8080\n");

    while (num_clients < MAX_CLIENTS) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_size = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_addr_size);
        if (client_socket!= -1) {
            client_sockets[num_clients] = client_socket;
            num_clients++;
            pthread_t thread_id;
            pthread_create(&thread_id, NULL, handle_client, &client_socket);
        }
    }

    close(server_socket);
    return 0;
}