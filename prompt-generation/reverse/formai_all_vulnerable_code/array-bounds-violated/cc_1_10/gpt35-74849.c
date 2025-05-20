//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    size_t bytes_sent, bytes_received;

    // Check if user provided enough arguments
    if (argc < 3) {
        printf("Usage: %s IP PORT\n", argv[0]);
        return 1;
    }

    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Error creating socket");
        return 1;
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) == 0) {
        perror("Invalid IP address");
        return 1;
    }

    // Connect to server
    if (connect(client_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting to server");
        return 1;
    }

    // Receive welcome message from server
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("Error receiving welcome message from server");
        return 1;
    }

    // Print welcome message
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Read command from user
    printf("> ");
    fgets(buffer, BUFFER_SIZE, stdin);

    // Strip newline character from command
    buffer[strcspn(buffer, "\n")] = '\0';

    // Send command to server
    bytes_sent = send(client_socket, buffer, strlen(buffer), 0);
    if (bytes_sent == -1) {
        perror("Error sending command to server");
        return 1;
    }

    // Receive response from server
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("Error receiving response from server");
        return 1;
    }

    // Print response
    buffer[bytes_received] = '\0';
    printf("%s", buffer);

    // Close socket
    close(client_socket);

    return 0;
}