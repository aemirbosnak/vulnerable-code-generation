//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUF_SIZE 1024
#define BLOCKED_IP "192.168.1.100"

int is_ip_blocked(const char *ip) {
    return strcmp(ip, BLOCKED_IP) == 0;
}

void handle_client(int client_socket) {
    char buffer[BUF_SIZE];
    ssize_t bytes_received;

    // Receive IP address from client
    bytes_received = recv(client_socket, buffer, BUF_SIZE, 0);
    if (bytes_received < 0) {
        perror("Error receiving data");
        close(client_socket);
        return;
    }

    // Null-terminate the received data
    buffer[bytes_received] = '\0';
    printf("Received connection from: %s\n", buffer);

    // Check if IP is blocked
    if (is_ip_blocked(buffer)) {
        printf("Connection from %s is blocked!\n", buffer);
        const char *reply_blocked = "Your IP is blocked.";
        send(client_socket, reply_blocked, strlen(reply_blocked), 0);
    } else {
        printf("Connection from %s is allowed.\n", buffer);
        const char *reply_allowed = "Welcome! Your IP is allowed.";
        send(client_socket, reply_allowed, strlen(reply_allowed), 0);
    }

    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setup server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Firewall listening on port %d...\n", PORT);

    while (1) {
        // Accept incoming connections
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue; // Continue accepting other connections
        }

        // Retrieve IP address
        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, sizeof(client_ip));
        printf("Connection accepted from %s\n", client_ip);

        // Handle the client in a separate function
        handle_client(client_socket);
    }

    close(server_socket);
    return 0;
}