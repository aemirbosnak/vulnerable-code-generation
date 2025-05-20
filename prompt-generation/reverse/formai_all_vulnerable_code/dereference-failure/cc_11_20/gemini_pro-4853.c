//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 100
#define MAX_MSG_LEN 1024

struct client {
    int sockfd;
    char name[MAX_MSG_LEN];
    pthread_t thread;
};

// List of connected clients
struct client clients[MAX_CLIENTS];

// Mutex to protect the client list
pthread_mutex_t client_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to handle a client connection
void *client_handler(void *arg) {
    // Get the client struct
    struct client *client = (struct client *)arg;

    // Receive the client's name
    char name[MAX_MSG_LEN] = {0};
    if (recv(client->sockfd, name, MAX_MSG_LEN, 0) < 0) {
        perror("recv");
        goto error;
    }

    // Add the client to the client list
    pthread_mutex_lock(&client_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].sockfd == 0) {
            clients[i] = *client;
            break;
        }
    }
    pthread_mutex_unlock(&client_mutex);

    // Send a welcome message to the client
    char welcome[] = "Welcome to the chat server!\n";
    if (send(client->sockfd, welcome, strlen(welcome), 0) < 0) {
        perror("send");
        goto error;
    }

    // Main loop: receive and broadcast messages
    while (1) {
        // Receive a message from the client
        char buffer[MAX_MSG_LEN] = {0};
        if (recv(client->sockfd, buffer, MAX_MSG_LEN, 0) < 0) {
            perror("recv");
            goto error;
        }

        // Check if the client is quitting
        if (strcmp(buffer, "/quit") == 0) {
            break;
        }

        // Broadcast the message to all other clients
        pthread_mutex_lock(&client_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].sockfd != client->sockfd && clients[i].sockfd != 0) {
                if (send(clients[i].sockfd, buffer, strlen(buffer), 0) < 0) {
                    perror("send");
                    goto error;
                }
            }
        }
        pthread_mutex_unlock(&client_mutex);
    }

error:
    // Remove the client from the client list
    pthread_mutex_lock(&client_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].sockfd == client->sockfd) {
            clients[i].sockfd = 0;
            break;
        }
    }
    pthread_mutex_unlock(&client_mutex);

    // Close the client's socket
    close(client->sockfd);

    // Free the client struct
    free(client);

    return NULL;
}

int main(int argc, char **argv) {
    // Create a server socket
    int serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd < 0) {
        perror("socket");
        return 1;
    }

    // Set the socket options
    int opt = 1;
    if (setsockopt(serverfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("setsockopt");
        return 1;
    }

    // Bind the socket to an address
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(8080),
    };
    if (bind(serverfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        return 1;
    }

    // Listen for incoming connections
    if (listen(serverfd, MAX_CLIENTS) < 0) {
        perror("listen");
        return 1;
    }

    // Main loop: accept and handle client connections
    while (1) {
        // Accept a client connection
        struct sockaddr_in client_addr = {0};
        socklen_t client_addr_len = sizeof(client_addr);
        int clientfd = accept(serverfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (clientfd < 0) {
            perror("accept");
            continue;
        }

        // Create a new client struct
        struct client *client = malloc(sizeof(struct client));
        client->sockfd = clientfd;

        // Create a new thread to handle the client connection
        if (pthread_create(&client->thread, NULL, client_handler, (void *)client) < 0) {
            perror("pthread_create");
            close(clientfd);
            free(client);
            continue;
        }
    }

    // Close the server socket
    close(serverfd);

    return 0;
}