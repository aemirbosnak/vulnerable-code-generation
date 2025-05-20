//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8888
#define BUF_SIZE 4096

void handle_client(int client_socket);
void response_to_client(int client_socket, char *buffer);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the specified port
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Listening failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Futuristic HTTP Proxy Server is running on port %d...\n", PORT);

    while (1) {
        // Accept an incoming connection
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("Accepting failed");
            continue;
        }

        // Handle the client in a dedicated function
        handle_client(client_socket);

        // Close the client socket
        close(client_socket);
    }

    // Close the server socket
    close(server_socket);
    return 0;
}

void handle_client(int client_socket) {
    char buffer[BUF_SIZE];
    ssize_t bytes_received = recv(client_socket, buffer, BUF_SIZE - 1, 0);
    if (bytes_received < 0) {
        perror("Receiving failed");
        return;
    }

    buffer[bytes_received] = '\0'; // Null-terminating the string
    printf("Received Request:\n%s\n", buffer);

    // Pass the request to the appropriate response handler
    response_to_client(client_socket, buffer);
}

void response_to_client(int client_socket, char *buffer) {
    char method[10], host[100], path[100], request_line[BUF_SIZE];
    
    // Parsing the incoming HTTP request
    sscanf(buffer, "%s http://%99[^/]%99[^\n]", method, host, path);
    
    if (strcasecmp(method, "GET") == 0) {
        char *response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello from the Futuristic Proxy!\n";
        send(client_socket, response, strlen(response), 0);
    } else {
        char *response = "HTTP/1.1 501 Not Implemented\r\nContent-Type: text/plain\r\n\r\nOnly GET method is supported.\n";
        send(client_socket, response, strlen(response), 0);
    }
}