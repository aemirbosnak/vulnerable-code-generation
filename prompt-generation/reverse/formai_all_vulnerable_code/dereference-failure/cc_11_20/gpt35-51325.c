//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <IMAP_Server_IP> <IMAP_Server_Port> <Username>\n", argv[0]);
        return 1;
    }
    
    // Parse command line arguments
    char *server_ip = argv[1];
    int server_port = atoi(argv[2]);
    char *username = argv[3];

    // Create a TCP socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("Failed to create socket");
        return 1;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) != 1) {
        perror("Failed to parse server IP");
        return 1;
    }

    if (connect(socket_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
        perror("Failed to connect to server");
        return 1;
    }

    // Read initial server response
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    ssize_t bytes_read = recv(socket_fd, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_read == -1) {
        perror("Failed to receive data");
        return 1;
    }

    printf("%s", buffer);

    // Send login command
    char login_command[BUFFER_SIZE];
    snprintf(login_command, BUFFER_SIZE - 1, "a001 LOGIN %s\r\n", username);
    ssize_t bytes_written = send(socket_fd, login_command, strlen(login_command), 0);
    if (bytes_written == -1) {
        perror("Failed to send data");
        return 1;
    }

    // Read server response to login command
    memset(buffer, 0, BUFFER_SIZE);
    bytes_read = recv(socket_fd, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_read == -1) {
        perror("Failed to receive data");
        return 1;
    }

    printf("%s", buffer);

    // Send list command to get mailbox list
    char list_command[BUFFER_SIZE];
    snprintf(list_command, BUFFER_SIZE - 1, "a002 LIST \"\" *\r\n");
    bytes_written = send(socket_fd, list_command, strlen(list_command), 0);
    if (bytes_written == -1) {
        perror("Failed to send data");
        return 1;
    }

    // Read server response to list command
    memset(buffer, 0, BUFFER_SIZE);
    bytes_read = recv(socket_fd, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_read == -1) {
        perror("Failed to receive data");
        return 1;
    }

    printf("%s", buffer);

    // Close the connection
    snprintf(buffer, BUFFER_SIZE - 1, "a003 LOGOUT\r\n");
    bytes_written = send(socket_fd, buffer, strlen(buffer), 0);
    if (bytes_written == -1) {
        perror("Failed to send data");
        return 1;
    }

    memset(buffer, 0, BUFFER_SIZE);
    bytes_read = recv(socket_fd, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_read == -1) {
        perror("Failed to receive data");
        return 1;
    }

    printf("%s", buffer);

    close(socket_fd);

    return 0;
}