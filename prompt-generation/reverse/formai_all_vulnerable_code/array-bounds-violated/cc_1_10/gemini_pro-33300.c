//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define MAX_MSG_LEN 1024

typedef struct {
    int sockfd;
    char username[32];
} client_t;

typedef struct {
    int num_clients;
    client_t clients[MAX_CLIENTS];
} server_t;

server_t server;

void *handle_client(void *arg) {
    client_t *client = (client_t *)arg;
    char buf[MAX_MSG_LEN];
    int len;

    while ((len = recv(client->sockfd, buf, MAX_MSG_LEN, 0)) > 0) {
        buf[len] = '\0';
        printf("[%s]: %s\n", client->username, buf);

        // Send the message to all other clients
        for (int i = 0; i < server.num_clients; i++) {
            if (server.clients[i].sockfd != client->sockfd) {
                send(server.clients[i].sockfd, buf, len, 0);
            }
        }
    }

    // Client has disconnected
    printf("[%s] has disconnected\n", client->username);
    close(client->sockfd);
    server.num_clients--;

    pthread_exit(NULL);
}

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    pthread_t thread;

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Initialize the server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(sockfd, MAX_CLIENTS) < 0) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Initialize the server
    server.num_clients = 0;

    // Main loop: accept new connections and handle them in separate threads
    while (1) {
        // Accept a new connection
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("accept");
            continue;
        }

        // Get the username of the new client
        char username[32];
        recv(newsockfd, username, 32, 0);

        // Add the new client to the server
        client_t client = {
            .sockfd = newsockfd,
            .username = username,
        };
        server.clients[server.num_clients++] = client;

        // Create a new thread to handle the client
        pthread_create(&thread, NULL, handle_client, (void *)&client);
    }

    // Close the server socket
    close(sockfd);

    return EXIT_SUCCESS;
}