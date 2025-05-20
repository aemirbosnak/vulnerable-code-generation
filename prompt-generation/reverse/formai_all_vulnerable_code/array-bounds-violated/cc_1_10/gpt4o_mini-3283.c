//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

// Function declarations
void send_command(int sockfd, const char *cmd);
void receive_response(int sockfd);
void send_email(int sockfd, const char *from, const char *to, const char *subject, const char *body);

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    // SMTP server details
    const char *smtp_server = "smtp.example.com";
    const int smtp_port = 587; // Typically 587 for SMTP
    const char *username = "your_email@example.com";
    const char *password = "your_password";
    
    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    // Configure the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(smtp_port);

    // Convert the server address from text to binary
    if (inet_pton(AF_INET, smtp_server, &server_addr.sin_addr) <= 0) {
        perror("Invalid address");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Connect to the SMTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection Failed");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Receive greeting from the server
    receive_response(sockfd);

    // Send HELO command
    send_command(sockfd, "HELO localhost\r\n");
    receive_response(sockfd);

    // Authenticate (using simple login method)
    send_command(sockfd, "AUTH LOGIN\r\n");
    receive_response(sockfd);
    
    // Send username
    send_command(sockfd, username); // ensure username is base64 encoded for production
    send_command(sockfd, "\r\n");
    receive_response(sockfd);

    // Send password
    send_command(sockfd, password);  // ensure password is base64 encoded for production
    send_command(sockfd, "\r\n");
    receive_response(sockfd);

    // Building the email details
    const char *from = "your_email@example.com";
    const char *to = "recipient@example.com";
    const char *subject = "Test Email";
    const char *body = "This is a test email sent from C SMTP client.";

    // Send email
    send_email(sockfd, from, to, subject, body);

    // Close the connection
    send_command(sockfd, "QUIT\r\n");
    receive_response(sockfd);
    
    close(sockfd);
    return EXIT_SUCCESS;
}

void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the received string
        printf("%s", buffer);
    }
}

void send_email(int sockfd, const char *from, const char *to, const char *subject, const char *body) {
    char buffer[BUFFER_SIZE];

    // Specify the sender
    snprintf(buffer, sizeof(buffer), "MAIL FROM: <%s>\r\n", from);
    send_command(sockfd, buffer);
    receive_response(sockfd);

    // Specify the recipient
    snprintf(buffer, sizeof(buffer), "RCPT TO: <%s>\r\n", to);
    send_command(sockfd, buffer);
    receive_response(sockfd);

    // Start the data section
    send_command(sockfd, "DATA\r\n");
    receive_response(sockfd);

    // Send email content
    snprintf(buffer, sizeof(buffer), "Subject: %s\r\nFrom: %s\r\nTo: %s\r\n\r\n%s\r\n.\r\n", subject, from, to, body);
    send_command(sockfd, buffer);
    receive_response(sockfd);
}