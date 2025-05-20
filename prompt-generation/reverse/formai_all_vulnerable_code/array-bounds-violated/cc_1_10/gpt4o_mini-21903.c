//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

void send_command(int sockfd, const char *command) {
    // Send command to SMTP server
    send(sockfd, command, strlen(command), 0);
    
    // Receive response from server
    char buffer[BUFFER_SIZE];
    int len = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    buffer[len] = '\0'; // Null-terminate the response

    printf("Server response: %s", buffer);
}

int main() {
    const char *smtp_server = "smtp.example.com"; // Replace with your SMTP server
    const char *from_email = "sender@example.com"; // Replace with your sender email
    const char *to_email = "receiver@example.com"; // Replace with your receiver email
    const char *subject = "Test Email Subject";
    const char *body = "This is a test email sent from a C SMTP client.";

    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return -1;
    }

    // Configure server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    
    // Convert the address from text to binary form
    if (inet_pton(AF_INET, smtp_server, &server_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        close(sockfd);
        return -1;
    }

    // Connect to SMTP server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        return -1;
    }

    // SMTP HELO command
    send_command(sockfd, "HELO localhost\r\n");

    // SMTP MAIL FROM command
    char mail_from_cmd[BUFFER_SIZE];
    snprintf(mail_from_cmd, sizeof(mail_from_cmd), "MAIL FROM:<%s>\r\n", from_email);
    send_command(sockfd, mail_from_cmd);

    // SMTP RCPT TO command
    char rcpt_to_cmd[BUFFER_SIZE];
    snprintf(rcpt_to_cmd, sizeof(rcpt_to_cmd), "RCPT TO:<%s>\r\n", to_email);
    send_command(sockfd, rcpt_to_cmd);

    // SMTP DATA command
    send_command(sockfd, "DATA\r\n");

    // Compose email data
    char email_data[BUFFER_SIZE * 2];
    snprintf(email_data, sizeof(email_data), "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.\r\n",
             from_email, to_email, subject, body);
    send(sockfd, email_data, strlen(email_data), 0);

    // Receive response for DATA command
    char buffer[BUFFER_SIZE];
    int len = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    buffer[len] = '\0';
    printf("Server response (DATA): %s", buffer);

    // SMTP QUIT command
    send_command(sockfd, "QUIT\r\n");

    // Close the socket
    close(sockfd);
    return 0;
}