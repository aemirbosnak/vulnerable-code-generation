//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024
#define SERVER "smtp.example.com" // Change this to your SMTP server

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_smtp_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    printf("Sent: %s\n", command);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        error("Error receiving response");
    }
    buffer[bytes_received] = '\0';
    printf("Received: %s", buffer);
}

int main() {
    int sockfd;
    struct sockaddr_in server_address;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SMTP_PORT);
    inet_pton(AF_INET, SERVER, &server_address.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        error("Connection failed");
    }

    receive_response(sockfd);

    // SMTP HELO command
    send_smtp_command(sockfd, "HELO localhost\r\n");
    receive_response(sockfd);

    // MAIL FROM command
    send_smtp_command(sockfd, "MAIL FROM:<sender@example.com>\r\n"); // Change sender's email
    receive_response(sockfd);

    // RCPT TO command
    send_smtp_command(sockfd, "RCPT TO:<recipient@example.com>\r\n"); // Change recipient's email
    receive_response(sockfd);

    // DATA command
    send_smtp_command(sockfd, "DATA\r\n");
    receive_response(sockfd);

    // Email data
    const char *email_data = 
        "Subject: Test Email\r\n"
        "From: sender@example.com\r\n"
        "To: recipient@example.com\r\n"
        "\r\n"
        "Hello, this is a test email sent from a simple SMTP client written in C.\r\n"
        ".\r\n"; // End of email data

    send(sockfd, email_data, strlen(email_data), 0);
    printf("Sent email data\n");

    receive_response(sockfd);

    // QUIT command
    send_smtp_command(sockfd, "QUIT\r\n");
    receive_response(sockfd);

    close(sockfd);
    return 0;
}