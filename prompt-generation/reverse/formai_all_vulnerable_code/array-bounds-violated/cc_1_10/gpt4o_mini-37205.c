//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null terminate the string
        printf("Received message: %s\n", buffer);
        // Basic firewall logic: block messages containing "FORBIDDEN"
        if (strstr(buffer, "FORBIDDEN") != NULL) {
            const char *message = "Message contains forbidden content.\n";
            send(client_socket, message, strlen(message), 0);
        } else {
            const char *ack = "Message received and allowed.\n";
            send(client_socket, ack, strlen(ack), 0);
        }
    }

    if (bytes_received == 0) {
        printf("Client disconnected.\n");
    } else {
        perror("recv error");
    }

    close(client_socket);
}

void start_server() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    // Accept clients in an infinite loop
    while (1) {
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len)) < 0) {
            perror("Accept failed");
            continue;
        }
        
        printf("New connection accepted.\n");
        if (fork() == 0) {
            close(server_socket);  // Close server socket in child process
            handle_client(client_socket);
            exit(0);
        }
        close(client_socket);  // Close client socket in parent process
    }

    close(server_socket);
}

int main() {
    start_server();
    return 0;
}