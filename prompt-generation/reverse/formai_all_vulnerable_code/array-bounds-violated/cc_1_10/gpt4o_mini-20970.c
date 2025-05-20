//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SMTP_PORT 587
#define BUFFER_SIZE 1024

void handle_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void send_command(int sock, const char *cmd) {
    send(sock, cmd, strlen(cmd), 0);
    printf("> %s", cmd);
}

void receive_response(int sock) {
    char buffer[BUFFER_SIZE];
    int len = recv(sock, buffer, sizeof(buffer)-1, 0);
    if (len < 0) {
        handle_error("recv failed");
    }
    buffer[len] = '\0';
    printf("< %s", buffer);
}

int main() {
    const char *smtp_server = "smtp.example.com"; // Replace with your SMTP server
    const char *email_from = "from@example.com"; // Replace with sender's email
    const char *email_to = "to@example.com"; // Replace with recipient's email
    const char *subject = "Test Email Subject";
    const char *body = "This is a test email body.";
    
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        handle_error("socket creation failed");
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SMTP_PORT);
    server_address.sin_addr.s_addr = inet_addr("192.0.2.0"); // Replace with SMTP server IP

    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        handle_error("connection failed");
    }

    receive_response(sock);
    
    send_command(sock, "EHLO localhost\r\n");
    receive_response(sock);

    send_command(sock, "MAIL FROM:<from@example.com>\r\n");
    receive_response(sock);

    send_command(sock, "RCPT TO:<to@example.com>\r\n");
    receive_response(sock);
    
    send_command(sock, "DATA\r\n");
    receive_response(sock);
    
    // Sending email headers and body
    char email_message[BUFFER_SIZE];
    snprintf(email_message, sizeof(email_message),
             "Subject: %s\r\n"
             "From: %s\r\n"
             "To: %s\r\n"
             "\r\n"
             "%s\r\n"
             ".\r\n",
             subject, email_from, email_to, body);
    
    send_command(sock, email_message);
    receive_response(sock);
    
    send_command(sock, "QUIT\r\n");
    receive_response(sock);
    
    close(sock);
    return 0;
}