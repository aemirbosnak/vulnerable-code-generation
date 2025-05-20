//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 8192

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void handle_request(int client_sock) {
    char buffer[BUFFER_SIZE];
    char method[10], url[1024], version[10];
    int bytes_read = recv(client_sock, buffer, sizeof(buffer), 0);
    
    if (bytes_read < 0) {
        error("Error receiving data");
    }
    
    // Parse the HTTP request
    sscanf(buffer, "%s %s %s", method, url, version);
    
    // Display the received request
    printf("Received request: %s %s %s\n", method, url, version);
    
    // Prepare to forward the request
    char *hostname = strtok(url + 7, "/"); // Skip "http://"
    char *path = strchr(url + 7, '/');
    
    if (path == NULL) {
        path = "/";
    }

    struct sockaddr_in server_addr;
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        error("Error opening socket");
    }
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Error connecting to the server");
    }
    
    // Send the original HTTP request to the actual server
    snprintf(buffer, sizeof(buffer), "%s %s %s\r\nHost: %s\r\nConnection: close\r\n\r\n", method, path, version, hostname);
    send(server_sock, buffer, strlen(buffer), 0);
    
    // Receive the response from the server and send it back to the client
    while ((bytes_read = recv(server_sock, buffer, sizeof(buffer), 0)) > 0) {
        send(client_sock, buffer, bytes_read, 0);
    }

    // Close sockets
    close(server_sock);
    close(client_sock);
}

int main() {
    int sockfd, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // Accept any incoming address
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Error on binding");
    }

    // Listen for connections
    listen(sockfd, 5);
    printf("Proxy server running on port %d...\n", PORT);

    while (1) {
        // Accept a connection from a client
        client_sock = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            error("Error on accept");
        }

        // Handle incoming request in a separate function
        handle_request(client_sock);
    }

    // Close the main socket
    close(sockfd);
    return 0;
}