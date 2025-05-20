//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <errno.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void error_handling(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error_handling("socket failed");
    }

    // Forcefully attaching socket to the port PORT
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        error_handling("setsockopt failed");
    }
    
    // Setting up the address structure
    address.sin_family = AF_INET; // IPv4
    address.sin_addr.s_addr = INADDR_ANY; // Accept all incoming connections
    address.sin_port = htons(PORT); // Convert to network byte order

    // Binding the socket to the address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        error_handling("bind failed");
    }

    // Listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        error_handling("listen failed");
    }

    printf("Server is listening on port %d...\n", PORT);

    // Accepting a connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        error_handling("accept failed");
    }

    printf("Connected to client: %s:%d\n", 
           inet_ntoa(address.sin_addr), ntohs(address.sin_port));

    // Communication loop
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        ssize_t bytes_received = recv(new_socket, buffer, sizeof(buffer) - 1, 0);
        
        if (bytes_received < 0) {
            error_handling("recv failed");
        } else if (bytes_received == 0) {
            printf("Client disconnected.\n");
            break; // Client disconnected
        }

        buffer[bytes_received] = '\0'; // Null-terminate the received string
        printf("Received from client: %s\n", buffer);
        
        // Echo back the received message to the client
        ssize_t bytes_sent = send(new_socket, buffer, bytes_received, 0);
        if (bytes_sent < 0) {
            error_handling("send failed");
        }
    }

    // Closing the socket
    close(new_socket);
    close(server_fd);
    printf("Server closed.\n");

    return 0;
}