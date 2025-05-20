//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_CONNECTIONS 1024
#define BUFFER_SIZE 2048

// Structure to hold client info
struct Client {
    int sock;
    struct sockaddr_in address;
    char request[BUFFER_SIZE];
    int pos;
};

// Structure to hold server info
struct Server {
    int sock;
    struct sockaddr_in address;
};

// Accept and process incoming client requests
void handle_client(struct Client *client) {
    // Create server socket
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Error creating server socket");
        return;
    }

    // Connect to server
    if (connect(server_sock, (struct sockaddr *)&client->address,
                sizeof(client->address)) < 0) {
        perror("Error connecting to server");
        close(server_sock);
        return;
    }

    // Send request to server
    if (send(server_sock, client->request, client->pos, 0) != client->pos) {
        perror("Error sending request to server");
        close(server_sock);
        return;
    }

    // Receive response from server
    char buffer[BUFFER_SIZE];
    int bytes_received;
    while ((bytes_received = recv(server_sock, buffer, BUFFER_SIZE, 0)) > 0) {
        // Send response to client
        if (send(client->sock, buffer, bytes_received, 0) != bytes_received) {
            perror("Error sending response to client");
            break;
        }
    }

    // Close connections
    close(server_sock);
    close(client->sock);
}

// Entry point
int main(int argc, char *argv[]) {
    // Create proxy socket
    int proxy_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_sock < 0) {
        perror("Error creating proxy socket");
        return EXIT_FAILURE;
    }

    // Set socket options
    int option = 1;
    if (setsockopt(proxy_sock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option)) == -1) {
        perror("Error setting socket options");
        close(proxy_sock);
        return EXIT_FAILURE;
    }

    // Bind to port
    struct sockaddr_in proxy_address = {
        .sin_family = AF_INET,
        .sin_port = htons(8080),
        .sin_addr = INADDR_ANY
    };
    if (bind(proxy_sock, (struct sockaddr *)&proxy_address, sizeof(proxy_address)) < 0) {
        perror("Error binding to port");
        close(proxy_sock);
        return EXIT_FAILURE;
    }

    // Listen for connections
    if (listen(proxy_sock, MAX_CONNECTIONS) < 0) {
        perror("Error listening for connections");
        close(proxy_sock);
        return EXIT_FAILURE;
    }

    printf("Proxy listening on port %d\n", ntohs(proxy_address.sin_port));

    // Keep accepting connections
    while (1) {
        struct Client *client = malloc(sizeof(struct Client));
        if (!client) {
            perror("Error allocating memory");
            break;
        }

        // Accept client connection
        socklen_t client_addr_size = sizeof(client->address);
        client->sock = accept(proxy_sock, (struct sockaddr *)&client->address, &client_addr_size);
        if (client->sock < 0) {
            perror("Error accepting client connection");
            free(client);
            break;
        }

        // Receive request from client
        int bytes_received;
        while ((bytes_received = recv(client->sock, client->request + client->pos, BUFFER_SIZE - client->pos, 0)) > 0) {
            client->pos += bytes_received;

            // Check if request has ended
            if (strstr(client->request, "\r\n\r\n")) {
                handle_client(client);
                break;
            }

            // Check if request buffer is full
            if (client->pos == BUFFER_SIZE) {
                perror("Error receiving client request");
                close(client->sock);
                break;
            }
        }

        // Free client memory
        free(client);
    }

    // Close proxy socket
    close(proxy_sock);

    return EXIT_SUCCESS;
}