//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define SMTP_PORT 587
#define BUFFER_SIZE 1024

// Function to send commands to the SMTP server
void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
}

// Function to receive response from the SMTP server
void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';
        printf("Server: %s", buffer);
    }
}

// Function to handle login via SMTP AUTH
int smtp_login(int sockfd, const char *username, const char *password) {
    // HELO command
    send_command(sockfd, "EHLO localhost\r\n");
    receive_response(sockfd);

    // Start AUTH LOGIN
    send_command(sockfd, "AUTH LOGIN\r\n");
    receive_response(sockfd);
    
    // Send username
    char encoded_username[BUFFER_SIZE];
    sprintf(encoded_username, "%s\r\n", username);
    send_command(sockfd, encoded_username);
    receive_response(sockfd);
    
    // Send password
    char encoded_password[BUFFER_SIZE];
    sprintf(encoded_password, "%s\r\n", password);
    send_command(sockfd, encoded_password);
    receive_response(sockfd);

    return 0;
}

// Function to send an email
int send_email(int sockfd, const char *from, const char *to, const char *subject, const char *body) {
    // Specify sender
    char command[BUFFER_SIZE];
    sprintf(command, "MAIL FROM: <%s>\r\n", from);
    send_command(sockfd, command);
    receive_response(sockfd);
    
    // Specify recipient
    sprintf(command, "RCPT TO: <%s>\r\n", to);
    send_command(sockfd, command);
    receive_response(sockfd);
    
    // Start DATA section
    send_command(sockfd, "DATA\r\n");
    receive_response(sockfd);
    
    // Email headers
    sprintf(command, "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", from, to, subject, body);
    send_command(sockfd, command);
    receive_response(sockfd);

    return 0;
}

// Main function
int main() {
    const char *smtp_server = "smtp.example.com"; // Change to your SMTP server
    const char *username = "your_email@example.com"; // Your email
    const char *password = "your_password"; // Your password
    const char *from = username;
    const char *to = "recipient@example.com"; // Recipient email
    const char *subject = "Test Email";
    const char *body = "Hello, this is a test email sent from a simple SMTP client.";

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Unable to create socket");
        return 1;
    }

    // Setup server address structure
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SMTP_PORT);
    inet_pton(AF_INET, smtp_server, &server_address.sin_addr);

    // Connect to SMTP server
    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Unable to connect to SMTP server");
        close(sockfd);
        return 1;
    }

    // Receive server response
    receive_response(sockfd);

    // Log in to the server
    smtp_login(sockfd, username, password);

    // Send email
    send_email(sockfd, from, to, subject, body);

    // Close connection
    send_command(sockfd, "QUIT\r\n");
    receive_response(sockfd);
    close(sockfd);

    printf("Email sent successfully!\n");
    return 0;
}