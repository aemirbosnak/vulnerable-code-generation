//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/ip.h>
#include <errno.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;
    
    // receiving data from client
    bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        perror("recv failed");
        close(client_socket);
        return;
    }
    
    buffer[bytes_received] = '\0'; // null-terminate the received string
    printf("Received: %s\n", buffer);
    
    // Example of basic filtering
    if (strstr(buffer, "BLOCK_ME") != NULL) {
        const char *block_response = "You have been blocked!\n";
        send(client_socket, block_response, strlen(block_response), 0);
    } else {
        const char *allow_response = "Message received!\n";
        send(client_socket, allow_response, strlen(allow_response), 0);
    }

    close(client_socket);
}

void start_firewall() {
    int server_socket, client_socket, opt = 1;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    
    // Creating socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setting socket options
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Set socket options failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET; 
    server_addr.sin_addr.s_addr = INADDR_ANY; 
    server_addr.sin_port = htons(PORT);

    // Binding socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listening for clients
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Firewall listening on port %d...\n", PORT);

    while (1) {
        // Accepting client connections
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }

        printf("Client connected: %s\n", inet_ntoa(client_addr.sin_addr));
        
        // Handling the client connection in a separate function
        handle_client(client_socket);
    }

    // Closing server socket
    close(server_socket);
}

int main() {
    start_firewall();
    return 0;
}