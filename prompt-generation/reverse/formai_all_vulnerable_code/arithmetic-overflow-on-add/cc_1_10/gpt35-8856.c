//FormAI DATASET v1.0 Category: Client Server Application ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Constants for setting up the server and client sockets
#define SERVER_ADDRESS "127.0.0.1"
#define SERVER_PORT 8888
#define MAX_CONNECTIONS 5
#define BUFF_SIZE 1024

// Struct to hold client information
struct client_info {
    int sockfd;
    char *name;
};

// Function to handle incoming client connections
void handle_client(struct client_info *client) {
    char buffer[BUFF_SIZE];
    int len;

    printf("New connection established. Client name: %s\n", client->name);

    while (true) {
        // Clear the buffer
        memset(buffer, 0, BUFF_SIZE);

        // Read from the socket
        len = recv(client->sockfd, buffer, BUFF_SIZE, 0);

        if (len > 0) {
            printf("%s: %s", client->name, buffer);
        } else if (len == 0) {
            // Client disconnected
            printf("Client disconnected: %s\n", client->name);
            break;
        } else {
            // Error reading from socket
            printf("Error reading from socket: %s\n", strerror(errno));
            break;
        }
    }

    // Close the socket
    close(client->sockfd);
    free(client->name);
}

// Main function
int main() {
    int server_sockfd, client_sockfd;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFF_SIZE];
    int len, i;
    struct client_info clients[MAX_CONNECTIONS];

    // Create the server socket
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd < 0) {
        printf("Error creating server socket: %s\n", strerror(errno));
        exit(1);
    }

    // Set up the server address struct
    memset(&server_address, 0, sizeof(struct sockaddr_in));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);
    server_address.sin_port = htons(SERVER_PORT);

    // Bind the socket to the server address
    if (bind(server_sockfd, (const struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error binding server socket: %s\n", strerror(errno));
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_sockfd, MAX_CONNECTIONS) < 0) {
        printf("Error listening for incoming connections: %s\n", strerror(errno));
        exit(1);
    }

    // Accept incoming connections and handle them
    while (true) {
        // Accept the incoming connection
        len = sizeof(struct sockaddr_in);
        client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, (socklen_t *)&len);

        if (client_sockfd < 0) {
            printf("Error accepting incoming connection: %s\n", strerror(errno));
            continue;
        }

        // Get the client name
        len = recv(client_sockfd, buffer, BUFF_SIZE, 0);
        if (len > 0) {
            buffer[len] = '\0';
            clients[i].name = strdup(buffer);
            clients[i].sockfd = client_sockfd;

            // Spawn a new thread to handle the client connection
            pthread_t tid;
            pthread_create(&tid, NULL, handle_client, &clients[i]);

            i++;
        } else {
            // Error reading client name
            printf("Error reading client name: %s\n", strerror(errno));
            close(client_sockfd);
        }
    }

    // Close the server socket
    close(server_sockfd);

    return 0;
}