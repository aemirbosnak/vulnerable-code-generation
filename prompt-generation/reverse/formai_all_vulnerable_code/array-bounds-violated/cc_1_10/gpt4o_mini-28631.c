//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

void send_command(int sock, const char *cmd) {
    send(sock, cmd, strlen(cmd), 0);
    send(sock, "\r\n", 2, 0);
}

void read_response(int sock) {
    char buffer[BUFFER_SIZE];
    int bytes = recv(sock, buffer, sizeof(buffer)-1, 0);
    buffer[bytes] = '\0';
    printf("%s", buffer);
}

int main() {
    int sock;
    struct sockaddr_in server;
    char *smtp_server = "smtp.example.com"; // Replace with your SMTP server
    char *from_email = "you@example.com";   // Your email
    char *to_email = "recipient@example.com"; // Recipient email
    char *subject = "Test Email from C";
    char *body = "Hello, this is a test email sent from a C program.";

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Socket creation failed");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(SMTP_PORT);
    inet_pton(AF_INET, smtp_server, &server.sin_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connection to server failed");
        return 1;
    }

    read_response(sock);
    
    // EHLO command
    send_command(sock, "EHLO localhost");
    read_response(sock);
    
    // MAIL FROM command
    char mail_from_command[BUFFER_SIZE];
    snprintf(mail_from_command, sizeof(mail_from_command), "MAIL FROM:<%s>", from_email);
    send_command(sock, mail_from_command);
    read_response(sock);
    
    // RCPT TO command
    char rcpt_to_command[BUFFER_SIZE];
    snprintf(rcpt_to_command, sizeof(rcpt_to_command), "RCPT TO:<%s>", to_email);
    send_command(sock, rcpt_to_command);
    read_response(sock);
    
    // DATA command
    send_command(sock, "DATA");
    read_response(sock);
    
    // Email header and body
    char email[BUFFER_SIZE];
    snprintf(email, sizeof(email),
             "From: %s\r\n"
             "To: %s\r\n"
             "Subject: %s\r\n"
             "\r\n"
             "%s\r\n"
             ".",
             from_email, to_email, subject, body);
    
    send(sock, email, strlen(email), 0);
    read_response(sock);
    
    // QUIT command
    send_command(sock, "QUIT");
    read_response(sock);
    
    close(sock);
    return 0;
}