//GPT-4o-mini DATASET v1.0 Category: Browser Plugin ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void log_request(const char *request) {
    FILE *log_file = fopen("request_log.txt", "a");
    if (log_file == NULL) {
        perror("Unable to open log file");
        exit(EXIT_FAILURE);
    }
    fprintf(log_file, "%s\n", request);
    fclose(log_file);
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        perror("Failed to receive data from client");
        close(client_socket);
        return;
    }
    buffer[bytes_received] = '\0'; // Null-terminate the received data

    printf("Received request:\n%s\n", buffer);
    log_request(buffer); // Log the incoming request

    // Prepare a simple HTTP response
    const char *http_response = "HTTP/1.1 200 OK\r\n"
                                "Content-Type: text/html\r\n"
                                "Connection: close\r\n\r\n"
                                "<html><body><h1>Request Logged</h1></body></html>\n";
    send(client_socket, http_response, strlen(http_response), 0);
    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Create the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    // Set up the address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        // Accept a new client connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue; // Move to the next connection
        }
        
        // Handle the client request in a separate function
        handle_client(client_socket);
    }

    // Close the server socket (though this code will never be reached)
    close(server_socket);
    return 0;
}