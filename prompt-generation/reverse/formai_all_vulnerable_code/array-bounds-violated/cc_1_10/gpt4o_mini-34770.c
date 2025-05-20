//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SERVER "smtp.example.com"
#define PORT 587
#define BUFFER_SIZE 1024

void error_handling(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int smtp_send(int sockfd, const char *message) {
    if (send(sockfd, message, strlen(message), 0) < 0) {
        error_handling("Error sending data to SMTP server");
        return -1;
    }
    return 0;
}

char* smtp_receive(int sockfd) {
    static char buffer[BUFFER_SIZE];
    int n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (n < 0) {
        error_handling("Error receiving data from SMTP server");
    }
    buffer[n] = '\0'; // Null-terminate the string
    return buffer;
}

void smtp_send_email(const char *from, const char *to, const char *subject, const char *body) {
    struct sockaddr_in server_addr;
    int sockfd;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error_handling("Cannot create socket");
    }

    // Server settings
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER);

    // Connect to the SMTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error_handling("Cannot connect to the SMTP server");
    }

    // Receive server greeting
    printf("%s", smtp_receive(sockfd));

    // EHLO command
    smtp_send(sockfd, "EHLO localhost\r\n");
    printf("%s", smtp_receive(sockfd));

    // AUTH LOGIN (optional, you might need to implement authentication)
    // smtp_send(sockfd, "AUTH LOGIN\r\n");
    // printf("%s", smtp_receive(sockfd));
    
    // MAIL FROM command
    char mail_from[BUFFER_SIZE];
    snprintf(mail_from, sizeof(mail_from), "MAIL FROM: <%s>\r\n", from);
    smtp_send(sockfd, mail_from);
    printf("%s", smtp_receive(sockfd));

    // RCPT TO command
    char rcpt_to[BUFFER_SIZE];
    snprintf(rcpt_to, sizeof(rcpt_to), "RCPT TO: <%s>\r\n", to);
    smtp_send(sockfd, rcpt_to);
    printf("%s", smtp_receive(sockfd));

    // DATA command
    smtp_send(sockfd, "DATA\r\n");
    printf("%s", smtp_receive(sockfd));

    // Email data
    char email[BUFFER_SIZE * 2];
    snprintf(email, sizeof(email),
             "From: %s\r\n"
             "To: %s\r\n"
             "Subject: %s\r\n"
             "\r\n"
             "%s\r\n"
             ".\r\n",
             from, to, subject, body);
    smtp_send(sockfd, email);
    printf("%s", smtp_receive(sockfd));

    // QUIT command
    smtp_send(sockfd, "QUIT\r\n");
    printf("%s", smtp_receive(sockfd));

    // Close the socket
    close(sockfd);
}

int main() {
    printf("Welcome to the SMTP Client!\n");
    
    // Sample email data
    const char *from = "sender@example.com";
    const char *to = "recipient@example.com";
    const char *subject = "Hello from SMTP Client!";
    const char *body = "This is a test email sent from an SMTP client in C. Isn't this cool?";
    
    printf("Sending email...\n");
    smtp_send_email(from, to, subject, body);
    printf("Email sent successfully!\n");

    return 0;
}