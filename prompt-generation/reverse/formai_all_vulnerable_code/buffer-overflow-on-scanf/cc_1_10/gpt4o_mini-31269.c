//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 587 // SMTP port
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int send_command(int sockfd, const char *command, char *response) {
    send(sockfd, command, strlen(command), 0);
    recv(sockfd, response, BUFFER_SIZE, 0);
    return atoi(response);
}

void send_email(int sockfd, const char *from, const char *to, const char *subject, const char *body) {
    char buffer[BUFFER_SIZE];

    // Send HELO command
    sprintf(buffer, "EHLO localhost\r\n");
    if (send_command(sockfd, buffer, buffer) != 250) {
        error("Failed to send EHLO");
    }

    // Authorization (usually use base64 encoding)
    sprintf(buffer, "AUTH LOGIN\r\n");
    if (send_command(sockfd, buffer, buffer) != 334) {
        error("Failed to request AUTH LOGIN");
    }
    
    // Username and password would typically be encoded in real usage
    sprintf(buffer, "<base64-username>\r\n"); 
    if (send_command(sockfd, buffer, buffer) != 334) {
        error("Failed to send username");
    }

    sprintf(buffer, "<base64-password>\r\n");
    if (send_command(sockfd, buffer, buffer) != 235) {
        error("Failed to send password");
    }

    // From Address
    sprintf(buffer, "MAIL FROM:<%s>\r\n", from);
    if (send_command(sockfd, buffer, buffer) != 250) {
        error("Failed to set sender");
    }

    // To Address
    sprintf(buffer, "RCPT TO:<%s>\r\n", to);
    if (send_command(sockfd, buffer, buffer) != 250) {
        error("Failed to set recipient");
    }

    // DATA
    sprintf(buffer, "DATA\r\n");
    if (send_command(sockfd, buffer, buffer) != 354) {
        error("Failed to send DATA command");
    }

    // Email body
    sprintf(buffer, "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    if (send_command(sockfd, buffer, buffer) != 250) {
        error("Failed to send email data");
    }

    // Quit command
    sprintf(buffer, "QUIT\r\n");
    send_command(sockfd, buffer, buffer);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    char from[100], to[100], subject[100], body[500];
    
    // Getting user input
    printf("Enter your email: ");
    scanf("%s", from);
    printf("Enter recipient email: ");
    scanf("%s", to);
    printf("Enter subject: ");
    getchar(); // To consume newline left by previous scanf
    fgets(subject, sizeof(subject), stdin);
    subject[strcspn(subject, "\n")] = 0; // Remove newline
    printf("Enter body: ");
    fgets(body, sizeof(body), stdin);
    body[strcspn(body, "\n")] = 0; // Remove newline

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    // Setup server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost SMTP server

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }

    // Send email
    send_email(sockfd, from, to, subject, body);

    // Clean up
    close(sockfd);
    printf("Email sent successfully!\n");

    return 0;
}