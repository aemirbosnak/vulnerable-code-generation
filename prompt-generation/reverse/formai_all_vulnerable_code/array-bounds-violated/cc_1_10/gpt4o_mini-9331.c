//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>

#define SMTP_PORT 587
#define BUFFER_SIZE 1024

void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
    printf(">>> %s", cmd);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    buffer[n] = '\0';
    printf("<<< %s", buffer);
}

int main() {
    const char *smtp_server = "smtp.example.com"; // Replace with your SMTP server
    const char *username = "user@example.com";     // Replace with your email
    const char *password = "yourpassword";         // Replace with your password
    const char *recipient = "recipient@example.com"; // Recipient email
    const char *subject = "Hello from SMTP Client";
    const char *body = "This is a test email sent from a simple SMTP client written in C.";

    // Create socket
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error creating socket.\n");
        return 1;
    }

    // Server address configuration
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    inet_pton(AF_INET, smtp_server, &server_addr.sin_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Connection to SMTP server failed.\n");
        close(sockfd);
        return 1;
    }

    // Receive server greeting
    receive_response(sockfd);

    // EHLO command
    send_command(sockfd, "EHLO localhost\r\n");
    receive_response(sockfd);

    // AUTH LOGIN
    send_command(sockfd, "AUTH LOGIN\r\n");
    receive_response(sockfd);

    // Send username
    char encoded_username[BUFFER_SIZE];
    snprintf(encoded_username, sizeof(encoded_username), "%s\r\n", username); // Assuming base64 encoding is done beforehand
    send_command(sockfd, encoded_username);
    receive_response(sockfd);

    // Send password
    char encoded_password[BUFFER_SIZE];
    snprintf(encoded_password, sizeof(encoded_password), "%s\r\n", password); // Assuming base64 encoding is done beforehand
    send_command(sockfd, encoded_password);
    receive_response(sockfd);

    // MAIL FROM
    char mail_from[BUFFER_SIZE];
    snprintf(mail_from, sizeof(mail_from), "MAIL FROM:<%s>\r\n", username);
    send_command(sockfd, mail_from);
    receive_response(sockfd);

    // RCPT TO
    char rcpt_to[BUFFER_SIZE];
    snprintf(rcpt_to, sizeof(rcpt_to), "RCPT TO:<%s>\r\n", recipient);
    send_command(sockfd, rcpt_to);
    receive_response(sockfd);

    // DATA command
    send_command(sockfd, "DATA\r\n");
    receive_response(sockfd);

    // Email headers and body
    char email_data[BUFFER_SIZE * 2];
    snprintf(email_data, sizeof(email_data),
             "From: %s\r\n"
             "To: %s\r\n"
             "Subject: %s\r\n"
             "\r\n"
             "%s\r\n"
             ".\r\n", username, recipient, subject, body);

    // Send email data
    send_command(sockfd, email_data);
    receive_response(sockfd);

    // QUIT command
    send_command(sockfd, "QUIT\r\n");
    receive_response(sockfd);

    // Close the socket
    close(sockfd);
    return 0;
}