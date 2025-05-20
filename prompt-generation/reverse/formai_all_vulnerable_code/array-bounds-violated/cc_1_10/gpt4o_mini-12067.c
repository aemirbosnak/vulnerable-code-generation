//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

void check_response(int sockfd, const char *expected_code) {
    char buffer[BUFFER_SIZE];
    int len = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (len < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    buffer[len] = '\0';
    printf("Server Response: %s", buffer);
    if (strncmp(buffer, expected_code, 3) != 0) {
        fprintf(stderr, "Unexpected response from SMTP server: %s", buffer);
        exit(EXIT_FAILURE);
    }
}

int connect_to_smtp_server(const char *hostname) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    
    if(inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        perror("Invalid address or Address not supported");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    check_response(sockfd, "220");
    return sockfd;
}

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    printf("Client Command: %s", command);
    check_response(sockfd, "250");
}

void send_email(int sockfd, const char *from, const char *to, const char *subject, const char *body) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "MAIL FROM:<%s>\r\n", from);
    send_command(sockfd, command);
    
    snprintf(command, sizeof(command), "RCPT TO:<%s>\r\n", to);
    send_command(sockfd, command);
    
    send(sockfd, "DATA\r\n", 6, 0);
    check_response(sockfd, "354");
    
    snprintf(command, sizeof(command), "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    send(sockfd, command, strlen(command), 0);
    check_response(sockfd, "250");
}

void quit_smtp_session(int sockfd) {
    send(sockfd, "QUIT\r\n", 6, 0);
    check_response(sockfd, "221");
}

void cleanup(int sockfd) {
    close(sockfd);
    printf("Connection closed.\n");
}

int main() {
    const char *smtp_server = "127.0.0.1"; // Replace with your SMTP server IP
    const char *from_address = "sender@example.com";
    const char *to_address = "recipient@example.com";
    const char *email_subject = "Test Email";
    const char *email_body = "Hello! This is a test email sent from a simple SMTP client program. Cheers!";

    int sockfd = connect_to_smtp_server(smtp_server);
    
    // HELO Command
    send_command(sockfd, "HELO localhost\r\n");
    
    // Send Email
    send_email(sockfd, from_address, to_address, email_subject, email_body);
    
    // Quit session
    quit_smtp_session(sockfd);
    
    cleanup(sockfd);
    return 0;
}