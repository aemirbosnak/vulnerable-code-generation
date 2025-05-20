//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 4096

int main(int argc, char *argv[]) {

    // Check parameters
    if (argc < 3) {
        printf("Usage: %s <server_ip_address> <server_port_number>\n", argv[0]);
        exit(1);
    }

    // Initialize socket
    int socket_fd;
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    // Set server address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0) {
        perror("Invalid IP address");
        exit(1);
    }

    // Connect to server
    if (connect(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Failed to connect to server");
        exit(1);
    }

    // Send HELO command
    char buffer[MAX_BUFFER_SIZE];
    sprintf(buffer, "HELO %s\r\n", argv[1]);
    if (send(socket_fd, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send HELO command");
        exit(1);
    }

    // Receive HELO response
    if (recv(socket_fd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive HELO response");
        exit(1);
    }
    printf("%s", buffer);

    // Send MAIL FROM command
    sprintf(buffer, "MAIL FROM: <sender@example.com>\r\n");
    if (send(socket_fd, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send MAIL FROM command");
        exit(1);
    }

    // Receive MAIL FROM response
    if (recv(socket_fd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive MAIL FROM response");
        exit(1);
    }
    printf("%s", buffer);

    // Send RCPT TO command
    sprintf(buffer, "RCPT TO: <recipient@example.com>\r\n");
    if (send(socket_fd, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send RCPT TO command");
        exit(1);
    }

    // Receive RCPT TO response
    if (recv(socket_fd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive RCPT TO response");
        exit(1);
    }
    printf("%s", buffer);

    // Send DATA command
    sprintf(buffer, "DATA\r\n");
    if (send(socket_fd, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send DATA command");
        exit(1);
    }

    // Receive DATA response
    if (recv(socket_fd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive DATA response");
        exit(1);
    }
    printf("%s", buffer);

    // Send message
    sprintf(buffer, "From: sender@example.com\r\nTo: recipient@example.com\r\nSubject: Test message\r\n\r\nThis is a test message\r\n.\r\n");
    if (send(socket_fd, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send message");
        exit(1);
    }

    // Receive message sent confirmation
    if (recv(socket_fd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive message sent confirmation");
        exit(1);
    }
    printf("%s", buffer);

    // Send QUIT command
    sprintf(buffer, "QUIT\r\n");
    if (send(socket_fd, buffer, strlen(buffer), 0) < 0) {
        perror("Failed to send QUIT command");
        exit(1);
    }

    // Receive QUIT response
    if (recv(socket_fd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive QUIT response");
        exit(1);
    }
    printf("%s", buffer);

    // Close socket
    close(socket_fd);

    return 0;
}