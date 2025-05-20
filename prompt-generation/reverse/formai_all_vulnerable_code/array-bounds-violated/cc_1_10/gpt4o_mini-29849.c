//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SMTP_SERVER "smtp.example.com" // Replace with your SMTP server
#define SMTP_PORT 25                     // Replace with your SMTP port, often 587 or 465
#define BUFFER_SIZE 1024

void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
    printf("Sent: %s", cmd);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        perror("recv failed");
        exit(1);
    }

    buffer[bytes_received] = '\0';
    printf("Received: %s", buffer);
}

int main() {
    int sockfd;
    struct sockaddr_in server_address;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return 1;
    }

    // Server address initialization
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SMTP_PORT);
    inet_pton(AF_INET, SMTP_SERVER, &server_address.sin_addr);

    // Connect to SMTP server
    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection to server failed");
        return 1;
    }

    // Receive server response
    receive_response(sockfd);

    // Send HELO command
    send_command(sockfd, "HELO localhost\r\n");
    receive_response(sockfd);

    // Send MAIL FROM command
    send_command(sockfd, "MAIL FROM:<your_email@example.com>\r\n"); // Replace with your email
    receive_response(sockfd);

    // Send RCPT TO command
    send_command(sockfd, "RCPT TO:<recipient@example.com>\r\n"); // Replace with recipient
    receive_response(sockfd);

    // Send DATA command
    send_command(sockfd, "DATA\r\n");
    receive_response(sockfd);

    // Email header and body
    const char *email_data = "Subject: Test Email from C SMTP Client\r\n"
                             "From: your_email@example.com\r\n"  // Replace with your email
                             "To: recipient@example.com\r\n"     // Replace with recipient
                             "\r\n"
                             "Hello, this is a test email sent from a C SMTP Client!\r\n"
                             ".\r\n"; // Ending the DATA section with a dot

    // Send the email body
    send(sockfd, email_data, strlen(email_data), 0);
    printf("Sending email data...\n");

    // Receive the response after sending data
    receive_response(sockfd);

    // Send QUIT command
    send_command(sockfd, "QUIT\r\n");
    receive_response(sockfd);

    // Close the socket
    close(sockfd);
    printf("Connection closed. Email sent successfully!\n");

    return 0;
}