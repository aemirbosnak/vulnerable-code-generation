//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Function to send a message from the server to the client
void send_message(int sockfd, char *message) {
    send(sockfd, message, strlen(message), 0);
}

// Function to receive a message from the client
char *receive_message(int sockfd) {
    char buf[1024];
    int bytes_recv = recv(sockfd, buf, sizeof(buf), 0);
    if (bytes_recv < 0) {
        perror("Error receiving message");
        exit(1);
    }
    buf[bytes_recv] = '\0'; // null-terminate the string
    return buf;
}

int main() {
    int server_fd, client_fd;
    char *message;

    // Create a socket for the server
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Error creating socket");
        exit(1);
    }

    // Set up server address structure
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345); // arbitrary port number
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the server address
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding to socket");
        exit(1);
    }

    // Start listening for incoming connections
    if (listen(server_fd, 5) == -1) {
        perror("Error listening on socket");
        exit(1);
    }

    // Accept incoming connection from client
    client_fd = accept(server_fd, NULL, NULL);
    if (client_fd == -1) {
        perror("Error accepting connection");
        exit(1);
    }

    // Send a message to the client
    send_message(client_fd, "Hello, client!\n");

    // Receive a message from the client
    message = receive_message(client_fd);
    printf("Received message: %s\n", message);

    // Clean up
    close(server_fd);
    close(client_fd);
    return 0;
}