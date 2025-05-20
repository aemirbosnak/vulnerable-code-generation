//FormAI DATASET v1.0 Category: Chat server ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int clients[MAX_CLIENTS];
int num_clients = 0;

void broadcast(int sender, char *message) {
    for(int i=0; i<num_clients; i++) {
        int client = clients[i];
        if (client != sender) {
            if (send(client, message, strlen(message), 0) == -1) {
                printf("Error broadcasting message to client %d\n", client);
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Create TCP server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Failed to set socket options");
        exit(EXIT_FAILURE);
    }

    // Set server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Failed to listen on socket");
        exit(EXIT_FAILURE);
    }

    printf("Chat server running on port %d\n", PORT);

    while(1) {
        // Accept incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Failed to accept connection");
            exit(EXIT_FAILURE);
        }

        printf("Client %d connected\n", new_socket);
        clients[num_clients] = new_socket;
        num_clients++;

        char *welcome_message = "Welcome to the chat server!\n";
        if (send(new_socket, welcome_message, strlen(welcome_message), 0) != strlen(welcome_message)) {
            perror("Failed to send welcome message");
            exit(EXIT_FAILURE);
        }

        // Fork a child process to handle the new client
        int pid = fork();

        if (pid == -1) {
            perror("Failed to fork child process to handle client");
        } else if (pid == 0) {
            // Child process

            // Close unused server socket
            close(server_fd);

            while(1) {
                int bytes_read = read(new_socket, buffer, BUFFER_SIZE-1);
                if (bytes_read < 0) {
                    perror("Failed to read from client");
                    exit(EXIT_FAILURE);
                } else if (bytes_read == 0) {
                    // Client has disconnected
                    break;
                } else {
                    // Broadcast message to all other clients
                    buffer[bytes_read] = '\0';
                    printf("Client %d: %s", new_socket, buffer);
                    broadcast(new_socket, buffer);
                }
            }

            // Client has disconnected
            printf("Client %d disconnected\n", new_socket);
            close(new_socket);
            exit(EXIT_SUCCESS);
        } else {
            // Parent process

            // Close unused client socket
            close(new_socket);
        }
    }

    return 0;
}