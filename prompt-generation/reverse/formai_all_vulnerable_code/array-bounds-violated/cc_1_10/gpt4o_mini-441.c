//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    while ((bytes_read = recv(client_socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the received string
        printf("Received: %s\n", buffer);
        
        // Echo back the message to the client
        if (send(client_socket, buffer, bytes_read, 0) == -1) {
            perror("send");
            break;
        }
    }

    if (bytes_read == -1) {
        perror("recv");
    }

    // Close the socket for the client
    close(client_socket);
    printf("Client disconnected\n");
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the specified port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("listen");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Main loop to accept clients
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket == -1) {
            perror("accept");
            continue; // Skip this iteration on error
        }

        // Print client's address
        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, sizeof(client_ip));
        printf("New connection established: %s:%d\n", client_ip, ntohs(client_addr.sin_port));

        // Fork to handle client connection
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            close(client_socket);
            continue;
        }

        if (pid == 0) {
            // In child process
            close(server_socket); // Child does not need the listening socket
            handle_client(client_socket);
            exit(EXIT_SUCCESS);
        } else {
            // In parent process
            close(client_socket); // Parent does not need the client socket here
        }
    }

    // Cleanup: This line will never be reached, but good practice to include
    close(server_socket);
    return 0;
}