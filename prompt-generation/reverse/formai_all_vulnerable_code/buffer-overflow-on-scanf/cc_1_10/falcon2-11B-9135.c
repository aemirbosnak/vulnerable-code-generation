//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Function to handle incoming connections from clients
void server_function(int socket_fd, int port) {
    char buffer[1024];
    int n;

    printf("Waiting for incoming connections...\n");

    // Accept incoming connections from clients
    while (1) {
        int client_fd = accept(socket_fd, NULL, NULL);
        if (client_fd < 0) {
            perror("accept");
            exit(1);
        }

        // Receive data from the client
        while ((n = recv(client_fd, buffer, sizeof(buffer), 0)) > 0) {
            printf("Received data: %s\n", buffer);
            send(client_fd, buffer, n, 0);
        }

        // Close the client connection
        close(client_fd);
    }
}

// Function to send data to the server
void client_function(int socket_fd, int port) {
    char buffer[1024];

    // Send data to the server
    printf("Sending data to server...\n");
    sprintf(buffer, "Hello from the client!");
    send(socket_fd, buffer, sizeof(buffer), 0);

    // Receive response from the server
    printf("Waiting for response...\n");
    recv(socket_fd, buffer, sizeof(buffer), 0);
    printf("Received response: %s\n", buffer);
}

// Main menu
int main() {
    int server_port = 8080;
    int client_port = 8080;
    int socket_fd;
    struct sockaddr_in server_addr, client_addr;
    int addrlen;

    printf("1. Start server\n2. Start client\n3. Exit\n");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            // Create a socket for the server
            socket_fd = socket(AF_INET, SOCK_STREAM, 0);
            if (socket_fd < 0) {
                perror("socket");
                exit(1);
            }

            // Set up server address and port
            server_addr.sin_family = AF_INET;
            server_addr.sin_addr.s_addr = INADDR_ANY;
            server_addr.sin_port = htons(server_port);

            // Bind the socket to the server address and port
            if (bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
                perror("bind");
                exit(1);
            }

            // Listen for incoming connections
            if (listen(socket_fd, 5) < 0) {
                perror("listen");
                exit(1);
            }

            // Start the server
            server_function(socket_fd, server_port);
            break;
        case 2:
            // Create a socket for the client
            socket_fd = socket(AF_INET, SOCK_STREAM, 0);
            if (socket_fd < 0) {
                perror("socket");
                exit(1);
            }

            // Set up client address and port
            client_addr.sin_family = AF_INET;
            client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
            client_addr.sin_port = htons(client_port);

            // Connect to the server
            if (connect(socket_fd, (struct sockaddr *)&client_addr, sizeof(client_addr)) < 0) {
                perror("connect");
                exit(1);
            }

            // Send data to the server
            client_function(socket_fd, client_port);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}