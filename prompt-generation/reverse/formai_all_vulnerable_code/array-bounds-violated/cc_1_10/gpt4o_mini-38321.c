//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 587 // SMTP port
#define BUFFER_SIZE 1024

void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
    printf("Sent: %s", cmd);
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    buffer[bytes_received] = '\0'; // Null-terminate the string
    printf("Received: %s", buffer);
}

int main() {
    const char *smtp_server = "smtp.example.com"; // Change to your SMTP server
    const char *username = "you@example.com"; // Change to your SMTP username
    const char *password = "yourpassword"; // Change to your SMTP password
    const char *from = "you@example.com"; // Your email address
    const char *to = "recipient@example.com"; // Recipient's email address
    const char *subject = "Test Email";
    const char *body = "Hello, this is a test email sent from a C program!";

    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Specify server details
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Change to appropriate address

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to the server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Read server response
    read_response(sockfd);
    
    // Initial HELO command
    send_command(sockfd, "EHLO localhost\r\n");
    read_response(sockfd);

    // Start TLS (if necessary, for secure connection)
    send_command(sockfd, "STARTTLS\r\n");
    read_response(sockfd);

    // Authenticate
    char auth_cmd[BUFFER_SIZE];
    sprintf(auth_cmd, "AUTH LOGIN\r\n");
    send_command(sockfd, auth_cmd);
    read_response(sockfd);
    
    // Send username
    send_command(sockfd, "your_base64_encoded_username\r\n"); // Encode your username in Base64
    read_response(sockfd);
    
    // Send password
    send_command(sockfd, "your_base64_encoded_password\r\n"); // Encode your password in Base64
    read_response(sockfd);

    // Specify the email sender
    char from_cmd[BUFFER_SIZE];
    sprintf(from_cmd, "MAIL FROM: < %s >\r\n", from);
    send_command(sockfd, from_cmd);
    read_response(sockfd);
    
    // Specify the recipient
    char rcpt_cmd[BUFFER_SIZE];
    sprintf(rcpt_cmd, "RCPT TO: < %s >\r\n", to);
    send_command(sockfd, rcpt_cmd);
    read_response(sockfd);
    
    // Start the message
    send_command(sockfd, "DATA\r\n");
    read_response(sockfd);
    
    // Send the message header and body
    char data_cmd[BUFFER_SIZE];
    sprintf(data_cmd, 
            "Subject: %s\r\n"
            "From: %s\r\n"
            "To: %s\r\n"
            "\r\n"
            "%s\r\n"
            ".\r\n", 
            subject, from, to, body);
    send_command(sockfd, data_cmd);
    read_response(sockfd);
    
    // Close the connection
    send_command(sockfd, "QUIT\r\n");
    read_response(sockfd);
    
    close(sockfd);
    printf("Email sent successfully!\n");

    return 0;
}