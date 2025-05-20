//FormAI DATASET v1.0 Category: Client Server Application ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main(int argc, char const *argv[]) {

    // Create a socket file descriptor
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Socket options set failed");
        exit(EXIT_FAILURE);
    }

    // Server address configuration
    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to an address
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    int addrlen = sizeof(address);
    int client_fd = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
    if (client_fd < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Communication with the client
    char buffer[1024] = {0};
    char message[1024] = "Hello from the server!";
    while (1) {

        // Receive message from the client
        int bytes_read = recv(client_fd, buffer, 1024, 0);
        if (bytes_read < 0) {
            perror("Receive failed");
            exit(EXIT_FAILURE);
        }

        // Print the received message
        buffer[bytes_read] = '\0';
        printf("Client: %s\n", buffer);

        // Send message to the client
        if (send(client_fd, message, strlen(message), 0) < 0) {
            perror("Send failed");
            exit(EXIT_FAILURE);
        }
    }

    // Close the communication with the client
    close(client_fd);
    close(server_fd);

    return 0;
}