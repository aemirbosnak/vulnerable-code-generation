//FormAI DATASET v1.0 Category: Chat server ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_fd, client_fds[MAX_CLIENTS] = {0};

    struct sockaddr_in address;
    int addr_len = sizeof(address);

    char buffer[BUFFER_SIZE] = {0};
    char welcome_message[] = "Welcome to the chatroom!\n";

    // Create and bind socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, addr_len) < 0) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    // Start listening for clients
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Failed to start listening");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for clients to connect...\n");

    while (1) {
        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(server_fd, &read_fds);

        // Add any connected clients to the set
        int max_fd = server_fd;
        for (int i = 0; i < MAX_CLIENTS; i++) {
            int client_fd = client_fds[i];
            if (client_fd > 0) {
                FD_SET(client_fd, &read_fds);
                max_fd = (client_fd > max_fd) ? client_fd : max_fd;
            }
        }

        // Wait for activity on any of the sockets
        if (select(max_fd + 1, &read_fds, NULL, NULL, NULL) < 0) {
            perror("Failed to select socket");
            exit(EXIT_FAILURE);
        }

        // Check if there are any new clients to accept
        if (FD_ISSET(server_fd, &read_fds)) {
            int new_fd;
            if ((new_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addr_len)) < 0) {
                perror("Failed to accept new client");
                exit(EXIT_FAILURE);
            }

            printf("New client connected: %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

            // Send welcome message to new client
            send(new_fd, welcome_message, strlen(welcome_message), 0);

            // Add client to list
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (client_fds[i] == 0) {
                    client_fds[i] = new_fd;
                    break;
                }
            }
        }

        // Check for activity on any connected clients
        for (int i = 0; i < MAX_CLIENTS; i++) {
            int client_fd = client_fds[i];
            if (FD_ISSET(client_fd, &read_fds)) {
                // Read message from client
                int bytes_read = read(client_fd, buffer, BUFFER_SIZE);
                if (bytes_read < 0) {
                    perror("Failed to read message from client");
                    close(client_fd);
                    client_fds[i] = 0;
                    continue;
                }

                // Check if client has disconnected
                if (bytes_read == 0) {
                    printf("Client disconnected: %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
                    close(client_fd);
                    client_fds[i] = 0;
                    continue;
                }

                // Print message to console and send to all other clients
                printf("Client %s:%d says: %s", inet_ntoa(address.sin_addr), ntohs(address.sin_port), buffer);
                for (int j = 0; j < MAX_CLIENTS; j++) {
                    int other_fd = client_fds[j];
                    if (other_fd == 0 || other_fd == client_fd) {
                        continue;
                    }
                    send(other_fd, buffer, bytes_read, 0);
                }
            }
        }
    }

    return 0;
}