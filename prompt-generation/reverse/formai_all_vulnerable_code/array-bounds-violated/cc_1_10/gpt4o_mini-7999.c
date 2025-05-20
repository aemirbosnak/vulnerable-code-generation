//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void error_handling(const char *message) {
    perror(message);
    exit(1);
}

void handle_request(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Receive message from the client
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        error_handling("recv() error");
    }
    buffer[bytes_received] = '\0'; // Null-terminate the received message

    printf("Received from client: %s\n", buffer);

    // Simple response logic (Transforming message to uppercase)
    for (int i = 0; i < bytes_received; i++) {
        buffer[i] = toupper(buffer[i]);
    }

    // Send transformed message back to the client
    send(client_socket, buffer, bytes_received, 0);
    printf("Sent back to client: %s\n", buffer);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_size;

    // Creating socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        error_handling("Socket creation error!");
    }
    printf("Socket created successfully.\n");

    // Setting up the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    // Binding the socket
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        error_handling("Binding error!");
    }
    printf("Bind successful on port %d.\n", PORT);

    // Listening for incoming connections
    if (listen(server_socket, 5) < 0) {
        error_handling("Listen error!");
    }
    printf("Server listening on port %d...\n", PORT);

    // Accepting connections in a loop
    while (1) {
        client_addr_size = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_size);
        if (client_socket < 0) {
            error_handling("Accept error!");
        }
        printf("Client connected.\n");

        // Handle client request
        handle_request(client_socket);

        // Close the connection
        close(client_socket);
        printf("Client disconnected.\n");
    }

    // Close the server socket
    close(server_socket);
    return 0;
}