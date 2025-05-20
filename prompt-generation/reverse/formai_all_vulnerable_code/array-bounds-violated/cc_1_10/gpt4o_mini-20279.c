//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SMTP_PORT 587 // SMTP port for TLS
#define BUFFER_SIZE 1024

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    printf("Sent: %s", command);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    buffer[bytes_received] = '\0';
    printf("Received: %s", buffer);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    
    const char *smtp_server = "smtp.example.com"; // Replace with your SMTP server
    const char *email_from = "sender@example.com"; // Replace with the sender's email
    const char *email_to = "recipient@example.com"; // Replace with the recipient's email
    const char *subject = "Test Email";
    const char *message_body = "Hello, this is a test email sent from a C SMTP client!";

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    inet_pton(AF_INET, smtp_server, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to the SMTP server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    receive_response(sockfd);
    
    // EHLO command
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "EHLO localhost\r\n");
    send_command(sockfd, command);
    receive_response(sockfd);
    
    // AUTH LOGIN
    snprintf(command, sizeof(command), "AUTH LOGIN\r\n");
    send_command(sockfd, command);
    receive_response(sockfd);
    
    // Base64 encode username and password (dummy values for example)
    const char *username = "your_username"; // Replace with actual username
    const char *password = "your_password"; // Replace with actual password
    snprintf(command, sizeof(command), "%s\r\n", username); // you should encode it to Base64
    send_command(sockfd, command);
    receive_response(sockfd);
    
    snprintf(command, sizeof(command), "%s\r\n", password); // you should encode it to Base64
    send_command(sockfd, command);
    receive_response(sockfd);
    
    // MAIL FROM
    snprintf(command, sizeof(command), "MAIL FROM: <%s>\r\n", email_from);
    send_command(sockfd, command);
    receive_response(sockfd);

    // RCPT TO
    snprintf(command, sizeof(command), "RCPT TO: <%s>\r\n", email_to);
    send_command(sockfd, command);
    receive_response(sockfd);

    // DATA
    snprintf(command, sizeof(command), "DATA\r\n");
    send_command(sockfd, command);
    receive_response(sockfd);

    // Email headers and body
    snprintf(command, sizeof(command), "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, message_body);
    send_command(sockfd, command);
    receive_response(sockfd);
    
    // QUIT
    snprintf(command, sizeof(command), "QUIT\r\n");
    send_command(sockfd, command);
    receive_response(sockfd);

    close(sockfd);
    return 0;
}