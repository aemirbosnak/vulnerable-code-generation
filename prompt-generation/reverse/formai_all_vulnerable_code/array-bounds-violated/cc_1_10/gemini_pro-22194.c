//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_CLIENTS 10
#define MAX_MESSAGE_SIZE 1024

struct client {
    int socket;
    struct sockaddr_in addr;
    char username[32];
};

struct server {
    int socket;
    struct sockaddr_in addr;
    struct client clients[MAX_CLIENTS];
    int num_clients;
};

void send_to_all(struct server *server, char *message) {
    for (int i = 0; i < server->num_clients; i++) {
        send(server->clients[i].socket, message, strlen(message), 0);
    }
}

void handle_client(struct server *server, int socket) {
    char buffer[MAX_MESSAGE_SIZE];

    while (1) {
        int n = recv(socket, buffer, MAX_MESSAGE_SIZE, 0);
        if (n <= 0) {
            break;
        }

        buffer[n] = '\0';

        if (strncmp(buffer, "/quit", 5) == 0) {
            break;
        }

        send_to_all(server, buffer);
    }

    close(socket);

    for (int i = 0; i < server->num_clients; i++) {
        if (server->clients[i].socket == socket) {
            server->clients[i] = server->clients[server->num_clients - 1];
            server->num_clients--;
            break;
        }
    }
}

int main() {
    struct server server;

    server.socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server.socket == -1) {
        perror("socket");
        return 1;
    }

    server.addr.sin_family = AF_INET;
    server.addr.sin_port = htons(8080);
    server.addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server.socket, (struct sockaddr *)&server.addr, sizeof(server.addr)) == -1) {
        perror("bind");
        return 1;
    }

    if (listen(server.socket, 10) == -1) {
        perror("listen");
        return 1;
    }

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);

        int client_socket = accept(server.socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        if (server.num_clients >= MAX_CLIENTS) {
            close(client_socket);
            continue;
        }

        server.clients[server.num_clients].socket = client_socket;
        server.clients[server.num_clients].addr = client_addr;
        server.num_clients++;

        char message[MAX_MESSAGE_SIZE];
        sprintf(message, "%s has joined the chat\n", strtok(inet_ntoa(client_addr.sin_addr), ":"));
        send_to_all(&server, message);

        handle_client(&server, client_socket);
    }

    close(server.socket);

    return 0;
}