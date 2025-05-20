//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 4096

void to_uppercase(char *str) {
    for(int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

void handle_request(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
    
    if (bytes_received < 0) {
        perror("Error receiving data");
        close(client_socket);
        return;
    }
    
    buffer[bytes_received] = '\0'; // Null-terminate the buffer

    printf("Received request:\n%s\n", buffer);
    
    // Forward the request to the remote server
    char *protocol, *host, *path;
    protocol = strtok(buffer, " "); // HTTP Method
    host = strtok(NULL, " ");      // Host
    path = strtok(NULL, " ");      // HTTP Path
    
    if (host != NULL) {
        // Connect to the remote server
        int server_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (server_socket < 0) {
            perror("Socket creation failed");
            close(client_socket);
            return;
        }

        struct sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(80);
        inet_pton(AF_INET, host, &server_addr.sin_addr);

        if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("Connection to server failed");
            close(server_socket);
            close(client_socket);
            return;
        }
        
        // Modify request to uppercase
        to_uppercase(buffer);

        // Send the modified request to the remote server
        send(server_socket, buffer, bytes_received, 0);
        
        // Receiving the response from the remote server
        bytes_received = recv(server_socket, buffer, BUFFER_SIZE - 1, 0);
        if (bytes_received > 0) {
            buffer[bytes_received] = '\0'; // Null-terminate the response
            printf("Modifying response...\n");
            to_uppercase(buffer); // Applying the same modification to the response
            send(client_socket, buffer, bytes_received, 0);
        }

        close(server_socket);
    }
    
    close(client_socket);
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Simple HTTP Proxy Server is running on port %d\n", PORT);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("Accept failed");
            continue; // Continue accepting new connections
        }

        handle_request(client_socket);
    }

    close(server_socket);
    return 0;
}