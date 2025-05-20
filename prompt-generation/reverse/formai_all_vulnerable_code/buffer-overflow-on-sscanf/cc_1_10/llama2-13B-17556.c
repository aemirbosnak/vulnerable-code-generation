//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_LENGTH 1024
#define MAX_PACKET_LENGTH 1024

// Structure to hold client information
struct client_info {
    int sock;
    char name[MAX_CLIENT_LENGTH];
    char message[MAX_PACKET_LENGTH];
};

// Function to handle client connections
void handle_client(int sock) {
    struct client_info *client;
    char buffer[MAX_PACKET_LENGTH];

    // Read client name and message
    read(sock, buffer, MAX_PACKET_LENGTH);
    client = (struct client_info *)malloc(sizeof(struct client_info));
    sscanf(buffer, "%s %s", client->name, client->message);

    // Print client information
    printf("Client connected: %s says %s\n", client->name, client->message);

    // Send response to client
    char *response = "Hello, client!";
    send(sock, response, strlen(response), 0);

    // Free client memory
    free(client);
}

// Function to handle server socket
void handle_server() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(1234),
        .sin_addr.s_addr = INADDR_ANY
    };

    // Bind server socket to address and port
    bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Listen for incoming connections
    listen(sock, 3);

    // Accept incoming connection
    int client_sock = accept(sock, NULL, NULL);

    // Handle client connection
    handle_client(client_sock);

    // Close client socket
    close(client_sock);
}

int main() {
    // Create server socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    // Set address and port for server
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(1234),
        .sin_addr.s_addr = INADDR_ANY
    };

    // Bind server socket to address and port
    bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Listen for incoming connections
    listen(sock, 3);

    // Handle server socket
    handle_server();

    // Close server socket
    close(sock);

    return 0;
}