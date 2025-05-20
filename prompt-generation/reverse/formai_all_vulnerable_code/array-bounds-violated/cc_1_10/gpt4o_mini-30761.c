//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>

#define PORT 8080
#define BUF_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUF_SIZE];
    int n;

    while (1) {
        n = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
        if (n <= 0) {
            printf("Client disconnected or error occurred.\n");
            break;
        }
        buffer[n] = '\0';
        printf("Client: %s\n", buffer);
        send(client_socket, buffer, n, 0); // Echo message back
    }

    close(client_socket);
    exit(0);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    printf("Socket created successfully.\n");

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // Bind to any IP address
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    printf("Binding successful. Listening on port %d...\n", PORT);

    listen(server_socket, 5);  // Listen for incoming connections
    addr_size = sizeof(client_addr);

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_size);
        if (client_socket < 0) {
            perror("Failed to accept connection");
            continue;
        }
        printf("Connection accepted.\n");

        if (fork() == 0) {
            // Child process to handle client
            close(server_socket);
            handle_client(client_socket);
        }
        close(client_socket); // Parent closes client socket
    }

    close(server_socket);
    return 0;
}