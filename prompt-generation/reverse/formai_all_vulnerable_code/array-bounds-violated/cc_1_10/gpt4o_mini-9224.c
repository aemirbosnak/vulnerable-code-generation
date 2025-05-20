//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER "smtp.example.com" // SMTP server, replace with a real one
#define PORT 587 // Port for SMTP
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
    printf("C: %s", cmd);
}

void receive_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (n < 0) error("ERROR reading from socket");
    buffer[n] = '\0';
    printf("S: %s", buffer);
}

void smtp_auth(int sockfd) {
    send_command(sockfd, "EHLO localhost\r\n");
    receive_response(sockfd);
    send_command(sockfd, "AUTH LOGIN\r\n");
    receive_response(sockfd);

    // Example credentials (base64 encoded, replace with real credentials)
    send_command(sockfd, "YWRtaW4=\r\n"); // base64 for "admin"
    receive_response(sockfd);
    send_command(sockfd, "cGFzc3cwcmQ=\r\n"); // base64 for "password"
    receive_response(sockfd);
}

void send_email(int sockfd, const char *from, const char *to, const char *subject, const char *body) {
    send_command(sockfd, "MAIL FROM: <");
    send(sockfd, from, strlen(from), 0);
    send_command(sockfd, ">\r\n");
    receive_response(sockfd);

    send_command(sockfd, "RCPT TO: <");
    send(sockfd, to, strlen(to), 0);
    send_command(sockfd, ">\r\n");
    receive_response(sockfd);

    send_command(sockfd, "DATA\r\n");
    receive_response(sockfd);

    // Prepare the email headers and body
    char email[BUFFER_SIZE];
    snprintf(email, sizeof(email),
        "From: %s\r\n"
        "To: %s\r\n"
        "Subject: %s\r\n"
        "\r\n"
        "%s\r\n"
        ".\r\n", 
        from, to, subject, body);
    
    send(sockfd, email, strlen(email), 0);
    receive_response(sockfd);
}

void close_connection(int sockfd) {
    send_command(sockfd, "QUIT\r\n");
    receive_response(sockfd);
    close(sockfd);
}

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("ERROR opening socket");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, SERVER, &serv_addr.sin_addr) <= 0) {
        error("ERROR invalid address/ address not supported");
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    // Initial response
    receive_response(sockfd);

    // Authenticate and send email
    smtp_auth(sockfd);
    
    const char *from = "sender@example.com";
    const char *to = "recipient@example.com";
    const char *subject = "Hello from SMTP Client";
    const char *body = "This is a test email sent from a simple SMTP client implemented in C.";

    send_email(sockfd, from, to, subject, body);

    // Close connection
    close_connection(sockfd);

    return 0;
}