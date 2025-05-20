//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 10
#define MAX_MSG_LEN 1024

struct client {
    int sockfd;
    char name[32];
    int is_active;
};

struct server {
    int sockfd;
    struct sockaddr_in addr;
    struct client clients[MAX_CLIENTS];
    int num_clients;
};

void init_server(struct server *server, int port) {
    // Create the socket
    server->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server->sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Set the socket options
    int opt = 1;
    if (setsockopt(server->sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) == -1) {
        perror("setsockopt");
        exit(1);
    }

    // Bind the socket to the address
    memset(&server->addr, 0, sizeof(server->addr));
    server->addr.sin_family = AF_INET;
    server->addr.sin_addr.s_addr = INADDR_ANY;
    server->addr.sin_port = htons(port);
    if (bind(server->sockfd, (struct sockaddr *)&server->addr, sizeof(server->addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for connections
    if (listen(server->sockfd, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(1);
    }
}

void accept_client(struct server *server) {
    // Accept the connection
    int new_sockfd = accept(server->sockfd, NULL, NULL);
    if (new_sockfd == -1) {
        perror("accept");
        return;
    }

    // Add the client to the list of clients
    struct client new_client;
    new_client.sockfd = new_sockfd;
    new_client.is_active = 1;
    server->clients[server->num_clients++] = new_client;

    // Send a welcome message to the client
    char *welcome_msg = "Welcome to the chat server!\n";
    if (send(new_sockfd, welcome_msg, strlen(welcome_msg), 0) == -1) {
        perror("send");
        return;
    }
}

void handle_client(struct server *server, struct client *client) {
    // Receive the message from the client
    char msg[MAX_MSG_LEN];
    int len = recv(client->sockfd, msg, MAX_MSG_LEN, 0);
    if (len == -1) {
        perror("recv");
        return;
    }
    msg[len] = '\0';

    // Check if the client is quitting
    if (strcmp(msg, "/quit") == 0) {
        client->is_active = 0;
        return;
    }

    // Broadcast the message to all other clients
    for (int i = 0; i < server->num_clients; i++) {
        struct client *other_client = &server->clients[i];
        if (other_client != client && other_client->is_active) {
            char send_msg[MAX_MSG_LEN];
            snprintf(send_msg, MAX_MSG_LEN, "%s: %s", client->name, msg);
            if (send(other_client->sockfd, send_msg, strlen(send_msg), 0) == -1) {
                perror("send");
                return;
            }
        }
    }
}

void run_server(struct server *server) {
    while (1) {
        // Accept any new clients
        accept_client(server);

        // Handle any messages from clients
        for (int i = 0; i < server->num_clients; i++) {
            struct client *client = &server->clients[i];
            if (client->is_active) {
                handle_client(server, client);
            }
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Create the server
    struct server server;
    init_server(&server, atoi(argv[1]));

    // Run the server
    run_server(&server);

    return 0;
}