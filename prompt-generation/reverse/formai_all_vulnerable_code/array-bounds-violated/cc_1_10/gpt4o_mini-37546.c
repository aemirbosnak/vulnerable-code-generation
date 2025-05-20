//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SMTP_PORT 587
#define BUFFER_SIZE 1024

void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    buffer[bytes_received] = '\0'; // Null-terminate the buffer
    printf("Server Response: %s", buffer);
}

void send_email(const char *smtp_server, const char *from, const char *to, const char *subject, const char *body) {
    int sockfd;
    struct sockaddr_in server_addr;
 
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setup server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr(smtp_server);
 
    // Connect to the SMTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Receive server response
    receive_response(sockfd);

    // Send HELO command
    send_command(sockfd, "HELO localhost\r\n");
    receive_response(sockfd);

    // Set the sender
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "MAIL FROM: <%s>\r\n", from);
    send_command(sockfd, command);
    receive_response(sockfd);

    // Set the recipient
    snprintf(command, sizeof(command), "RCPT TO: <%s>\r\n", to);
    send_command(sockfd, command);
    receive_response(sockfd);

    // Start the data transmission
    send_command(sockfd, "DATA\r\n");
    receive_response(sockfd);

    // Prepare and send email content
    snprintf(command, sizeof(command), "Subject: %s\r\nFrom: %s\r\nTo: %s\r\n\r\n%s\r\n.\r\n", subject, from, to, body);
    send_command(sockfd, command);
    receive_response(sockfd);

    // Send QUIT command
    send_command(sockfd, "QUIT\r\n");
    receive_response(sockfd);

    // Close socket
    close(sockfd);
}

int main() {
    char smtp_server[100] = "smtp.example.com"; // Replace with your SMTP server
    char from[100] = "you@example.com"; // Replace with your email
    char to[100] = "recipient@example.com"; // Replace with recipient's email
    char subject[100] = "Test Email";
    char body[512] = "This is a test email sent from a C program.";

    send_email(smtp_server, from, to, subject, body);

    return 0;
}