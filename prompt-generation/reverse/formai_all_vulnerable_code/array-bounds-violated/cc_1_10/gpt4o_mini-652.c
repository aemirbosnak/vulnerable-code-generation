//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

void check_response(int sockfd, const char *expected_code) {
    char buffer[BUFFER_SIZE];
    int received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    buffer[received] = '\0';
    printf("Response: %s", buffer);
    if (strncmp(buffer, expected_code, 3) != 0) {
        fprintf(stderr, "Unexpected response from server: %s\n", buffer);
        exit(EXIT_FAILURE);
    }
}

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    send(sockfd, "\r\n", 2, 0);
}

void smtp_client(const char *server, const char *from, const char *to, const char *subject, const char *body) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr(server);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to SMTP server failed");
        exit(EXIT_FAILURE);
    }

    check_response(sockfd, "220");

    send_command(sockfd, "EHLO localhost");
    check_response(sockfd, "250");

    send_command(sockfd, "MAIL FROM: <");
    send(sockfd, from, strlen(from), 0);
    send(sockfd, ">", 1, 0);
    check_response(sockfd, "250");

    send_command(sockfd, "RCPT TO: <");
    send(sockfd, to, strlen(to), 0);
    send(sockfd, ">", 1, 0);
    check_response(sockfd, "250");

    send_command(sockfd, "DATA");
    check_response(sockfd, "354");

    send_command(sockfd, "Subject: ");
    send(sockfd, subject, strlen(subject), 0);
    send(sockfd, "\r\n", 2, 0);
    
    send(sockfd, body, strlen(body), 0);
    send(sockfd, "\r\n.\r\n", 5, 0);
    check_response(sockfd, "250");

    send_command(sockfd, "QUIT");
    check_response(sockfd, "221");

    close(sockfd);
}

int main() {
    const char *smtp_server = "127.0.0.1";
    const char *from_email = "your_email@example.com";
    const char *to_email = "recipient@example.com";
    const char *email_subject = "Test Email from SMTP Client";
    const char *email_body = "This is a test email sent from a simple SMTP client written in C.";

    smtp_client(smtp_server, from_email, to_email, email_subject, email_body);

    printf("Email sent successfully!\n");
    return 0;
}