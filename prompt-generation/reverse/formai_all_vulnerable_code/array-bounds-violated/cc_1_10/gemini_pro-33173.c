//GEMINI-pro DATASET v1.0 Category: Networking ; Style: high level of detail
// C program for client-server chat using sockets

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Constants
#define PORT 8080
#define MAX_LINE 1024

// Function to handle client requests
void handle_client(int sockfd) {
    char buffer[MAX_LINE];
    int n;

    // Receive message from client
    n = recv(sockfd, buffer, MAX_LINE, 0);
    if (n < 0) {
        perror("Error receiving message from client");
        close(sockfd);
        return;
    }

    // Process message
    buffer[n] = '\0';
    printf("Message received from client: %s\n", buffer);

    // Convert message to uppercase
    for (int i = 0; buffer[i] != '\0'; i++) {
        buffer[i] = toupper(buffer[i]);
    }

    // Send uppercase message back to client
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error sending message to client");
        close(sockfd);
        return;
    }

    // Close socket
    close(sockfd);
}

// Main function
int main() {
    int server_sockfd, client_sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;

    // Create server socket
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd < 0) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind server socket to address
    if (bind(server_sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding server socket to address");
        close(server_sockfd);
        exit(EXIT_FAILURE);
    }

    // Listen for client connections
    if (listen(server_sockfd, 5) < 0) {
        perror("Error listening for client connections");
        close(server_sockfd);
        exit(EXIT_FAILURE);
    }

    // Accept client connection
    client_addr_len = sizeof(client_addr);
    client_sockfd = accept(server_sockfd, (struct sockaddr *) &client_addr, &client_addr_len);
    if (client_sockfd < 0) {
        perror("Error accepting client connection");
        close(server_sockfd);
        exit(EXIT_FAILURE);
    }

    // Handle client requests
    handle_client(client_sockfd);

    // Close server socket
    close(server_sockfd);

    return EXIT_SUCCESS;
}