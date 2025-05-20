//LLAMA2-13B DATASET v1.0 Category: Client Server Application ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

// Structure to store client information
typedef struct {
    int sock;        // Socket descriptor
    char name[50];  // Client name
    char message[100];  // Client message
} client_t;

// Array to store all connected clients
client_t clients[10];

// Function to handle incoming connections
void handle_connection(int sock) {
    char name[50];
    char message[100];

    // Get client name and message
    recv(sock, name, 50, 0);
    recv(sock, message, 100, 0);

    // Add client to list of connected clients
    clients[sizeof(clients) - 1] = (client_t) {
        sock,
        name,
        message
    };
}

// Function to send message to all connected clients
void send_message_to_all(char *message) {
    int i;

    for (i = 0; i < sizeof(clients) - 1; i++) {
        send(clients[i].sock, message, strlen(message), 0);
    }
}

int main() {
    int sock;
    struct sockaddr_in server_addr;

    // Create server socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // Bind server socket to address and port
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("Listening failed");
        exit(1);
    }

    // Accept incoming connection
    sock = accept(sock, NULL, NULL);
    if (sock < 0) {
        perror("Accept failed");
        exit(1);
    }

    // Handle incoming connection
    handle_connection(sock);

    // Send message to all connected clients
    char message[] = "Hello, world!";
    send_message_to_all(message);

    // Close server socket
    close(sock);

    return 0;
}