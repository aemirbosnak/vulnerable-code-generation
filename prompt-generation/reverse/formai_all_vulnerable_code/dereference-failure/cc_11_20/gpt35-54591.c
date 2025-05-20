//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {

    // Check if the user has provided enough arguments
    if (argc != 4) {
        printf("Usage: %s <server_ip> <port> <username>\n", argv[0]);
        return 0;
    }

    // Get the server IP and port from the command line arguments
    char* server_ip = argv[1];
    int port = atoi(argv[2]);
    char* username = argv[3];

    // Create a socket to connect to the server
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    // Create a structure to store the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    inet_pton(AF_INET, server_ip, &server_address.sin_addr);

    // Connect to the server
    if (connect(sock, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Failed to connect to server");
        return 0;
    }

    // Receive the server's greeting message
    char response_buffer[BUFFER_SIZE];
    ssize_t bytes_received = recv(sock, response_buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("Failed to receive greeting message");
        return 0;
    }

    // Print the server's greeting message
    printf("Server: %.*s\n", (int)bytes_received, response_buffer);

    // Send the user's credentials to the server
    char auth_buffer[BUFFER_SIZE];
    sprintf(auth_buffer, "USER %s\r\n", username);
    if (send(sock, auth_buffer, strlen(auth_buffer), 0) == -1) {
        perror("Failed to send USER command");
        return 0;
    }

    bytes_received = recv(sock, response_buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("Failed to receive response to USER command");
        return 0;
    }

    printf("Server: %.*s\n", (int)bytes_received, response_buffer);

    // Prompt the user for their password
    char password[100];
    printf("Password: ");
    fgets(password, 100, stdin);
    password[strlen(password)-1] = '\0'; // Remove the newline character

    // Send the user's password to the server
    sprintf(auth_buffer, "PASS %s\r\n", password);
    if (send(sock, auth_buffer, strlen(auth_buffer), 0) == -1) {
        perror("Failed to send PASS command");
        return 0;
    }

    bytes_received = recv(sock, response_buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("Failed to receive response to PASS command");
        return 0;
    }

    printf("Server: %.*s\n", (int)bytes_received, response_buffer);

    // Send the LIST command to get a list of messages
    memset(auth_buffer, 0, BUFFER_SIZE); // Clear the buffer
    sprintf(auth_buffer, "LIST\r\n");
    if (send(sock, auth_buffer, strlen(auth_buffer), 0) == -1) {
        perror("Failed to send LIST command");
        return 0;
    }

    bytes_received = recv(sock, response_buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("Failed to receive response to LIST command");
        return 0;
    }

    printf("Server: %.*s\n", (int)bytes_received, response_buffer);

    // Send the QUIT command to disconnect from the server
    memset(auth_buffer, 0, BUFFER_SIZE); // Clear the buffer
    sprintf(auth_buffer, "QUIT\r\n");
    if (send(sock, auth_buffer, strlen(auth_buffer), 0) == -1) {
        perror("Failed to send QUIT command");
        return 0;
    }

    bytes_received = recv(sock, response_buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        perror("Failed to receive response to QUIT command");
        return 0;
    }

    printf("Server: %.*s\n", (int)bytes_received, response_buffer);

    // Close the socket
    close(sock);

    return 0;
}