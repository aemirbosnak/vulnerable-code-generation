//GEMINI-pro DATASET v1.0 Category: Networking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define PORT 5555
#define BACKLOG 5
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main() {
    int server_socket, client_socket, client_addr_len;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int num_clients = 0;
    fd_set read_fds, write_fds;

    // Create the server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    // Set the server socket to be reusable
    int reuse_addr = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &reuse_addr, sizeof(reuse_addr)) == -1) {
        perror("setsockopt");
        exit(1);
    }

    // Set the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    // Bind the server socket to the server address
    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    // Initialize the file descriptor sets
    FD_ZERO(&read_fds);
    FD_ZERO(&write_fds);

    // Add the server socket to the read file descriptor set
    FD_SET(server_socket, &read_fds);

    // Main server loop
    while (1) {
        // Select the ready file descriptors
        if (select(FD_SETSIZE, &read_fds, &write_fds, NULL, NULL) == -1) {
            perror("select");
            exit(1);
        }

        // Handle new connections
        if (FD_ISSET(server_socket, &read_fds)) {
            // Accept the incoming connection
            if ((client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_addr_len)) == -1) {
                perror("accept");
                exit(1);
            }

            // Add the client socket to the read file descriptor set
            FD_SET(client_socket, &read_fds);

            // Increment the number of clients
            num_clients++;

            // Send a welcome message to the client
            const char *welcome_msg = "Welcome to the server!\n";
            if (send(client_socket, welcome_msg, strlen(welcome_msg), 0) == -1) {
                perror("send");
                exit(1);
            }
        }

        // Handle data from clients
        for (int i = 0; i < FD_SETSIZE; i++) {
            if (FD_ISSET(i, &read_fds) && i != server_socket) {
                // Receive data from the client
                int bytes_received = recv(i, buffer, BUFFER_SIZE, 0);

                if (bytes_received == -1) {
                    perror("recv");
                    exit(1);
                } else if (bytes_received == 0) {
                    // Client has closed the connection
                    FD_CLR(i, &read_fds);
                    close(i);
                    num_clients--;
                } else {
                    // Echo the data back to the client
                    if (send(i, buffer, bytes_received, 0) == -1) {
                        perror("send");
                        exit(1);
                    }
                }
            }
        }

        // Handle data to send to clients
        for (int i = 0; i < FD_SETSIZE; i++) {
            if (FD_ISSET(i, &write_fds) && i != server_socket) {
                // Send data to the client
                const char *data = "Hello from the server!\n";
                if (send(i, data, strlen(data), 0) == -1) {
                    perror("send");
                    exit(1);
                }

                // Remove the client socket from the write file descriptor set
                FD_CLR(i, &write_fds);
            }
        }
    }

    // Close the server socket
    close(server_socket);

    return 0;
}