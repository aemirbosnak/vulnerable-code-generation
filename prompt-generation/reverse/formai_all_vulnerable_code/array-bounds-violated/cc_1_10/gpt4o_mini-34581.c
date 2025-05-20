//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int sockfd, const char *command) {
    if (send(sockfd, command, strlen(command), 0) < 0) {
        handle_error("send");
    }
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        handle_error("recv");
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);
}

void smtp_client(const char *server, const char *from, const char *to, const char *subject, const char *body) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        handle_error("socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    if (inet_pton(AF_INET, server, &server_addr.sin_addr) <= 0) {
        handle_error("inet_pton");
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("connect");
    }

    receive_response(sockfd);
    
    send_command(sockfd, "HELO localhost\r\n");
    receive_response(sockfd);

    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "MAIL FROM:<%s>\r\n", from);
    send_command(sockfd, command);
    receive_response(sockfd);

    snprintf(command, sizeof(command), "RCPT TO:<%s>\r\n", to);
    send_command(sockfd, command);
    receive_response(sockfd);

    send_command(sockfd, "DATA\r\n");
    receive_response(sockfd);

    snprintf(command, sizeof(command), "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    send_command(sockfd, command);
    receive_response(sockfd);

    send_command(sockfd, "QUIT\r\n");
    receive_response(sockfd);

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <smtp_server> <from_email> <to_email> <subject> <body>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *smtp_server = argv[1];
    const char *from_email = argv[2];
    const char *to_email = argv[3];
    const char *subject = argv[4];
    const char *body = "This is a test email sent using a simple SMTP client in C.\n";

    smtp_client(smtp_server, from_email, to_email, subject, body);

    return EXIT_SUCCESS;
}