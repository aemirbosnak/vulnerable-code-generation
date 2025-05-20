//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SMTP_PORT 587
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char *cmd) {
    if (send(sockfd, cmd, strlen(cmd), 0) < 0) {
        error("Error sending command");
    }
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        error("Error receiving response");
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);
}

void smtp_client(const char *server, const char *from, const char *to, const char *subject, const char *body) {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error("Socket creation failed");
    }

    // Server details
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    if (inet_pton(AF_INET, server, &server_addr.sin_addr) <= 0) {
        error("Invalid address or address not supported");
    }

    // Connect to SMTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection to SMTP server failed");
    }

    receive_response(sockfd);  // Welcome message

    // HELO command
    send_command(sockfd, "EHLO localhost\r\n");
    receive_response(sockfd);

    // Start TLS (optional, uncomment if needed)
    // send_command(sockfd, "STARTTLS\r\n");
    // receive_response(sockfd);
    // Here, you would normally initiate SSL/TLS handshake

    // Authentication (simple "mail" command)
    send_command(sockfd, "MAIL FROM: ");
    send_command(sockfd, from);
    send_command(sockfd, "\r\n");
    receive_response(sockfd);

    // Recipient
    send_command(sockfd, "RCPT TO: ");
    send_command(sockfd, to);
    send_command(sockfd, "\r\n");
    receive_response(sockfd);

    // Data command
    send_command(sockfd, "DATA\r\n");
    receive_response(sockfd);

    // Email content
    char data[BUFFER_SIZE];
    snprintf(data, sizeof(data), "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    send_command(sockfd, data);
    receive_response(sockfd);

    // Quit command
    send_command(sockfd, "QUIT\r\n");
    receive_response(sockfd);

    // Clean up
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 6) {
        fprintf(stderr, "Usage: %s <SMTP_SERVER> <FROM_EMAIL> <TO_EMAIL> <SUBJECT> <BODY>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *smtp_server = argv[1];
    const char *from_email = argv[2];
    const char *to_email = argv[3];
    const char *email_subject = argv[4];
    const char *email_body = argv[5];

    smtp_client(smtp_server, from_email, to_email, email_subject, email_body);

    return 0;
}