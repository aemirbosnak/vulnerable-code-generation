//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DEFAULT_PORT 8080
#define BACKLOG 10
#define BUFFER_SIZE 2048

int main() {
    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Bind the socket to a port
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(DEFAULT_PORT);
    bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));

    // Listen for incoming connections
    listen(server_socket, BACKLOG);

    // Accept connections and serve requests
    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_address_length = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
        
        // Read the HTTP request from the client
        char buffer[BUFFER_SIZE];
        int bytes_read = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
        buffer[bytes_read] = '\0';

        // Send a response back to the client
        char response[] = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello, world!\r\n";
        send(client_socket, response, strlen(response), 0);

        // Close the client socket
        close(client_socket);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}