//LLAMA2-13B DATASET v1.0 Category: Client Server Application ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080
#define MAX_CLIENT_LENGTH 1024

// Structure to hold client information
struct client_info {
    int sock;
    char name[50];
    char message[MAX_CLIENT_LENGTH];
};

// Function to create a new client socket
int create_client_socket(int server_fd) {
    int client_fd;
    struct sockaddr_in client_addr;

    // Create a new socket
    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // Set address and port number
    memset(&client_addr, 0, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &client_addr.sin_addr);

    // Connect to the server
    if (connect(client_fd, (struct sockaddr *)&client_addr, sizeof(client_addr)) < 0) {
        perror("connection failed");
        exit(1);
    }

    return client_fd;
}

// Function to handle client requests
void handle_client_request(int server_fd, int client_fd) {
    char buffer[MAX_CLIENT_LENGTH];
    struct client_info client_info;

    // Read client message
    read(client_fd, buffer, MAX_CLIENT_LENGTH);
    buffer[sizeof(buffer) - 1] = '\0';

    // Parse client message and extract name and message
    sscanf(buffer, "%s %s", client_info.name, client_info.message);

    // Print name and message on the server side
    printf("Client %s said: %s\n", client_info.name, client_info.message);

    // Send a response back to the client
    char* response = "Hello, client!";
    send(client_fd, response, strlen(response), 0);
}

// Function to handle server requests
void handle_server_request(int server_fd) {
    char buffer[MAX_CLIENT_LENGTH];

    // Read request from the client
    read(server_fd, buffer, MAX_CLIENT_LENGTH);
    buffer[sizeof(buffer) - 1] = '\0';

    // Print request on the server side
    printf("Server received: %s\n", buffer);

    // Send a response back to the client
    char* response = "Hello, client!";
    send(server_fd, response, strlen(response), 0);
}

int main() {
    int server_fd, client_fd;

    // Create a server socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // Bind the server socket to a specific address and port
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("binding failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listening failed");
        exit(1);
    }

    // Accept an incoming connection
    client_fd = accept(server_fd, NULL, NULL);
    if (client_fd < 0) {
        perror("accept failed");
        exit(1);
    }

    // Handle client requests
    handle_client_request(server_fd, client_fd);

    // Close the client socket
    close(client_fd);

    // Close the server socket
    close(server_fd);

    return 0;
}