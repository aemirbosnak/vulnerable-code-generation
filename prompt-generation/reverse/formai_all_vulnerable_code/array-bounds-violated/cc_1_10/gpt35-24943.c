//FormAI DATASET v1.0 Category: Networking ; Style: lively
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int server_sock, client_sock, read_size;
    struct sockaddr_in server_addr, client_addr;
    char client_message[2000];

    // Create server socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        printf("Error creating server socket\n");
        return 1;
    }

    printf("Server socket created\n");

    // Set server address and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8888);

    // Bind server socket to address and port
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding server socket\n");
        return 1;
    }

    printf("Server socket bound to port 8888\n");

    // Listen for incoming connections
    listen(server_sock, 3);

    printf("Waiting for incoming connections...\n");

    // Accept incoming connection
    int client_addr_len = sizeof(client_addr);
    client_sock = accept(server_sock, (struct sockaddr *)&client_addr, (socklen_t*)&client_addr_len);
    if (client_sock < 0) {
        printf("Error accepting incoming connection\n");
        return 1;
    }

    printf("Incoming connection accepted\n");

    // Send welcome message to client
    char *welcome_message = "Welcome to my server!\n";
    write(client_sock, welcome_message, strlen(welcome_message));

    // Receive message from client
    while ((read_size = recv(client_sock, client_message, 2000, 0)) > 0) {
        // Add null terminator to received message
        client_message[read_size] = '\0';

        // Print received message
        printf("Received message from client: %s", client_message);

        // Send acknowledgment message to client
        char *ack_message = "Message received by server\n";
        write(client_sock, ack_message, strlen(ack_message));

        // Clear message buffer
        memset(client_message, 0, sizeof(client_message));
    }

    if (read_size == 0) {
        printf("Client disconnected\n");
    } else {
        printf("Error receiving message\n");
    }

    close(client_sock);
    close(server_sock);

    return 0;
}