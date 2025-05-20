//FormAI DATASET v1.0 Category: Simple Web Server ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

/* Function to handle incoming client connections */
void handle_client(int client_fd) {
    char buffer[BUFFER_SIZE];
    int num_bytes = recv(client_fd, buffer, BUFFER_SIZE, 0);
    if (num_bytes <= 0) {
        perror("recv");
        close(client_fd);
        return;
    }

    // Null-terminate the received data to turn it into a string
    buffer[num_bytes] = '\0';

    // Construct a response to send back to the client
    char response[BUFFER_SIZE];
    sprintf(response, "HTTP/1.1 200 OK\n\nHello, client! You said: %s\n", buffer);

    // Send the response to the client
    send(client_fd, response, strlen(response), 0);

    // Close the connection to the client
    close(client_fd);
}

/* Function to accept incoming client connections and handle each one */
void run_server(int server_fd) {
    while (1) {
        // Accept incoming client connections
        int client_fd = accept(server_fd, NULL, NULL);
        if (client_fd < 0) {
            perror("accept");
            continue;
        }

        // Handle the client connection in a separate process
        int pid = fork();
        if (pid < 0) {
            perror("fork");
            close(client_fd);
            continue;
        } else if (pid == 0) {
            // Child process
            handle_client(client_fd);
            exit(0);
        } else {
            // Parent process
            close(client_fd);
            continue;
        }
    }
}

/* Function to create the server socket and listen for incoming connections */
int start_server() {
    // Create the server socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        exit(1);
    }

    // Bind the server socket to a port
    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming client connections
    if (listen(server_fd, SOMAXCONN) < 0) {
        perror("listen");
        exit(1);
    }

    return server_fd;
}

/* Main function */
int main() {
    // Create the server socket and listen for incoming connections
    int server_fd = start_server();

    // Handle incoming client connections recursively
    run_server(server_fd);

    // Close the server socket
    close(server_fd);

    return 0;
}