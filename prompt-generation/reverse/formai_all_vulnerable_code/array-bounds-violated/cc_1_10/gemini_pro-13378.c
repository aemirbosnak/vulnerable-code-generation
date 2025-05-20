//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 10
#define MAX_MESSAGE_LENGTH 1024

typedef struct {
    int sockfd;
    char username[32];
} client_t;

client_t clients[MAX_CLIENTS];
int num_clients = 0;

void send_message(char *message, int sender_sockfd) {
    for (int i = 0; i < num_clients; i++) {
        if (clients[i].sockfd != sender_sockfd) {
            send(clients[i].sockfd, message, strlen(message), 0);
        }
    }
}

void handle_client(int sockfd) {
    char buffer[MAX_MESSAGE_LENGTH];
    char *message;

    while (1) {
        memset(buffer, 0, MAX_MESSAGE_LENGTH);
        if (recv(sockfd, buffer, MAX_MESSAGE_LENGTH, 0) <= 0) {
            printf("Client disconnected.\n");
            break;
        }

        message = strtok(buffer, "\n");
        if (strcmp(message, "/quit") == 0) {
            printf("Client %s has left the realm.\n", clients[sockfd].username);
            break;
        } else if (strcmp(message, "/join") == 0) {
            message = strtok(NULL, "\n");
            strcpy(clients[sockfd].username, message);
            printf("Client %s has joined the realm.\n", clients[sockfd].username);
        } else {
            printf("Message from client %s: %s\n", clients[sockfd].username, message);
            send_message(message, sockfd);
        }
    }

    close(sockfd);
    clients[sockfd].sockfd = -1;
    num_clients--;
}

int main() {
    int server_sockfd, client_sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;

    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd == -1) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(1234);

    if (bind(server_sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(server_sockfd, 5) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Server is listening on port 1234.\n");

    while (1) {
        client_addr_len = sizeof(client_addr);
        client_sockfd = accept(server_sockfd, (struct sockaddr *) &client_addr, &client_addr_len);
        if (client_sockfd == -1) {
            perror("accept");
            continue;
        }

        if (num_clients >= MAX_CLIENTS) {
            printf("Max clients reached, rejecting connection.\n");
            close(client_sockfd);
        } else {
            clients[client_sockfd].sockfd = client_sockfd;
            num_clients++;
            handle_client(client_sockfd);
        }
    }

    close(server_sockfd);
    return 0;
}