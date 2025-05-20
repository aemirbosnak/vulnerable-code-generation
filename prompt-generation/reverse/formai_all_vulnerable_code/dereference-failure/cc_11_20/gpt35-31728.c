//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 2048

int main(int argc, char *argv[]) {
    int socket_fd, port_number, server_len, bytes_sent;
    struct sockaddr_in server_address;
    struct hostent *server_info;
    char buffer[BUFFER_SIZE];

    // Check command line arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the address of the server
    server_info = gethostbyname(argv[1]);
    if (server_info == NULL) {
        fprintf(stderr, "Error: %s not found\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Set up the server address struct
    bzero((char *) &server_address, sizeof(server_address));
    port_number = atoi(argv[2]);
    server_address.sin_family = AF_INET;
    bcopy((char *) server_info->h_addr, (char *) &server_address.sin_addr.s_addr, server_info->h_length);
    server_address.sin_port = htons(port_number);

    // Create the socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Read greeting message from server
    bzero(buffer, BUFFER_SIZE);
    if (read(socket_fd, buffer, BUFFER_SIZE) < 0) {
        perror("Error reading from server");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    // Send HELO message to server
    bzero(buffer, BUFFER_SIZE);
    snprintf(buffer, BUFFER_SIZE, "HELO %s\r\n", argv[1]);
    bytes_sent = send(socket_fd, buffer, strlen(buffer), 0);
    if (bytes_sent < 0) {
        perror("Error sending message to server");
        exit(EXIT_FAILURE);
    }

    // Read reply from server
    bzero(buffer, BUFFER_SIZE);
    if (read(socket_fd, buffer, BUFFER_SIZE) < 0) {
        perror("Error reading from server");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    // Send MAIL FROM message to server
    bzero(buffer, BUFFER_SIZE);
    snprintf(buffer, BUFFER_SIZE, "MAIL FROM: <%s>\r\n", "sender@example.com");
    bytes_sent = send(socket_fd, buffer, strlen(buffer), 0);
    if (bytes_sent < 0) {
        perror("Error sending message to server");
        exit(EXIT_FAILURE);
    }

    // Read reply from server
    bzero(buffer, BUFFER_SIZE);
    if (read(socket_fd, buffer, BUFFER_SIZE) < 0) {
        perror("Error reading from server");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    // Send RCPT TO message to server
    bzero(buffer, BUFFER_SIZE);
    snprintf(buffer, BUFFER_SIZE, "RCPT TO: <%s>\r\n", "recipient@example.com");
    bytes_sent = send(socket_fd, buffer, strlen(buffer), 0);
    if (bytes_sent < 0) {
        perror("Error sending message to server");
        exit(EXIT_FAILURE);
    }

    // Read reply from server
    bzero(buffer, BUFFER_SIZE);
    if (read(socket_fd, buffer, BUFFER_SIZE) < 0) {
        perror("Error reading from server");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    // Send DATA message to server
    bzero(buffer, BUFFER_SIZE);
    snprintf(buffer, BUFFER_SIZE, "DATA\r\n");
    bytes_sent = send(socket_fd, buffer, strlen(buffer), 0);
    if (bytes_sent < 0) {
        perror("Error sending message to server");
        exit(EXIT_FAILURE);
    }

    // Read reply from server
    bzero(buffer, BUFFER_SIZE);
    if (read(socket_fd, buffer, BUFFER_SIZE) < 0) {
        perror("Error reading from server");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    // Send message body to server
    bzero(buffer, BUFFER_SIZE);
    snprintf(buffer, BUFFER_SIZE, "Subject: Test message\r\n\r\nThis is a test message.\r\n.\r\n");
    bytes_sent = send(socket_fd, buffer, strlen(buffer), 0);
    if (bytes_sent < 0) {
        perror("Error sending message to server");
        exit(EXIT_FAILURE);
    }

    // Read reply from server
    bzero(buffer, BUFFER_SIZE);
    if (read(socket_fd, buffer, BUFFER_SIZE) < 0) {
        perror("Error reading from server");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    // Send QUIT message to server
    bzero(buffer, BUFFER_SIZE);
    snprintf(buffer, BUFFER_SIZE, "QUIT\r\n");
    bytes_sent = send(socket_fd, buffer, strlen(buffer), 0);
    if (bytes_sent < 0) {
        perror("Error sending message to server");
        exit(EXIT_FAILURE);
    }

    // Read reply from server
    bzero(buffer, BUFFER_SIZE);
    if (read(socket_fd, buffer, BUFFER_SIZE) < 0) {
        perror("Error reading from server");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    // Close the socket
    close(socket_fd);

    return 0;
}