//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4000
#define MAX_CLIENTS 10
#define MAX_NAME_LENGTH 32

struct client {
    int sock;
    char name[MAX_NAME_LENGTH];
};

struct server {
    int sock;
    struct client clients[MAX_CLIENTS];
    int num_clients;
};

void init_server(struct server *server) {
    server->sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server->sock == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server->sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(server->sock, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
}

void add_client(struct server *server, int sock, char *name) {
    if (server->num_clients >= MAX_CLIENTS) {
        printf("Server is full\n");
        close(sock);
        return;
    }

    server->clients[server->num_clients].sock = sock;
    strncpy(server->clients[server->num_clients].name, name, MAX_NAME_LENGTH);
    server->num_clients++;
}

void remove_client(struct server *server, int sock) {
    for (int i = 0; i < server->num_clients; i++) {
        if (server->clients[i].sock == sock) {
            for (int j = i + 1; j < server->num_clients; j++) {
                server->clients[j - 1] = server->clients[j];
            }
            server->num_clients--;
            break;
        }
    }
}

void broadcast_message(struct server *server, int sock, char *message) {
    for (int i = 0; i < server->num_clients; i++) {
        if (server->clients[i].sock != sock) {
            send(server->clients[i].sock, message, strlen(message), 0);
        }
    }
}

void handle_client(struct server *server, int sock) {
    char buffer[1024];

    while (1) {
        int n = recv(sock, buffer, sizeof(buffer), 0);
        if (n <= 0) {
            remove_client(server, sock);
            break;
        }

        buffer[n] = '\0';

        if (strncmp(buffer, "/name ", 6) == 0) {
            char *name = buffer + 6;
            add_client(server, sock, name);
            sprintf(buffer, "Welcome to the server, %s!\n", name);
            send(sock, buffer, strlen(buffer), 0);
            broadcast_message(server, sock, buffer);
        } else {
            broadcast_message(server, sock, buffer);
        }
    }
}

int main() {
    struct server server;

    init_server(&server);

    while (1) {
        int sock = accept(server.sock, NULL, NULL);
        if (sock == -1) {
            perror("accept");
            continue;
        }

        handle_client(&server, sock);
    }

    return 0;
}