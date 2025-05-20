//FormAI DATASET v1.0 Category: Client Server Application ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

void handle_connection(int socket_fd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Receive message from client
    while ((bytes_received = recv(socket_fd, buffer, BUFFER_SIZE, 0)) > 0) {
        // Null-terminate the buffer string
        buffer[bytes_received] = '\0';

        // Print client's message
        printf("Received: %s\n", buffer);

        // Send response to client
        char response[BUFFER_SIZE] = "Server received your message: ";
        strcat(response, buffer);
        send(socket_fd, response, strlen(response), 0);
    }

    // If recv() returns 0, it means the client has disconnected
    if (bytes_received == 0) {
        printf("Client disconnected\n");
    } else {
        printf("recv() failed: %s\n", strerror(errno));
    }

    close(socket_fd);
}

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    char client_ip[INET_ADDRSTRLEN];

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("socket() failed: %s\n", strerror(errno));
        exit(1);
    }

    // Configure server address/port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8080);

    // Bind server socket to configured address/port
    if (bind(server_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
        printf("bind() failed: %s\n", strerror(errno));
        exit(1);
    }

    // Listen for incoming client connections
    if (listen(server_fd, MAX_CLIENTS) == -1) {
        printf("listen() failed: %s\n", strerror(errno));
        exit(1);
    }

    printf("Server started. Listening on port %d\n", ntohs(server_addr.sin_port));

    // Main server loop
    while (1) {
        // Accept incoming client connection
        if ((client_fd = accept(server_fd, (struct sockaddr*) &client_addr, &client_addr_len)) == -1) {
            printf("accept() failed: %s\n", strerror(errno));
            continue;
        }

        // Convert client's IP address to string format
        inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);

        printf("Client connected from %s:%d\n", client_ip, ntohs(client_addr.sin_port));

        // Handle client connection in a new thread
        if (fork() == 0) {
            handle_connection(client_fd);
            exit(0);
        }

        // Close client socket (parent process)
        close(client_fd);
    }

    // Close server socket (should never reach here)
    close(server_fd);

    return 0;
}