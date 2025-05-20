//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

void process_request(int client_socket) {
    char buffer[BUFFER_SIZE];
    int read_size;
    
    // Receive data from client
    if ((read_size = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0';
        printf("Received message: %s\n", buffer);

        // Perform a simple statistical operation: word count
        int word_count = 0;
        char *token = strtok(buffer, " ");
        while (token != NULL) {
            word_count++;
            token = strtok(NULL, " ");
        }

        // Send back the word count
        snprintf(buffer, BUFFER_SIZE, "Word Count: %d", word_count);
        send(client_socket, buffer, strlen(buffer), 0);
    }

    // Close client socket
    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return EXIT_FAILURE;
    }

    // Prepare the sockaddr_in structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_socket);
        return EXIT_FAILURE;
    }
    
    printf("Server listening on port %d\n", PORT);

    // Main server loop
    while (1) {
        addr_size = sizeof(client_addr);
        // Accept a new client connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_size);
        
        if (client_socket < 0) {
            perror("Client accept failed");
            continue;
        }
        
        printf("Client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        
        // Process the client request
        process_request(client_socket);
    }

    // Close server socket (unreachable code in this case)
    close(server_socket);
    return EXIT_SUCCESS;
}