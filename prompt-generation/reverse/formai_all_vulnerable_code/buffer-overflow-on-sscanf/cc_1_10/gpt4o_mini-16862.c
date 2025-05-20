//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PORT 8080
#define BUFFER_SIZE 8192

void handle_client(int client_sock) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Read the request from the client
    bytes_received = recv(client_sock, buffer, sizeof(buffer), 0);
    if (bytes_received < 0) {
        perror("recv failed");
        close(client_sock);
        return;
    }

    // Extract the request line to get the target host and port
    char method[8], host[256];
    int port = 80; // Default HTTP port

    // Example request line: GET http://www.example.com/index.html HTTP/1.1
    sscanf(buffer, "%s http://%[^/]", method, host);

    // If there is a port specified, extract it
    char *port_pos = strstr(host, ":");
    if (port_pos) {
        port = atoi(port_pos + 1);
        *port_pos = '\0'; // Null terminate the host
    }

    // Create a socket to connect to the target server
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("socket creation failed");
        close(client_sock);
        return;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    
    // Convert host to IP address
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        perror("Invalid address");
        close(server_sock);
        close(client_sock);
        return;
    }

    // Connect to the target server
    if (connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(server_sock);
        close(client_sock);
        return;
    }

    // Send the request to the target server
    send(server_sock, buffer, bytes_received, 0);

    // Now read the response from the target server and send it back to the client
    while ((bytes_received = recv(server_sock, buffer, sizeof(buffer), 0)) > 0) {
        send(client_sock, buffer, bytes_received, 0);
    }

    if (bytes_received < 0) {
        perror("recv failed");
    }

    // Close the sockets
    close(server_sock);
    close(client_sock);
}

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Create a TCP socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Prepare the sockaddr_in structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_sock, 10) < 0) {
        perror("listen failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    printf("Proxy server is listening on port %d...\n", PORT);

    // Accept incoming connections in a loop
    while (1) {
        client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addr_len);
        if (client_sock < 0) {
            perror("accept failed");
            continue;
        }

        // Handle the client in a separate function
        handle_client(client_sock);
    }

    // Close the server socket (unreachable in this example)
    close(server_sock);
    return 0;
}