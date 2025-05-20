//GPT-4o-mini DATASET v1.0 Category: Simple Web Server ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void respond(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        perror("recv failed");
        close(client_socket);
        return;
    }
    
    buffer[bytes_received] = '\0';  // Null terminate the buffer

    // Log the request to the console
    printf("Request:\n%s\n", buffer);

    // Prepare the HTTP response
    const char *http_response_header = 
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        "Connection: close\r\n\r\n";

    const char *html_content =
        "<html>"
        "<head><title>Simple Web Server</title></head>"
        "<body>"
        "<h1>Welcome to My Simple Web Server!</h1>"
        "<p>This is a simple example of a web server written in C.</p>"
        "</body>"
        "</html>";

    // Send the response
    send(client_socket, http_response_header, strlen(http_response_header), 0);
    send(client_socket, html_content, strlen(html_content), 0);

    // Close the socket
    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    // Create the socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Failed to create socket");
        return 1;
    }

    // Set up the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;  // Listen on all interfaces
    server_addr.sin_port = htons(PORT);          // Use specified port

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        return 1;
    }

    // Start listening for connections
    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        close(server_socket);
        return 1;
    }

    printf("Server is running on http://localhost:%d\n", PORT);

    // Main loop to accept and respond to clients
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;  // If accept fails, just continue to the next loop iteration
        }

        respond(client_socket);
    }

    // Clean up and close the server socket
    close(server_socket);
    return 0;
}