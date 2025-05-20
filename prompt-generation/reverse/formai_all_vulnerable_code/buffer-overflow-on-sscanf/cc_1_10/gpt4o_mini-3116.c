//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 4096

void handle_client(int client_socket);

int main() {
    // Setting up the server
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_socket, 10) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    printf("Artistic HTTP Proxy running on port %d!\n", PORT);

    while (1) {
        // Accepting client connections
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }
        printf("Client connected!\n");

        // Handle the client request in a new function
        handle_client(client_socket);
        close(client_socket);
    }

    close(server_socket);
    return 0;
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    // Read the request from the client
    memset(buffer, 0, BUFFER_SIZE);
    bytes_read = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_read < 0) {
        perror("Receive failed");
        return;
    }

    buffer[bytes_read] = '\0';
    printf("Request received:\n%s\n", buffer);

    // Extracting the URL from the GET request
    char method[10], url[256];
    sscanf(buffer, "%s %s", method, url);

    // Forming the new server query
    if (strncmp(method, "GET", 3) != 0) {
        printf("Only GET method is supported!\n");
        return;
    }

    // Strip off HTTP:// from the URL if present
    char *http_pos = strstr(url, "http://");
    char *target_url;
    if (http_pos) {
        target_url = http_pos + 7; // Move past "http://"
    } else {
        target_url = url;
    }

    // Finding the end of the host
    char *end_pos = strchr(target_url, '/');
    char host[256];
    if (end_pos) {
        strncpy(host, target_url, end_pos - target_url);
        host[end_pos - target_url] = '\0';
    } else {
        strcpy(host, target_url);
    }

    // Connecting to Target Host
    int target_socket;
    struct sockaddr_in target_addr;
    
    if ((target_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Target socket creation failed");
        return;
    }

    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(80);
    target_addr.sin_addr.s_addr = inet_addr(host);

    // Connect to the target host
    if (connect(target_socket, (struct sockaddr *)&target_addr, sizeof(target_addr)) < 0) {
        perror("Connection to target host failed");
        close(target_socket);
        return;
    }
    printf("Proxying request to %s...\n", host);

    // Send the request to the target
    send(target_socket, buffer, bytes_read, 0);
    
    // Receive the response from the target
    while ((bytes_read = recv(target_socket, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytes_read] = '\0';
        send(client_socket, buffer, bytes_read, 0); // Send back to the client
    }

    // Cleanup
    close(target_socket);
    printf("Connection closed with client.\n");
}