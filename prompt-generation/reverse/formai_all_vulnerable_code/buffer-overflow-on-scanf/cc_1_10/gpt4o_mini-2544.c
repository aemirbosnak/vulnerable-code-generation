//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER "smtp.example.com"
#define PORT 587
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sockfd, const char *command, const char *expected_response) {
    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "%s\r\n", command);
    send(sockfd, buffer, strlen(buffer), 0);
    
    // Receive response
    recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    buffer[BUFFER_SIZE - 1] = '\0'; // null-terminate to prevent overflow

    // Check for expected response
    if (strncmp(buffer, expected_response, 3) != 0) {
        fprintf(stderr, "Unexpected response: %s", buffer);
        exit(1);
    }
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char username[50];
    char password[50];
    char from[50];
    char to[50];
    char subject[100];
    char body[500];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // Setup server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting");
    }

    // Receive server greeting
    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    printf("Server: %s", buffer);
    
    // EHLO command
    send_command(sockfd, "EHLO localhost", "250");

    // Authentication
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    // Use STARTTLS for secure communication
    send_command(sockfd, "STARTTLS", "220");
    // Here you would normally enable TLS using OpenSSL or similar library.
    // For simplicity, we assume that it supports TLS immediately after.

    // Auth command
    char auth_command[BUFFER_SIZE];
    snprintf(auth_command, sizeof(auth_command), "AUTH LOGIN\r\n");
    send_command(sockfd, auth_command, "334");

    snprintf(auth_command, sizeof(auth_command), "%s\r\n", username);
    send(sockfd, auth_command, strlen(auth_command), 0);
    recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    printf("Server: %s", buffer);

    snprintf(auth_command, sizeof(auth_command), "%s\r\n", password);
    send(sockfd, auth_command, strlen(auth_command), 0);
    recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    printf("Server: %s", buffer);

    // Mail from
    printf("Enter sender email address: ");
    scanf("%s", from);
    snprintf(auth_command, sizeof(auth_command), "MAIL FROM:<%s>\r\n", from);
    send_command(sockfd, auth_command, "250");

    // Mail to
    printf("Enter recipient email address: ");
    scanf("%s", to);
    snprintf(auth_command, sizeof(auth_command), "RCPT TO:<%s>\r\n", to);
    send_command(sockfd, auth_command, "250");

    // Data command
    send_command(sockfd, "DATA", "354");

    // Email subject and body
    printf("Enter email subject: ");
    scanf(" %[^\n]", subject);
    printf("Enter email body (use '.' on a new line to end):\n");
    char email_body[BUFFER_SIZE];
    snprintf(email_body, sizeof(email_body), "Subject: %s\r\n\r\n", subject);
    
    char line[100];
    while (1) {
        fgets(line, sizeof(line), stdin);
        if (strcmp(line, ".\n") == 0) break; // end of email
        strcat(email_body, line);
    }
    
    // Sending email data
    strcat(email_body, "\r\n.\r\n");
    send(sockfd, email_body, strlen(email_body), 0);
    recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    printf("Server: %s", buffer);

    // Quit command
    send_command(sockfd, "QUIT", "221");

    // Close socket
    close(sockfd);
    return 0;
}