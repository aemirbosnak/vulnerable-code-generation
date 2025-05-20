//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: Cryptic
#include <stdio.h>    // Required for input/output functions
#include <stdlib.h>   // For memory allocation and system functions
#include <string.h>   // String manipulation functions
#include <unistd.h>   // Unix standard functions
#include <arpa/inet.h> // For sockets
#include <netinet/in.h> // Internet address family

#define BUF_SIZE 8192 // Buffer size for data transfer
#define SERVER_PORT 8080 // Port for the proxy
#define BACKLOG 10 // Listen backlog

// A cryptic funtion to interpret and begin the HTTP proxy
void handle_client(int client_socket) {
    int server_socket;
    struct sockaddr_in server_addr;
    char buffer[BUF_SIZE], method[10], url[256], version[20], *host, *path;
    
    // Read from client
    int bytes_read = recv(client_socket, buffer, BUF_SIZE, 0);
    if (bytes_read <= 0) return;

    // Parse request
    sscanf(buffer, "%s %s %s", method, url, version);
    host = strstr(url, "://") + 3; // Find the host
    path = strchr(host, '/'); // Find the path
    if (path) {
        *path = '\0'; // Split host and path
        path++; // Move past null terminator
    } else {
        path = ""; // Default path
    }

    // Create socket to target server
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket Creation Failed");
        close(client_socket);
        return;
    }

    // Configure server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = inet_addr(host); // Convert IP Address

    // Connect to target server
    if (connect(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to Server Failed");
        close(server_socket);
        close(client_socket);
        return;
    }

    // Forward the request
    send(server_socket, buffer, bytes_read, 0);
    // Receive the response
    while ((bytes_read = recv(server_socket, buffer, BUF_SIZE, 0)) > 0) {
        send(client_socket, buffer, bytes_read, 0); // Send response to client
    }

    // Clean up
    close(server_socket);
    close(client_socket);
}

// The edgy function initializes the proxy server
int main() {
    int listen_socket, client_socket; // Socket descriptors
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Secretly create a listening socket
    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket < 0) {
        perror("Socket Creation Failed");
        exit(EXIT_FAILURE);
    }

    // Mysteriously fill the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // Listen on any available interface
    server_addr.sin_port = htons(SERVER_PORT); // Set the server port

    // Bind the socket to the specified port
    if (bind(listen_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding Failed");
        close(listen_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections, allowing a backlog
    listen(listen_socket, BACKLOG);
    printf("Proxy Server is running on port %d...\n", SERVER_PORT);

    // Eternal loop to accept and handle clients
    while (1) {
        client_socket = accept(listen_socket, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("Accept Failed");
            continue;
        }
        handle_client(client_socket); // Serve the client secretly and swiftly
    }

    // Clean up the listening socket (though this will never be reached)
    close(listen_socket);
    return 0;
}