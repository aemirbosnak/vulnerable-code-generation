//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

int main() {
    // Define the SMTP server address and port
    char *server_address = "mail.example.com";
    int port = 25;

    // Create a socket for communication with the SMTP server
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Resolve the server address
    struct hostent *server = gethostbyname(server_address);
    if (server == NULL) {
        perror("Error resolving server address");
        exit(1);
    }

    // Create a sockaddr_in structure for the server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, server->h_addr, server->h_length);

    // Connect to the SMTP server
    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Receive the server's greeting
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    if (recv(socket_fd, buffer, sizeof(buffer), 0) < 0) {
        perror("Error receiving server greeting");
        exit(1);
    }
    printf("Server greeting: %s\n", buffer);

    // Send the HELO command
    memset(buffer, 0, sizeof(buffer));
    snprintf(buffer, sizeof(buffer), "HELO %s\r\n", server_address);
    if (send(socket_fd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending HELO command");
        exit(1);
    }

    // Receive the server's response to the HELO command
    memset(buffer, 0, sizeof(buffer));
    if (recv(socket_fd, buffer, sizeof(buffer), 0) < 0) {
        perror("Error receiving server response to HELO command");
        exit(1);
    }
    printf("Server response to HELO command: %s\n", buffer);

    // Send the MAIL FROM command
    memset(buffer, 0, sizeof(buffer));
    snprintf(buffer, sizeof(buffer), "MAIL FROM: <sender@example.com>\r\n");
    if (send(socket_fd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending MAIL FROM command");
        exit(1);
    }

    // Receive the server's response to the MAIL FROM command
    memset(buffer, 0, sizeof(buffer));
    if (recv(socket_fd, buffer, sizeof(buffer), 0) < 0) {
        perror("Error receiving server response to MAIL FROM command");
        exit(1);
    }
    printf("Server response to MAIL FROM command: %s\n", buffer);

    // Send the RCPT TO command
    memset(buffer, 0, sizeof(buffer));
    snprintf(buffer, sizeof(buffer), "RCPT TO: <recipient@example.com>\r\n");
    if (send(socket_fd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending RCPT TO command");
        exit(1);
    }

    // Receive the server's response to the RCPT TO command
    memset(buffer, 0, sizeof(buffer));
    if (recv(socket_fd, buffer, sizeof(buffer), 0) < 0) {
        perror("Error receiving server response to RCPT TO command");
        exit(1);
    }
    printf("Server response to RCPT TO command: %s\n", buffer);

    // Send the DATA command
    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer, "DATA\r\n");
    if (send(socket_fd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending DATA command");
        exit(1);
    }

    // Receive the server's response to the DATA command
    memset(buffer, 0, sizeof(buffer));
    if (recv(socket_fd, buffer, sizeof(buffer), 0) < 0) {
        perror("Error receiving server response to DATA command");
        exit(1);
    }
    printf("Server response to DATA command: %s\n", buffer);

    // Send the email message
    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer, "Subject: Test email\r\n\r\nThis is a test email. Please ignore.\r\n.\r\n");
    if (send(socket_fd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending email message");
        exit(1);
    }

    // Receive the server's response to the email message
    memset(buffer, 0, sizeof(buffer));
    if (recv(socket_fd, buffer, sizeof(buffer), 0) < 0) {
        perror("Error receiving server response to email message");
        exit(1);
    }
    printf("Server response to email message: %s\n", buffer);

    // Send the QUIT command
    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer, "QUIT\r\n");
    if (send(socket_fd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending QUIT command");
        exit(1);
    }

    // Receive the server's response to the QUIT command
    memset(buffer, 0, sizeof(buffer));
    if (recv(socket_fd, buffer, sizeof(buffer), 0) < 0) {
        perror("Error receiving server response to QUIT command");
        exit(1);
    }
    printf("Server response to QUIT command: %s\n", buffer);

    // Close the socket
    close(socket_fd);

    return 0;
}