//GPT-4o-mini DATASET v1.0 Category: Simple Web Server ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUF_SIZE 1024

void handle_client(int client_socket);

const char *HTTP_OK = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
const char *HTTP_NOT_FOUND = "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\n\r\n";
const char *HTML_OK = "<html><body><h1>Hello, World!</h1></body></html>";
const char *HTML_NOT_FOUND = "<html><body><h1>404 Not Found</h1></body></html>";

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Creating socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setting up the server address structure
    server_addr.sin_family = AF_INET;  
    server_addr.sin_addr.s_addr = INADDR_ANY;  
    server_addr.sin_port = htons(PORT);  

    // Binding the socket to the port
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_socket, 10) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        // Accepting a new client connection
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue; // Continue to the next iteration
        }

        handle_client(client_socket);
        close(client_socket);
    }

    close(server_socket);
    return 0;
}

void handle_client(int client_socket) {
    char buffer[BUF_SIZE];
    int bytes_read = recv(client_socket, buffer, BUF_SIZE - 1, 0);
    if (bytes_read < 0) {
        perror("recv failed");
        return; // Exit the function
    }
    buffer[bytes_read] = '\0';  // Null terminate the buffer

    printf("Received request:\n%s\n", buffer);

    // Check the request method and path
    if (strstr(buffer, "GET / HTTP/1.1")) {
        // Serve the main page
        send(client_socket, HTTP_OK, strlen(HTTP_OK), 0);
        send(client_socket, HTML_OK, strlen(HTML_OK), 0);
    } else {
        // Serve 404 Page
        send(client_socket, HTTP_NOT_FOUND, strlen(HTTP_NOT_FOUND), 0);
        send(client_socket, HTML_NOT_FOUND, strlen(HTML_NOT_FOUND), 0);
    }
}