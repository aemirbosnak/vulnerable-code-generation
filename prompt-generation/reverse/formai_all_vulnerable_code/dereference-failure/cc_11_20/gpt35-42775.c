//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024 // Maximum size of buffer

int main(int argc, char *argv[]) {

    // Check input arguments
    if (argc != 3) {
        printf("Usage: %s smtp_server_address smtp_port_number\n", argv[0]);
        exit(1);
    }

    // Get SMTP server address and port number from input
    char *server_address = argv[1];
    int server_port = atoi(argv[2]);

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    // Connect to SMTP server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    if (inet_pton(AF_INET, server_address, &server_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(1);
    }
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        exit(1);
    }

    // Receive server greeting message
    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));
    if (recv(sock, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive server greeting");
        exit(1);
    }
    printf("Server message: %s", buffer);

    // Send HELO message to server
    char *helo_message = "HELO example.com\r\n";
    if (send(sock, helo_message, strlen(helo_message), 0) < 0) {
        perror("Failed to send HELO message");
        exit(1);
    }
    printf("Sent message: %s", helo_message);

    // Receive server response to HELO message
    memset(buffer, 0, sizeof(buffer));
    if (recv(sock, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive server response");
        exit(1);
    }
    printf("Server message: %s", buffer);

    // Send MAIL FROM message to server
    char *mail_from_message = "MAIL FROM: <sender@example.com>\r\n";
    if (send(sock, mail_from_message, strlen(mail_from_message), 0) < 0) {
        perror("Failed to send MAIL FROM message");
        exit(1);
    }
    printf("Sent message: %s", mail_from_message);

    // Receive server response to MAIL FROM message
    memset(buffer, 0, sizeof(buffer));
    if (recv(sock, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive server response");
        exit(1);
    }
    printf("Server message: %s", buffer);

    // Send RCPT TO message to server
    char *rcpt_to_message = "RCPT TO: <recipient@example.com>\r\n";
    if (send(sock, rcpt_to_message, strlen(rcpt_to_message), 0) < 0) {
        perror("Failed to send RCPT TO message");
        exit(1);
    }
    printf("Sent message: %s", rcpt_to_message);

    // Receive server response to RCPT TO message
    memset(buffer, 0, sizeof(buffer));
    if (recv(sock, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive server response");
        exit(1);
    }
    printf("Server message: %s", buffer);

    // Send DATA message to server
    char *data_message = "DATA\r\n";
    if (send(sock, data_message, strlen(data_message), 0) < 0) {
        perror("Failed to send DATA message");
        exit(1);
    }
    printf("Sent message: %s", data_message);

    // Receive server response to DATA message
    memset(buffer, 0, sizeof(buffer));
    if (recv(sock, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive server response");
        exit(1);
    }
    printf("Server message: %s", buffer);

    // Send email message to server
    char *email_message = "Subject: Test\r\n\r\nHello!\r\n.\r\n";
    if (send(sock, email_message, strlen(email_message), 0) < 0) {
        perror("Failed to send email message");
        exit(1);
    }
    printf("Sent message: %s", email_message);

    // Receive server response to email message
    memset(buffer, 0, sizeof(buffer));
    if (recv(sock, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive server response");
        exit(1);
    }
    printf("Server message: %s", buffer);

    // Send QUIT message to server
    char *quit_message = "QUIT\r\n";
    if (send(sock, quit_message, strlen(quit_message), 0) < 0) {
        perror("Failed to send QUIT message");
        exit(1);
    }
    printf("Sent message: %s", quit_message);

    // Receive server response to QUIT message
    memset(buffer, 0, sizeof(buffer));
    if (recv(sock, buffer, MAX_BUFFER_SIZE, 0) < 0) {
        perror("Failed to receive server response");
        exit(1);
    }
    printf("Server message: %s", buffer);

    // Close socket
    close(sock);

    return 0;
}