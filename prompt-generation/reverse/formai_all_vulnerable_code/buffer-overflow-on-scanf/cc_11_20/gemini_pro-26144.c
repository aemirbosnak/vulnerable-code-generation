//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Email header constants
#define FROM "From: "
#define TO "To: "
#define SUBJECT "Subject: "
#define CRLF "\r\n"

// SMTP server and port
#define SMTP_SERVER "smtp.example.com"
#define SMTP_PORT 587

// Email message template
#define EMAIL_TEMPLATE "From: %s\n" \
                      "To: %s\n" \
                      "Subject: %s\n" \
                      "\n" \
                      "%s\n"

int main() {
    // Socket descriptor
    int sockfd;

    // Server address
    struct sockaddr_in server_addr;

    // Email sender, recipient, subject, and message
    char sender[100], recipient[100], subject[100], message[1000];

    // Get user input
    printf("Enter sender email address: ");
    scanf("%s", sender);
    printf("Enter recipient email address: ");
    scanf("%s", recipient);
    printf("Enter email subject: ");
    scanf("%s", subject);
    printf("Enter email message: ");
    scanf("%[^\n]", message);

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    if (inet_pton(AF_INET, SMTP_SERVER, &server_addr.sin_addr) <= 0) {
        perror("Invalid server address");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Send HELO command
    char helo[] = "HELO " SMTP_SERVER CRLF;
    if (send(sockfd, helo, strlen(helo), 0) < 0) {
        perror("HELO command failed");
        exit(EXIT_FAILURE);
    }

    // Receive server response
    char response[1024];
    if (recv(sockfd, response, sizeof(response), 0) < 0) {
        perror("Receive failed");
        exit(EXIT_FAILURE);
    }
    printf("Server response: %s", response);

    // Send MAIL FROM command
    char mail_from[strlen(FROM) + strlen(sender) + strlen(CRLF) + 1];
    sprintf(mail_from, "%s%s%s", FROM, sender, CRLF);
    if (send(sockfd, mail_from, strlen(mail_from), 0) < 0) {
        perror("MAIL FROM command failed");
        exit(EXIT_FAILURE);
    }

    // Receive server response
    if (recv(sockfd, response, sizeof(response), 0) < 0) {
        perror("Receive failed");
        exit(EXIT_FAILURE);
    }
    printf("Server response: %s", response);

    // Send RCPT TO command
    char rcpt_to[strlen(TO) + strlen(recipient) + strlen(CRLF) + 1];
    sprintf(rcpt_to, "%s%s%s", TO, recipient, CRLF);
    if (send(sockfd, rcpt_to, strlen(rcpt_to), 0) < 0) {
        perror("RCPT TO command failed");
        exit(EXIT_FAILURE);
    }

    // Receive server response
    if (recv(sockfd, response, sizeof(response), 0) < 0) {
        perror("Receive failed");
        exit(EXIT_FAILURE);
    }
    printf("Server response: %s", response);

    // Send DATA command
    char data[] = "DATA" CRLF;
    if (send(sockfd, data, strlen(data), 0) < 0) {
        perror("DATA command failed");
        exit(EXIT_FAILURE);
    }

    // Receive server response
    if (recv(sockfd, response, sizeof(response), 0) < 0) {
        perror("Receive failed");
        exit(EXIT_FAILURE);
    }
    printf("Server response: %s", response);

    // Send email message
    char email[strlen(EMAIL_TEMPLATE) + strlen(sender) + strlen(recipient) + strlen(subject) + strlen(message) + 1];
    sprintf(email, EMAIL_TEMPLATE, sender, recipient, subject, message);
    if (send(sockfd, email, strlen(email), 0) < 0) {
        perror("Email send failed");
        exit(EXIT_FAILURE);
    }

    // Send QUIT command
    char quit[] = "QUIT" CRLF;
    if (send(sockfd, quit, strlen(quit), 0) < 0) {
        perror("QUIT command failed");
        exit(EXIT_FAILURE);
    }

    // Receive server response
    if (recv(sockfd, response, sizeof(response), 0) < 0) {
        perror("Receive failed");
        exit(EXIT_FAILURE);
    }
    printf("Server response: %s", response);

    // Close the socket
    close(sockfd);

    return 0;
}