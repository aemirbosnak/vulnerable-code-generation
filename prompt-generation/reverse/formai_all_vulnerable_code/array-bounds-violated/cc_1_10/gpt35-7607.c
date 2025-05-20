//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <signal.h>

#define PORT 8080
#define MAX_PENDING 10
#define BUF_SIZE 1024

int server_socket_fd, client_socket_fd;

/**
 * Handles incoming connections
 */
void handle_connection(int client_fd, struct sockaddr_in client_addr) {
    char buffer[BUF_SIZE];
    int read_size;

    // Receive message from the client
    while ((read_size = recv(client_fd, buffer, BUF_SIZE, 0)) > 0) {
        buffer[read_size] = '\0';
        printf("Received message from %s:%d: %s\n",
            inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), buffer);
        
        // Send confirmation message back to the client
        write(client_fd, "Message received", sizeof("Message received"));
    }

    // Close client socket
    printf("Lost connection to %s:%d\n",
        inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    close(client_fd);
}

/**
 * Handles signal interrupt
 */
void sigint_handler(int signum) {
    printf("Shutting down server...\n");
    close(server_socket_fd);
    exit(0);
}

int main() {
    struct sockaddr_in server_addr = {0}, client_addr = {0}, remote_addr = {0};
    int addrlen = sizeof(server_addr), opt = 1;
    char buffer[BUF_SIZE];

    // Create TCP socket
    if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Socket creation error\n");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        printf("Socket option setting error\n");
        exit(EXIT_FAILURE);
    }

    // Set server address variables
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind socket to server address
    if (bind(server_socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Socket binding error\n");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket_fd, MAX_PENDING) < 0) {
        printf("Listen error\n");
        exit(EXIT_FAILURE);
    }

    // Register signal interrupt handler
    signal(SIGINT, sigint_handler);

    // Server loop
    while (1) {
        // Accept incoming connections
        if ((client_socket_fd = accept(server_socket_fd, (struct sockaddr *)&client_addr, (socklen_t *)&addrlen)) < 0) {
            printf("Accept error\n");
            exit(EXIT_FAILURE);
        }

        printf("Accepted connection from %s:%d\n",
            inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Spawn child process to handle incoming connection
        if (fork() == 0) {
            close(server_socket_fd);

            handle_connection(client_socket_fd, client_addr);

            exit(0);
        } else {
            close(client_socket_fd);
        }
    }

    close(server_socket_fd);

    return 0;
}