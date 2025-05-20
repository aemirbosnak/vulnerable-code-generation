//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

// Structure to store client information
struct client {
    int sock;
    char ip_address[INET_ADDRSTRLEN];
    char username[50];
};

// Function to handle client connection
void handle_client(int sock) {
    char buffer[256];
    struct client client;

    // Receive client's IP address and username
    recvfrom(sock, buffer, 256, 0, (struct sockaddr *)NULL, NULL);
    sscanf(buffer, "%s %s", client.ip_address, client.username);

    // Print received IP address and username
    printf("Client connected from IP: %s, username: %s\n", client.ip_address, client.username);

    // Accept or reject client based on configured rules
    if (strcmp(client.username, "admin") == 0) {
        // Accept client if username is "admin"
        printf("Accepting client with username: %s\n", client.username);
    } else {
        // Reject client if username is not "admin"
        printf("Rejecting client with username: %s\n", client.username);
        close(sock);
    }
}

// Function to handle server
void handle_server() {
    int sock;
    struct client client;

    // Create server socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Bind server socket to configured port
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("binding failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming client connections
    if (listen(sock, 3) < 0) {
        perror("listening failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming client connections
    while (1) {
        client.sock = accept(sock, (struct sockaddr *)NULL, NULL);
        handle_client(client.sock);
    }

    close(sock);
}

int main() {
    // Initialize server socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server socket to listen on configured port
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("binding failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming client connections
    if (listen(sock, 3) < 0) {
        perror("listening failed");
        exit(EXIT_FAILURE);
    }

    // Start handling incoming client connections
    handle_server();

    return 0;
}