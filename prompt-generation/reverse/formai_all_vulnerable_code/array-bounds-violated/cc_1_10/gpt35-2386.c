//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Ada Lovelace
// Include necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Define server IP address and port number
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 80

// Define HTTP request message
#define REQUEST_MSG "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n"

int main() {
    // Create socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    // Check if socket was created successfully
    if (client_socket < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }
    
    // Define server address structure
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_address.sin_port = htons(SERVER_PORT);
    
    // Connect to server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection to server failed");
        return EXIT_FAILURE;
    }
    
    // Send HTTP request message
    if (send(client_socket, REQUEST_MSG, strlen(REQUEST_MSG), 0) != strlen(REQUEST_MSG)) {
        perror("Failed to send message to server");
        return EXIT_FAILURE;
    }
    
    // Receive HTTP response message
    char buffer[BUFSIZ];
    int bytes_received = 0;
    
    while ((bytes_received = recv(client_socket, buffer, BUFSIZ-1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }
    
    // Close socket
    close(client_socket);
    
    return EXIT_SUCCESS;
}