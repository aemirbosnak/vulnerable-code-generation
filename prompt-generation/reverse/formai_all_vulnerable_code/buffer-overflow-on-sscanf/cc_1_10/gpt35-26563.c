//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 4096
    
void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int client_fd, server_fd, port, client_addr_len, server_addr_len, n;
    struct sockaddr_in client_addr, server_addr;
    char buffer[BUFFER_SIZE], proxy[BUFFER_SIZE], *temp;
    
    // Check if port number is provided
    if (argc < 2) {
        fprintf(stderr, "Port number not provided.\n");
        exit(1);
    }
    
    // Initialize socket
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        error("Error initializing client socket.");
    }
    
    // Set socket options
    int optval = 1;
    setsockopt(client_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval);
    
    // Parse port number
    port = atoi(argv[1]);
    
    // Clear client_addr buffer and set values
    memset(&client_addr, 0, sizeof client_addr);
    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    client_addr.sin_port = htons(port);
    
    // Bind to port
    if (bind(client_fd, (struct sockaddr *) &client_addr, sizeof client_addr) == -1) {
        error("Error binding socket to port.");
    }
    
    // Start listening for incoming connections
    if (listen(client_fd, 5) == -1) {
        error("Error setting socket to listen.");
    }
    
    printf("Proxy server running on port %d...\n", port);
    
    // Main loop - accept incoming connections and start proxying
    while (1) {
        // Accept incoming connection
        client_addr_len = sizeof client_addr;
        server_addr_len = sizeof server_addr;
        if ((server_fd = accept(client_fd, (struct sockaddr *) &server_addr, &server_addr_len)) == -1) {
            error("Error accepting connection.");
        }
        
        printf("Client connected to proxy server.\n");
        
        // Receive client request
        memset(buffer, 0, BUFFER_SIZE);
        n = recv(server_fd, buffer, BUFFER_SIZE - 1, 0);
        if (n < 0) {
            error("Error receiving data from client.");
        }
        
        // Parse client request and extract hostname
        temp = strstr(buffer, "Host:");
        sscanf(temp, "Host: %s", proxy);
        
        // Connect to remote server
        memset(&server_addr, 0, sizeof server_addr);
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(80);
        if (inet_pton(AF_INET, proxy, &server_addr.sin_addr) <= 0) {
            error("Error resolving hostname.");
        }
        if (connect(server_fd, (struct sockaddr *) &server_addr, server_addr_len) < 0) {
            error("Error connecting to remote server.");
        }
        
        printf("Proxying request to remote server...\n");
        
        // Send client request to remote server
        if (send(server_fd, buffer, strlen(buffer), 0) < 0) {
            error("Error sending data to remote server.");
        }
        
        // Receive response from remote server and forward to client
        memset(buffer, 0, BUFFER_SIZE);
        while ((n = recv(server_fd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
            printf("Forwarding response to client...\n");
            if (send(server_fd, buffer, n, 0) < 0) {
                error("Error sending data to client.");
            }
            
            memset(buffer, 0, BUFFER_SIZE);
        }
        
        // Close server socket
        close(server_fd);
    }
    
    // Close client socket
    close(client_fd);
    
    return 0;
}