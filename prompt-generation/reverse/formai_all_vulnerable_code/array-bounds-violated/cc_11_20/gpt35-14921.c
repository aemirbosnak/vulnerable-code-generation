//FormAI DATASET v1.0 Category: Chat server ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_MSG_LEN 1024
#define MAX_CLIENTS 5

typedef struct {
    int socket_fd;
    struct sockaddr_in address;
} client_t;

int main() {
    int server_fd, valread;
    struct sockaddr_in server_address = {0};

    // Create TCP socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Failed to create server socket");
        return EXIT_FAILURE;
    }

    // Set server socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int)) < 0) {
        perror("Failed to set server socket options");
        return EXIT_FAILURE;
    }

    // Specify server address details
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind server socket to specified address
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to bind server socket");
        return EXIT_FAILURE;
    }

    // Listen for incoming client connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Failed to listen for client connections");
        return EXIT_FAILURE;
    }

    printf("Chat server running on port %d\n", PORT);

    client_t clients[MAX_CLIENTS];
    int active_clients = 0;

    while (1) {
        // Accept incoming client connections
        int client_fd;
        struct sockaddr_in client_address = {0};
        int client_address_len = sizeof(client_address);
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t *)&client_address_len)) < 0) {
            perror("Failed to accept client connection");
            return EXIT_FAILURE;
        }

        // Add client to list of active clients
        client_t new_client = { client_fd, client_address };
        clients[active_clients++] = new_client;

        // Inform other clients about new client connection
        char *new_client_msg = "New client connected\n";
        for (int i = 0; i < active_clients; i++) {
            if (clients[i].socket_fd != client_fd) {
                send(clients[i].socket_fd, new_client_msg, strlen(new_client_msg), 0);
            }
        }

        // Create child process to handle client communication
        int pid = fork();
        if (pid < 0) {
            perror("Failed to create child process");
            return EXIT_FAILURE;
        }
        else if (pid == 0) {
            // Child process - handle client communication
            close(server_fd);

            char buffer[MAX_MSG_LEN] = {0};
            while (1) {
                int msg_len;
                if ((msg_len = recv(client_fd, buffer, MAX_MSG_LEN, 0)) < 0) {
                    perror("Failed to receive message from client");
                    exit(EXIT_FAILURE);
                }
                if (msg_len == 0) {
                    // Client disconnected
                    printf("Client disconnected\n");

                    // Remove client from list of active clients
                    for (int i = 0; i < active_clients; i++) {
                        if (clients[i].socket_fd == client_fd) {
                            // Shift clients after this one down one position
                            for (int j = i+1; j < active_clients; j++) {
                                clients[j-1] = clients[j];
                            }
                            active_clients--;

                            // Inform other clients about client disconnection
                            char *disconnect_msg = "Client disconnected\n";
                            for (int j = 0; j < active_clients; j++) {
                                send(clients[j].socket_fd, disconnect_msg, strlen(disconnect_msg), 0);
                            }
                            break;
                        }
                    }
                    close(client_fd);
                    break;
                }

                // Broadcast message to all other clients
                for (int i = 0; i < active_clients; i++) {
                    if (clients[i].socket_fd != client_fd) {
                        send(clients[i].socket_fd, buffer, strlen(buffer), 0);
                    }
                }
                memset(buffer, 0, MAX_MSG_LEN);
            }
            exit(EXIT_SUCCESS);
        }
        else {
            // Parent process - continue accepting client connections
            close(client_fd);
        }
    }

    return EXIT_SUCCESS;
}