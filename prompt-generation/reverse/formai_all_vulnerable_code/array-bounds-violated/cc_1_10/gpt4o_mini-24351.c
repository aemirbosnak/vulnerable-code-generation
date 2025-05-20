//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_BUFFER 1024

void handle_client(int client_socket) {
    char buffer[MAX_BUFFER];
    int read_size;

    // Welcome message
    const char *welcome_msg = "🎉 Welcome to the Happy Server! 🎉\n";
    send(client_socket, welcome_msg, strlen(welcome_msg), 0);

    // Main loop to chat with the client
    while ((read_size = recv(client_socket, buffer, MAX_BUFFER - 1, 0)) > 0) {
        buffer[read_size] = '\0'; // Null terminate the received string

        // Log the received message with a cheerful response
        printf("Client says: %s\n", buffer);
        const char *response_msg = "😊 You said something amazing! Keep it up! 😊\n";
        send(client_socket, response_msg, strlen(response_msg), 0);
    }

    // Close the connection
    if (read_size == 0) {
        printf("Client disconnected. Goodbye! 👋\n");
    } else {
        perror("recv failed");
    }
    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Creating socket file descriptor
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Setting the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Binding the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    
    // Starting to listen
    if (listen(server_socket, 3) < 0) {
        perror("listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    printf("🌈 The Happy Server is running on port %d! 🌈\n", PORT);
    printf("🎈 Waiting for clients... 🎈\n");

    // Accept a client connection in a loop
    while ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len)) >= 0) {
        printf("🦄 A new client connected! 🦄\n");
        // Handle the client in a new function
        handle_client(client_socket);
    }

    if (client_socket < 0) {
        perror("accept failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Close the server socket
    close(server_socket);
    return 0;
}