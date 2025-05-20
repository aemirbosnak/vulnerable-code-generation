//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int socket, const char *cmd) {
    send(socket, cmd, strlen(cmd), 0);
    printf("<< Sending: %s", cmd);
}

void receive_response(int socket) {
    char buffer[BUFFER_SIZE];
    int n = recv(socket, buffer, sizeof(buffer)-1, 0);
    buffer[n] = '\0';
    printf(">> Received: %s", buffer);
}

void smtp_send_email(const char *smtp_server, const char *from, const char *to, const char *subject, const char *body) {
    int sock;
    struct sockaddr_in server_addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        error("Error opening socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr(smtp_server);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }

    receive_response(sock);
    send_command(sock, "HELO localdomain\r\n");
    receive_response(sock);
    
    char msg[BUFFER_SIZE];
    snprintf(msg, sizeof(msg), "MAIL FROM:<%s>\r\n", from);
    send_command(sock, msg);
    receive_response(sock);

    snprintf(msg, sizeof(msg), "RCPT TO:<%s>\r\n", to);
    send_command(sock, msg);
    receive_response(sock);

    send_command(sock, "DATA\r\n");
    receive_response(sock);

    snprintf(msg, sizeof(msg), "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    send_command(sock, msg);
    receive_response(sock);

    send_command(sock, "QUIT\r\n");
    receive_response(sock);

    close(sock);
}

int main() {
    const char *smtp_server = "127.0.0.1";  // Replace with your SMTP server address
    const char *from = "sender@example.com"; // Sender's email address
    const char *to = "recipient@example.com"; // Recipient's email address
    const char *subject = "Hello, SMTP!";
    const char *body = "This is a test email sent from a simple SMTP client in C.";

    printf("Starting SMTP Client...\n");
    smtp_send_email(smtp_server, from, to, subject, body);
    printf("Email sent successfully!\n");

    return 0;
}