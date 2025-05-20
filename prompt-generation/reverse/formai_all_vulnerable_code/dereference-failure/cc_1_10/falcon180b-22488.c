//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int clients[MAX_CLIENTS];
int num_clients = 0;
char *names[MAX_CLIENTS];

void broadcast(int sender_socket, char *message) {
    for (int i = 0; i < num_clients; i++) {
        if (clients[i]!= sender_socket) {
            send(clients[i], message, strlen(message), 0);
        }
    }
}

void *handle_client(void *socket_desc) {
    int socket = *(int *) socket_desc;
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(socket, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            close(socket);
            broadcast(socket, " has left the game.\n");
            break;
        }

        broadcast(socket, buffer);
    }

    close(socket);
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(12345);

    bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(server_socket, 3);

    printf("Server is listening on port 12345\n");

    while (num_clients < MAX_CLIENTS) {
        int client_socket = accept(server_socket, NULL, NULL);
        printf("Client connected on socket %d\n", client_socket);

        char *name = malloc(16);
        memset(name, 0, 16);
        sprintf(name, "Client %d", num_clients + 1);
        names[num_clients] = name;
        clients[num_clients] = client_socket;
        num_clients++;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) &client_socket);
    }

    while (1) {
        usleep(100000);
    }

    return 0;
}