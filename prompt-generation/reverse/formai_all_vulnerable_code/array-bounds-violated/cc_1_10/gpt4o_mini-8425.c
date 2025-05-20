//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 587
#define BUFFER_SIZE 1024

void send_command(int sock, const char *cmd) {
    send(sock, cmd, strlen(cmd), 0);
    printf("Sent: %s", cmd);
}

void receive_response(int sock) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0);
    buffer[bytes_received] = '\0';
    printf("Received: %s", buffer);
}

int main() {
    char *server = "smtp.example.com"; // Replace with your SMTP server
    char *from = "you@example.com";     // Your email
    char *to = "recipient@example.com";  // Recipient email
    char *subject = "Test Email";
    char *body = "Hello, this is a test email from my C email client.";

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, server, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(sock);
        return EXIT_FAILURE;
    }

    receive_response(sock);

    send_command(sock, "EHLO localhost\r\n");
    receive_response(sock);

    send_command(sock, "AUTH LOGIN\r\n");
    receive_response(sock);
    
    // Base64 encode your username and password
    send_command(sock, "YOUR_BASE64_ENCODED_EMAIL\r\n");
    receive_response(sock);
    
    send_command(sock, "YOUR_BASE64_ENCODED_PASSWORD\r\n");
    receive_response(sock);

    send_command(sock, "MAIL FROM:<you@example.com>\r\n");
    receive_response(sock);

    send_command(sock, "RCPT TO:<recipient@example.com>\r\n");
    receive_response(sock);

    send_command(sock, "DATA\r\n");
    receive_response(sock);

    char email[BUFFER_SIZE];
    snprintf(email, sizeof(email), "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    send_command(sock, email);
    receive_response(sock);

    send_command(sock, "QUIT\r\n");
    receive_response(sock);

    close(sock);
    return EXIT_SUCCESS;
}