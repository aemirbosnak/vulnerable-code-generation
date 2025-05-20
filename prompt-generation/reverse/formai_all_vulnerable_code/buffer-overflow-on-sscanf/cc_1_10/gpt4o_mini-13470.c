//GPT-4o-mini DATASET v1.0 Category: Simple Web Server ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <fcntl.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define RESPONSE_SIZE 4096

void serve_file(int client_socket, const char *filename) {
    char buffer[BUFFER_SIZE];
    FILE *file = fopen(filename, "rb");
    
    if (file == NULL) {
        const char *error_response = "HTTP/1.1 404 Not Found\r\n\r\n";
        send(client_socket, error_response, strlen(error_response), 0);
        return;
    }

    // Send 200 OK Response Header
    const char *header = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
    send(client_socket, header, strlen(header), 0);

    // Read file and send content
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        send(client_socket, buffer, strlen(buffer), 0);
    }

    fclose(file);
}

void handle_client(int client_socket) {
    char request[BUFFER_SIZE];
    int bytes_received = recv(client_socket, request, sizeof(request) - 1, 0);
    if (bytes_received <= 0) {
        close(client_socket);
        return;
    }
    request[bytes_received] = '\0';

    // Get the requested file from the request
    char method[BUFFER_SIZE], uri[BUFFER_SIZE], version[BUFFER_SIZE];
    sscanf(request, "%s %s %s", method, uri, version);

    if (strcmp(method, "GET") == 0) {
        // Treat the URI as a file path
        // If path is just '/', serve index.html
        if (strcmp(uri, "/") == 0) {
            serve_file(client_socket, "index.html");
        } else {
            serve_file(client_socket, uri + 1);  // Skip the '/'
        }
    }

    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_size = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        close(server_socket);
        return 1;
    }

    if (listen(server_socket, 10) < 0) {
        perror("Listening failed");
        close(server_socket);
        return 1;
    }
    
    printf("Server running on http://localhost:%d/\n", PORT);

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_size);
        if (client_socket < 0) {
            perror("Failed to accept connection");
            continue;
        }
        
        // Fork the process to handle the client
        if (fork() == 0) {
            close(server_socket); // Close the listening socket in the child process
            handle_client(client_socket);
            exit(0);
        }
        
        // Parent process can close the client socket
        close(client_socket);
        
        // Clean up finished child processes
        while (waitpid(-1, NULL, WNOHANG) > 0);
    }

    close(server_socket);
    return 0;
}