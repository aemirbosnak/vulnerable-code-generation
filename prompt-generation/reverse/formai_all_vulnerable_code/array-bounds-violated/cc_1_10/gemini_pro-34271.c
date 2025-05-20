//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define MAX_DATA_SIZE 1024

typedef struct {
    int socket;
    struct sockaddr_in address;
    char name[MAX_DATA_SIZE];
} client_t;

typedef struct {
    int num_clients;
    client_t clients[MAX_CLIENTS];
} server_t;

server_t server;

void error(char *msg) {
    perror(msg);
    exit(1);
}

void *handle_client(void *arg) {
    client_t *client = (client_t *)arg;
    char data[MAX_DATA_SIZE];

    while (1) {
        int len = recv(client->socket, data, MAX_DATA_SIZE, 0);
        if (len <= 0) {
            break;
        }

        data[len] = '\0';
        printf("%s: %s\n", client->name, data);

        for (int i = 0; i < server.num_clients; i++) {
            if (server.clients[i].socket != client->socket) {
                send(server.clients[i].socket, data, len, 0);
            }
        }
    }

    close(client->socket);
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len;
    pthread_t client_threads[MAX_CLIENTS];

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        error("Error creating socket");
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        error("Error binding socket");
    }

    if (listen(server_socket, MAX_CLIENTS) < 0) {
        error("Error listening on socket");
    }

    while (1) {
        client_address_len = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
        if (client_socket < 0) {
            error("Error accepting client");
        }

        if (server.num_clients >= MAX_CLIENTS) {
            send(client_socket, "Server is full", 14, 0);
            close(client_socket);
            continue;
        }

        client_t client;
        client.socket = client_socket;
        client.address = client_address;

        recv(client_socket, client.name, MAX_DATA_SIZE, 0);

        server.clients[server.num_clients] = client;
        server.num_clients++;

        pthread_create(&client_threads[server.num_clients - 1], NULL, handle_client, (void *)&client);
    }

    close(server_socket);
    return 0;
}