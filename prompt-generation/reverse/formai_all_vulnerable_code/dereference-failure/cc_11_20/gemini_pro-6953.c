//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>

#define MAX_CLIENTS 100
#define BUFF_SIZE 1024

int main(int argc, char** argv) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;
    fd_set read_fds;
    int max_fd;
    char buffer[BUFF_SIZE];
    int nbytes;

    // Create server socket
    server_socket = socket(PF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        exit(1);
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // Bind server socket to address
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for client connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(1);
    }

    // Initialize read file descriptor set
    FD_ZERO(&read_fds);
    FD_SET(server_socket, &read_fds);
    max_fd = server_socket;

    // Main loop
    while (1) {
        // Select ready file descriptors
        memcpy(&read_fds, &read_fds, sizeof(read_fds));
        if (select(max_fd+1, &read_fds, NULL, NULL, NULL) < 0) {
            perror("select");
            exit(1);
        }

        // Check for new client connections
        if (FD_ISSET(server_socket, &read_fds)) {
            client_addr_len = sizeof(client_addr);
            client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_len);
            if (client_socket < 0) {
                perror("accept");
                continue;
            }

            // Add client socket to read file descriptor set
            FD_SET(client_socket, &read_fds);
            max_fd = fmax(max_fd, client_socket);

            // Send welcome message to client
            nbytes = sprintf(buffer, "Welcome to the chat server!\n");
            if (send(client_socket, buffer, nbytes, 0) < 0) {
                perror("send");
                close(client_socket);
                continue;
            }
        }

        // Check for data from clients
        for (int i = 0; i <= max_fd; i++) {
            if (FD_ISSET(i, &read_fds)) {
                // Read data from client
                nbytes = recv(i, buffer, BUFF_SIZE, 0);
                if (nbytes <= 0) {
                    // Client disconnected
                    close(i);
                    FD_CLR(i, &read_fds);
                } else {
                    // Broadcast data to all clients
                    for (int j = 0; j <= max_fd; j++) {
                        if (j != i && FD_ISSET(j, &read_fds)) {
                            if (send(j, buffer, nbytes, 0) < 0) {
                                perror("send");
                                close(j);
                                FD_CLR(j, &read_fds);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}