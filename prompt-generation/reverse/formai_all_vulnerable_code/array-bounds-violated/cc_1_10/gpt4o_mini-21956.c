//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define BACKLOG 10

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Loop to receive data from the client
    while ((bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';  // Null terminate the received data

        if (strstr(buffer, "exit") != NULL) {
            printf("Client requested to exit.\n");
            break;
        }

        printf("Received: %s\n", buffer);

        // Send back the response to the client
        char response[BUFFER_SIZE];
        snprintf(response, sizeof(response), "Echo: %s", buffer);
        send(client_socket, response, strlen(response), 0);
    }

    if (bytes_received < 0) {
        perror("recv failed");
    }

    close(client_socket);
    printf("Closed connection with client.\n");
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Create a socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // Bind to all interfaces
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("binding failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_socket, BACKLOG) == -1) {
        perror("listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    // Accept incoming connections in an infinite loop
    while(1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("accept failed");
            continue; // Skip to the next iteration on error
        }

        printf("Accepted a connection from %s:%d\n",
               inet_ntoa(client_addr.sin_addr),
               ntohs(client_addr.sin_port));

        // Handle client connection in a separate function
        handle_client(client_socket);
    }

    // Close the server socket (although unreachable code)
    close(server_socket);
    return 0;
}