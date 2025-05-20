//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 6666
#define MAX_CLIENTS 100

typedef struct client_data {
    int sockfd;
    char username[20];
} client_data;

int server_sockfd;
client_data clients[MAX_CLIENTS];
int num_clients = 0;

void* handle_client(void* arg) {
    client_data* client = (client_data*)arg;
    int sockfd = client->sockfd;
    char username[20];
    strcpy(username, client->username);

    while (1) {
        char buffer[256];
        int n = recv(sockfd, buffer, sizeof(buffer), 0);
        if (n <= 0) {
            printf("%s has left the chat.\n", username);
            for (int i = 0; i < num_clients; i++) {
                if (clients[i].sockfd == sockfd) {
                    clients[i] = clients[num_clients - 1];
                    num_clients--;
                    break;
                }
            }
            pthread_exit(NULL);
        } else {
            buffer[n] = '\0';
            printf("%s: %s\n", username, buffer);
            for (int i = 0; i < num_clients; i++) {
                if (clients[i].sockfd != sockfd) {
                    send(clients[i].sockfd, buffer, n, 0);
                }
            }
        }
    }
}

int main() {
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(server_sockfd, 100) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Avast! The server is now listening on port %d.\n", PORT);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sockfd = accept(server_sockfd, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_sockfd == -1) {
            perror("accept");
            exit(1);
        }

        char username[20];
        int n = recv(client_sockfd, username, sizeof(username), 0);
        if (n <= 0) {
            printf("The client did not provide a username.\n");
            close(client_sockfd);
            continue;
        } else {
            username[n] = '\0';
            printf("%s has joined the chat.\n", username);
        }

        client_data client;
        client.sockfd = client_sockfd;
        strcpy(client.username, username);

        clients[num_clients] = client;
        num_clients++;

        pthread_t thread;
        pthread_create(&thread, NULL, handle_client, &client);
    }

    close(server_sockfd);
    return 0;
}