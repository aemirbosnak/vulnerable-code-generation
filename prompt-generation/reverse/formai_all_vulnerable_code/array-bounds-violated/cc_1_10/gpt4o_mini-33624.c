//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>

#define PORT 8080
#define BUF_SIZE 4096

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void forward_request(int client_sock, const char *request) {
    // Create socket for forwarding the request
    int server_sock;
    struct sockaddr_in server_addr;

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        error("Unable to create socket for server connection");
    }

    // Parse the host and port from the request
    char host[256];
    int port = 80;
    sscanf(request, "GET http://%[^:]:%d", host, &port);
    
    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(host);

    // Connect to the server
    if (connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection to the server failed");
    }

    // Send request to the server
    send(server_sock, request, strlen(request), 0);
    
    char response[BUF_SIZE];
    int n;
    
    // Receive response from server and send it to the client
    while ((n = recv(server_sock, response, BUF_SIZE, 0)) > 0) {
        send(client_sock, response, n, 0);
    }
    
    // Cleanup socket
    close(server_sock);
}

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    
    // Create socket for HTTP proxy
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        error("Unable to create socket");
    }
    
    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    // Bind the socket
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Binding failed");
    }
    
    // Listen for incoming connections
    listen(server_sock, 5);
    printf("Grateful HTTP Proxy running on port %d!\n", PORT);
    
    // Accept and handle incoming connections
    while (1) {
        // Accepting client connection
        client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            error("Accept failed");
        }
        
        char request[BUF_SIZE];
        int bytes_received = recv(client_sock, request, BUF_SIZE - 1, 0);
        
        if (bytes_received > 0) {
            request[bytes_received] = '\0'; // Null terminate the request
            
            // Log the request for transparency
            printf("Received Request:\n%s\n", request);
            
            // Forward the request to the appropriate server
            forward_request(client_sock, request);
        }
        
        // Close client socket after finishing
        close(client_sock);
        printf("Finished handling a grateful request.\n");
    }
    
    // Close the server socket (ideally this should never be reached)
    close(server_sock);
    return 0;
}