//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER "smtp.example.com"  // Modify with a valid SMTP server
#define PORT 587                     // SMTP port, typically 587 for STARTTLS
#define BUFFER_SIZE 1024

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int send_email(int sockfd, const char *from, const char *to, const char *subject, const char *body) {
    char buffer[BUFFER_SIZE];

    sprintf(buffer, "HELO localhost\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Response: %s", buffer);

    sprintf(buffer, "MAIL FROM:<%s>\r\n", from);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Response: %s", buffer);

    sprintf(buffer, "RCPT TO:<%s>\r\n", to);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Response: %s", buffer);

    sprintf(buffer, "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Response: %s", buffer);
    
    // Send the email body and ending with a line with just a dot
    sprintf(buffer, "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Response: %s", buffer);

    sprintf(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Response: %s", buffer);

    return 0;
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char from[100], to[100], subject[100], body[512];

    // Input email details
    printf("Enter sender's email: ");
    scanf("%s", from);
    printf("Enter recipient's email: ");
    scanf("%s", to);
    printf("Enter the subject: ");
    scanf(" %[^\n]", subject);
    printf("Enter the email body: ");
    scanf(" %[^\n]", body);

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        handle_error("Socket creation failed");
    }

    // Define server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, SERVER, &server_addr.sin_addr) <= 0) {
        handle_error("Invalid address or address not supported");
    }

    // Connect to SMTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection to the server failed");
    }

    printf("Connected to the SMTP server: %s\n", SERVER);

    // Send email
    send_email(sockfd, from, to, subject, body);

    // Close socket
    close(sockfd);
    printf("Email sent successfully.\n");

    return 0;
}