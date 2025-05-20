//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_smtp_command(int sockfd, const char *command) {
    if (send(sockfd, command, strlen(command), 0) < 0) {
        handle_error("Failed to send command");
    }
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    if (bytes_received < 0) {
        handle_error("Failed to receive response");
    }
    buffer[bytes_received] = '\0';
    printf("Server Response: %s", buffer);
}

void smtp_handshake(int sockfd) {
    receive_response(sockfd);
    send_smtp_command(sockfd, "HELO localhost\r\n");
    receive_response(sockfd);
}

void smtp_send_email(int sockfd, const char *from, const char *to, const char *subject, const char *body) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "MAIL FROM:<%s>\r\n", from);
    send_smtp_command(sockfd, command);
    receive_response(sockfd);
    
    snprintf(command, sizeof(command), "RCPT TO:<%s>\r\n", to);
    send_smtp_command(sockfd, command);
    receive_response(sockfd);
    
    send_smtp_command(sockfd, "DATA\r\n");
    receive_response(sockfd);
    
    snprintf(command, sizeof(command),
             "Subject: %s\r\nFrom: %s\r\nTo: %s\r\n\r\n%s\r\n.\r\n",
             subject, from, to, body);
    send_smtp_command(sockfd, command);
    receive_response(sockfd);
    
    send_smtp_command(sockfd, "QUIT\r\n");
    receive_response(sockfd);
}

int main() {
    const char *smtp_server = "smtp.example.com"; // Replace with your SMTP server
    const char *from_email = "you@example.com";   // Replace with sender's email
    const char *to_email = "recipient@example.com"; // Replace with recipient's email
    const char *email_subject = "Test SMTP Email";
    const char *email_body = "Hello, this is a test email from a simple SMTP client!";

    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        handle_error("Socket creation error");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);

    // Convert IPv4 address from text to binary form
    if (inet_pton(AF_INET, smtp_server, &server_addr.sin_addr) <= 0) {
        handle_error("Invalid address or address not supported");
    }

    // Connect to SMTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection failed");
    }

    // Handshake with the SMTP server
    smtp_handshake(sockfd);

    // Send email through SMTP
    smtp_send_email(sockfd, from_email, to_email, email_subject, email_body);

    // Close socket
    close(sockfd);
    return 0;
}