//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>

#define PORT 8080
#define BUFFER_SIZE 4096

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    char method[10], url[255], version[10];
    char *host, *port;
    int server_socket;

    // Read the request from the client
    int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
    if (bytes_received < 0) {
        perror("Error reading from client socket");
        close(client_socket);
        return;
    }

    // Parse the HTTP request
    sscanf(buffer, "%s %s %s", method, url, version);
    if (strcasecmp(method, "GET") != 0) {
        printf("Only GET method supported. Received: %s\n", method);
        close(client_socket);
        return;
    }

    // Extract the host from the URL
    host = strstr(url, "://");
    if (host) host += 3; // Skip over "http://"
    else host = url; // Fallback if no "http://" present

    port = strchr(host, ':'); // Check if port is specified
    if (port) {
        *port = '\0'; // Null-terminate for easy extraction
        port++;
    } else {
        port = "80"; // Default HTTP port
    }

    // Create a socket to connect to the target server
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Server socket creation failed");
        close(client_socket);
        return;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    server_addr.sin_addr.s_addr = inet_addr(host);

    // Establish the connection to the target server
    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(client_socket);
        close(server_socket);
        return;
    }

    // Send the parsed request to the target server
    if (send(server_socket, buffer, bytes_received, 0) < 0) {
        perror("Failed to send request to server");
        close(client_socket);
        close(server_socket);
        return;
    }

    // Read the response from the server
    while ((bytes_received = recv(server_socket, buffer, sizeof(buffer), 0)) > 0) {
        send(client_socket, buffer, bytes_received, 0);
    }

    // Close the sockets
    close(server_socket);
    close(client_socket);
}

int main() {
    int server_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    // Create a socket for the proxy server
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_sock, 10) < 0) {
        perror("Listen failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    printf("Proxy server listening on port %d\n", PORT);

    // Accept incoming connections in an infinite loop
    while (1) {
        int client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("Accept failed");
            continue;
        }

        // Handle the client in a separate function (this could be enhanced with threading)
        handle_client(client_sock);
    }

    // Close the server socket (will not reach here in this infinite loop)
    close(server_sock);
    return 0;
}