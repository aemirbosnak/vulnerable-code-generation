//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    int server_socket_fd, client_socket_fd, socket_option = 1;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len = sizeof(client_address);
    char buffer[BUFFER_SIZE] = {0};

    // Create server socket
    if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Failed to create server socket.");
        exit(EXIT_FAILURE);
    }

    // Set socket options to reuse address and port
    if (setsockopt(server_socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &socket_option, sizeof(socket_option))) {
        perror("Failed to set socket options.");
        exit(EXIT_FAILURE);
    }

    // Bind the server socket to given address and port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(atoi(argv[1]));
    if (bind(server_socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to bind server socket.");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket_fd, 3) < 0) {
        perror("Failed to listen for incoming connections.");
        exit(EXIT_FAILURE);
    }
    printf("Server listening on port %d\n", atoi(argv[1]));

    // Accept incoming connections and handle them
    while (1) {
        if ((client_socket_fd = accept(server_socket_fd, (struct sockaddr*)&client_address, &client_address_len)) < 0) {
            perror("Failed to accept incoming connection.");
            exit(EXIT_FAILURE);
        }

        // Fork to handle multiple client connections
        if (fork() == 0) {
            close(server_socket_fd);  // Close parent socket in child process

            // Handle client connection
            printf("Connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
            while (1) {
                memset(buffer, 0, BUFFER_SIZE);
                if (read(client_socket_fd, buffer, BUFFER_SIZE) <= 0) {
                    perror("Connection closed by client.");
                    break;
                }
                printf("%s:%d > %s", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port), buffer);
                strcat(buffer, " Server received message\n");
                if (write(client_socket_fd, buffer, strlen(buffer)) < 0) {
                    perror("Failed to respond to client.");
                    break;
                }
            }
            close(client_socket_fd);  // Close client socket in child process
            exit(EXIT_SUCCESS);
        }

        close(client_socket_fd);  // Close socket in parent process
    }

    return 0;
}