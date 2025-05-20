//GPT-4o-mini DATASET v1.0 Category: Simple Web Server ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void respond(int client_socket, const char *status, const char *content_type, const char *body) {
    char response[BUFFER_SIZE];
    int n;

    n = snprintf(response, sizeof(response),
                 "HTTP/1.1 %s\r\n"
                 "Content-Type: %s\r\n"
                 "Content-Length: %zu\r\n"
                 "Connection: close\r\n"
                 "\r\n"
                 "%s",
                 status, content_type, strlen(body), body);

    send(client_socket, response, n, 0);
}

void handle_request(int client_socket) {
    char buffer[BUFFER_SIZE];
    recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    
    // Extract the request line
    char method[16], path[128], version[16];
    sscanf(buffer, "%s %s %s", method, path, version);

    // Basic routing
    if (strcmp(method, "GET") == 0) {
        if (strcmp(path, "/") == 0) {
            respond(client_socket, "200 OK", "text/html", "<h1>Welcome to Our Simple Server</h1><p>Go to /hello for a greeting!</p>");
        } else if (strcmp(path, "/hello") == 0) {
            respond(client_socket, "200 OK", "text/html", "<h1>Hello, World!</h1>");
        } else {
            respond(client_socket, "404 Not Found", "text/html", "<h1>404 Not Found</h1><p>The page you requested does not exist.</p>");
        }
    } else {
        respond(client_socket, "405 Method Not Allowed", "text/html", "<h1>405 Method Not Allowed</h1><p>Only GET method is allowed.</p>");
    }
    
    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is running on port %d...\n", PORT);

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("Accept failed");
            close(server_socket);
            exit(EXIT_FAILURE);
        }
        
        handle_request(client_socket);
    }

    close(server_socket);
    return 0;
}