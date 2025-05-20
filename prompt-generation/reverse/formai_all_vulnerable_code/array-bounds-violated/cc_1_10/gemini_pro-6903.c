//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 10
#define MAX_DATA 1024

struct client {
    int sockfd;
    char username[256];
};

struct server {
    int sockfd;
    struct sockaddr_in addr;
    struct client clients[MAX_CLIENTS];
    int num_clients;
};

void send_to_all(struct server *server, char *data) {
    for (int i = 0; i < server->num_clients; i++) {
        send(server->clients[i].sockfd, data, strlen(data), 0);
    }
}

void handle_client(struct server *server, int client_sockfd) {
    char data[MAX_DATA];
    while (1) {
        int n = recv(client_sockfd, data, MAX_DATA, 0);
        if (n <= 0) {
            break;
        }
        data[n] = '\0';
        send_to_all(server, data);
    }
    close(client_sockfd);
}

int main() {
    struct server server;
    server.sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server.sockfd < 0) {
        perror("socket");
        exit(1);
    }
    memset(&server.addr, 0, sizeof(server.addr));
    server.addr.sin_family = AF_INET;
    server.addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server.addr.sin_port = htons(8080);
    if (bind(server.sockfd, (struct sockaddr *)&server.addr, sizeof(server.addr)) < 0) {
        perror("bind");
        exit(1);
    }
    if (listen(server.sockfd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(1);
    }
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sockfd = accept(server.sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sockfd < 0) {
            perror("accept");
            continue;
        }
        if (server.num_clients >= MAX_CLIENTS) {
            close(client_sockfd);
            continue;
        }
        server.clients[server.num_clients].sockfd = client_sockfd;
        server.num_clients++;
        handle_client(&server, client_sockfd);
    }
    close(server.sockfd);
    return 0;
}