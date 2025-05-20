//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

void send_command(int sockfd, const char *cmd) {
    // Send the command to the SMTP server
    send(sockfd, cmd, strlen(cmd), 0);
    printf("Sent: %s", cmd);
}

void read_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    buffer[bytes_received] = '\0'; // Null-terminate the string
    printf("Response: %s", buffer);
}

int main() {
    struct sockaddr_in server_addr;
    int sockfd;
    char *smtp_server = "smtp.example.com"; // Replace with your SMTP server
    char *from_email = "your-email@example.com"; // Replace with your email
    char *to_email = "recipient@example.com"; // Replace with recipient's email
    char *subject = "Test Email";
    char *body = "Hello, this is a test email sent from a C program.";
    
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Could not create socket");
        return EXIT_FAILURE;
    }

    // Define server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    inet_pton(AF_INET, smtp_server, &server_addr.sin_addr);

    // Connect to the SMTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Read welcome message
    read_response(sockfd);

    // Sending HELO command
    send_command(sockfd, "HELO localhost\r\n");
    read_response(sockfd);

    // Authenticate (optional, depending on your server)
    // Uncomment and modify the lines below if needed
    /*
    send_command(sockfd, "AUTH LOGIN\r\n");
    read_response(sockfd);
    send_command(sockfd, "<base64_encoded_username>\r\n");
    read_response(sockfd);
    send_command(sockfd, "<base64_encoded_password>\r\n");
    read_response(sockfd);
    */

    // Set the sender
    char from_cmd[BUFFER_SIZE];
    snprintf(from_cmd, sizeof(from_cmd), "MAIL FROM:<%s>\r\n", from_email);
    send_command(sockfd, from_cmd);
    read_response(sockfd);

    // Set the recipient
    char to_cmd[BUFFER_SIZE];
    snprintf(to_cmd, sizeof(to_cmd), "RCPT TO:<%s>\r\n", to_email);
    send_command(sockfd, to_cmd);
    read_response(sockfd);

    // Start the message
    send_command(sockfd, "DATA\r\n");
    read_response(sockfd);
    
    // Compose the email
    char email[BUFFER_SIZE];
    snprintf(email, sizeof(email), 
             "Subject: %s\r\n"
             "From: %s\r\n"
             "To: %s\r\n"
             "\r\n"
             "%s\r\n"
             ".\r\n", 
             subject, from_email, to_email, body);
    
    // Send email content
    send_command(sockfd, email);
    read_response(sockfd);
    
    // Quit session
    send_command(sockfd, "QUIT\r\n");
    read_response(sockfd);

    // Close the socket
    close(sockfd);
    printf("Email sent successfully.\n");

    return EXIT_SUCCESS;
}