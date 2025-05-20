//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 25
#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int sock_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char message[BUFFER_SIZE];
    char sender[50];
    char receiver[50];

    // Prompt user for email sender and receiver
    printf("Enter sender email address: ");
    scanf("%s", sender);
    printf("Enter receiver email address: ");
    scanf("%s", receiver);

    // Create socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Error creating socket");
        return EXIT_FAILURE;
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // Connect to server
    if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        return EXIT_FAILURE;
    }

    // Receive server response
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sock_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving response from server");
        return EXIT_FAILURE;
    }

    printf("Server response: %s\n", buffer);

    // Send HELO command
    snprintf(message, BUFFER_SIZE, "HELO %s\r\n", "myhost");
    if (send(sock_fd, message, strlen(message), 0) < 0) {
        perror("Error sending HELO command to server");
        return EXIT_FAILURE;
    }

    // Receive server response
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sock_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving response from server");
        return EXIT_FAILURE;
    }

    printf("Server response: %s\n", buffer);

    // Send MAIL FROM command
    memset(message, 0, BUFFER_SIZE);
    snprintf(message, BUFFER_SIZE, "MAIL FROM:<%s>\r\n", sender);
    if (send(sock_fd, message, strlen(message), 0) < 0) {
        perror("Error sending MAIL FROM command to server");
        return EXIT_FAILURE;
    }

    // Receive server response
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sock_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving response from server");
        return EXIT_FAILURE;
    }

    printf("Server response: %s\n", buffer);

    // Send RCPT TO command
    memset(message, 0, BUFFER_SIZE);
    snprintf(message, BUFFER_SIZE, "RCPT TO:<%s>\r\n", receiver);
    if (send(sock_fd, message, strlen(message), 0) < 0) {
        perror("Error sending RCPT TO command to server");
        return EXIT_FAILURE;
    }

    // Receive server response
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sock_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving response from server");
        return EXIT_FAILURE;
    }

    printf("Server response: %s\n", buffer);

    // Send DATA command
    if (send(sock_fd, "DATA\r\n", strlen("DATA\r\n"), 0) < 0) {
        perror("Error sending DATA command to server");
        return EXIT_FAILURE;
    }

    // Receive server response
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sock_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving response from server");
        return EXIT_FAILURE;
    }

    printf("Server response: %s\n", buffer);

    // Prompt user for message body
    printf("Enter message body:\n");
    memset(message, 0, BUFFER_SIZE);
    scanf(" %[^\n]s", message);

    // Send message body
    snprintf(buffer, BUFFER_SIZE, "Subject: SMTP Client Example\r\nFrom: %s\r\nTo: %s\r\n\r\n%s\r\n.\r\n", sender, receiver, message);
    if (send(sock_fd, buffer, strlen(buffer), 0) < 0) {
        perror("Error sending message body to server");
        return EXIT_FAILURE;
    }

    // Receive server response
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sock_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving response from server");
        return EXIT_FAILURE;
    }

    printf("Server response: %s\n", buffer);

    // Send QUIT command
    if (send(sock_fd, "QUIT\r\n", strlen("QUIT\r\n"), 0) < 0) {
        perror("Error sending QUIT command to server");
        return EXIT_FAILURE;
    }

    // Receive server response
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sock_fd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error receiving response from server");
        return EXIT_FAILURE;
    }

    printf("Server response: %s\n", buffer);

    // Close socket
    close(sock_fd);

    return 0;
}