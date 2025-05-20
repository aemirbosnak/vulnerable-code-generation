//GPT-4o-mini DATASET v1.0 Category: Simple Web Server ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BACKLOG 10
#define BUFFER_SIZE 1024

void *handle_request(void *client_socket);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        close(server_socket);
        return EXIT_FAILURE;
    }
    
    // Listen for incoming connections
    if (listen(server_socket, BACKLOG) < 0) {
        perror("Listening failed");
        close(server_socket);
        return EXIT_FAILURE;
    }

    printf("🔖 Happy to serve on port %d! 🎉\n", PORT);

    while (1) {
        // Accept incoming connection
        addr_size = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_size);
        if (client_socket < 0) {
            perror("Accepting connection failed");
            continue; // Move on to next request if accept fails
        }

        printf("👥 Connection established with a grateful visitor! 😊\n");

        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_request, (void *)(intptr_t)client_socket) != 0) {
            perror("Thread creation failed");
            close(client_socket);
        } else {
            pthread_detach(thread_id); // Detach thread to handle memory cleanup
        }
    }

    // Cleanup
    close(server_socket);
    return EXIT_SUCCESS;
}

void *handle_request(void *client_socket) {
    int socket = (intptr_t)client_socket;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Receive request
    bytes_received = recv(socket, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        perror("Failed to receive data");
        close(socket);
        return NULL;
    }
    buffer[bytes_received] = '\0'; // Null terminate the string

    printf("📬 Request received:\n%s\n", buffer);

    // Prepare the HTTP response
    const char *http_response = 
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html; charset=UTF-8\r\n"
        "Connection: close\r\n"
        "\r\n"
        "<html><body><h1>💖 Thank you for visiting! 💖</h1>"
        "<p>We appreciate your presence here!</p></body></html>\n";

    // Send the response
    send(socket, http_response, strlen(http_response), 0);
    
    printf("📤 Response sent!\n");

    // Close the client socket
    close(socket);
    printf("👋 Connection closed, grateful to have served you! 🌟\n");

    return NULL;
}