//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int read_size;

    // Receive data from the client
    if ((read_size = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0';  // Null-terminate the received string
        printf("Received: %s\n", buffer);

        // Echo back the message to the client
        send(client_socket, buffer, read_size, 0);
        printf("Sent: %s\n", buffer);
    }

    // Close the client socket
    close(client_socket);
}

void accept_clients(int server_socket) {
    struct sockaddr_in client;
    int client_socket;
    socklen_t client_struct_length = sizeof(client);

    // Accepting a new client connection
    client_socket = accept(server_socket, (struct sockaddr *)&client, &client_struct_length);
    if (client_socket < 0) {
        perror("Accept failed");
        return;
    }
    printf("Client connected: %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

    // Handle the client in a recursive manner
    handle_client(client_socket);
    
    // Recursively call accept_clients to handle next client
    accept_clients(server_socket);
}

int main() {
    int server_socket;
    struct sockaddr_in server;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Could not create socket");
        return 1;
    }
    printf("Socket created.\n");

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Bind failed");
        return 1;
    }
    printf("Bind done.\n");

    // Listen for incoming connections
    listen(server_socket, 3);
    printf("Waiting for incoming connections...\n");

    // Start accepting clients
    accept_clients(server_socket);

    // Close the server socket (this line will actually never be reached due to recursion)
    close(server_socket);
    return 0;
}