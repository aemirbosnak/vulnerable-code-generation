//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 25  // Default SMTP port
#define BUFFER_SIZE 1024

void check_command_response(int sockfd);
void send_email(int sockfd, const char *from, const char *to, const char *subject, const char *body);

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    // Shock alert! Configuring the socket!
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "[ERROR] Unable to create socket! D: \n");
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "[INFO] Socket created successfully! Phew! 😅\n");

    // Preparing the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  // Replace with actual SMTP server IP

    // Shockingly trying to connect to the server!
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "[ERROR] Connection to SMTP server failed! 😱 \n");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "[SUCCESS] Connected to SMTP server! 🎉\n");

    // Ahh! Receiving the server's welcome message!
    check_command_response(sockfd);

    // Setting up email details
    const char *from = "you@example.com";  // Add your sender email
    const char *to = "recipient@example.com";  // Add recipient email
    const char *subject = "Test Email From SMTP Client!";
    const char *body = "This is a test email sent via a simple SMTP client built in C.\n\nBest regards,\nYour shocking C Program!";

    // Let's send the email now! Hold your breath!
    send_email(sockfd, from, to, subject, body);

    // Closing up the socket!
    fprintf(stdout, "[CLOSE] Closing connection to SMTP server.\n");
    close(sockfd);
    return 0;
}

void check_command_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Receiving the server response
    bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        fprintf(stderr, "[ERROR] Failed to receive response from server!\n");
        exit(EXIT_FAILURE);
    }

    buffer[bytes_received] = '\0';  // Null-terminate the string
    fprintf(stdout, "[SERVER] %s\n", buffer);
}

void send_email(int sockfd, const char *from, const char *to, const char *subject, const char *body) {
    char command[BUFFER_SIZE];

    // Send HELO command
    snprintf(command, sizeof(command), "HELO localhost\r\n");
    send(sockfd, command, strlen(command), 0);
    check_command_response(sockfd);

    // Send MAIL FROM command
    snprintf(command, sizeof(command), "MAIL FROM:<%s>\r\n", from);
    send(sockfd, command, strlen(command), 0);
    check_command_response(sockfd);

    // Send RCPT TO command
    snprintf(command, sizeof(command), "RCPT TO:<%s>\r\n", to);
    send(sockfd, command, strlen(command), 0);
    check_command_response(sockfd);

    // Send DATA command
    send(sockfd, "DATA\r\n", 6, 0);
    check_command_response(sockfd);

    // Send email headers and body
    snprintf(command, sizeof(command), "Subject: %s\r\nFrom: %s\r\nTo: %s\r\n\r\n%s\r\n.\r\n", subject, from, to, body);
    send(sockfd, command, strlen(command), 0);
    check_command_response(sockfd);

    // Send QUIT command
    send(sockfd, "QUIT\r\n", 6, 0);
    check_command_response(sockfd);
    fprintf(stdout, "[SUCCESS] Email sent successfully! 🎉✉️\n");
}