//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: Cryptic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_CLIENTS 10
#define MAX_MSG_LEN 1024

typedef struct client_info {
    int sockfd;
    char name[32];
} client_info;

client_info clients[MAX_CLIENTS];
int num_clients = 0;

void broadcast_msg(char *msg, int sender_sockfd) {
    for (int i = 0; i < num_clients; i++) {
        if (clients[i].sockfd != sender_sockfd) {
            send(clients[i].sockfd, msg, strlen(msg), 0);
        }
    }
}

void handle_client(int client_sockfd) {
    char msg[MAX_MSG_LEN];
    while (1) {
        int n = recv(client_sockfd, msg, MAX_MSG_LEN, 0);
        if (n <= 0) {
            printf("Client disconnected: %d\n", client_sockfd);
            close(client_sockfd);
            num_clients--;
            break;
        }
        msg[n] = '\0';
        printf("Received message from client %d: %s\n", client_sockfd, msg);
        broadcast_msg(msg, client_sockfd);
    }
}

int main() {
    int server_sockfd, client_sockfd, portno;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;

    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd < 0) {
        perror("socket");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(9000);

    if (bind(server_sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        return 1;
    }

    if (listen(server_sockfd, MAX_CLIENTS) < 0) {
        perror("listen");
        return 1;
    }

    while (1) {
        client_len = sizeof(client_addr);
        client_sockfd = accept(server_sockfd, (struct sockaddr *) &client_addr, &client_len);
        if (client_sockfd < 0) {
            perror("accept");
            continue;
        }

        if (num_clients >= MAX_CLIENTS) {
            printf("Maximum number of clients reached\n");
            close(client_sockfd);
            continue;
        }

        char name[32];
        int n = recv(client_sockfd, name, 32, 0);
        if (n <= 0) {
            printf("Client failed to send name\n");
            close(client_sockfd);
            continue;
        }
        name[n] = '\0';

        strcpy(clients[num_clients].name, name);
        clients[num_clients].sockfd = client_sockfd;
        num_clients++;

        printf("New client connected: %s (%d)\n", name, client_sockfd);
        handle_client(client_sockfd);
        printf("Client disconnected: %s (%d)\n", name, client_sockfd);
    }

    close(server_sockfd);
    return 0;
}