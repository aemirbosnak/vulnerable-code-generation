//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

void smtp_send(int socket, const char *message) {
    send(socket, message, strlen(message), 0);
    char buffer[BUFFER_SIZE] = {0};
    recv(socket, buffer, BUFFER_SIZE - 1, 0);
    printf("%s", buffer);
}

void smtp_client(const char *server, const char *from_email, const char *to_email, const char *subject, const char *body) {
    int sock;
    struct sockaddr_in server_addr;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr(server);

    // Connect to the SMTP server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to SMTP server failed");
        exit(EXIT_FAILURE);
    }

    // Greet the server
    smtp_send(sock, "HELO localhost\r\n");
    
    // From
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "MAIL FROM:<%s>\r\n", from_email);
    smtp_send(sock, command);

    // To
    snprintf(command, sizeof(command), "RCPT TO:<%s>\r\n", to_email);
    smtp_send(sock, command);

    // Data
    smtp_send(sock, "DATA\r\n");
    snprintf(command, sizeof(command), "Subject: %s\r\nFrom: %s\r\nTo: %s\r\n\r\n%s\r\n.\r\n", subject, from_email, to_email, body);
    smtp_send(sock, command);

    // Quit
    smtp_send(sock, "QUIT\r\n");

    // Close socket
    close(sock);
}

int main() {
    char server[100], from_email[100], to_email[100], subject[100], body[512];

    printf("Welcome to the Retro SMTP Client!\n");
    printf("Enter SMTP server address (e.g., 192.168.1.1): ");
    scanf("%99s", server);
    printf("Enter your email address: ");
    scanf("%99s", from_email);
    printf("Enter recipient email address: ");
    scanf("%99s", to_email);
    printf("Enter email subject: ");
    scanf(" %[^\n]", subject); // Read until newline
    printf("Enter email body (max 512 characters):\n");
    scanf(" %[^\n]", body); // Read until newline

    smtp_client(server, from_email, to_email, subject, body);

    printf("Email sent successfully!\n");
    return 0;
}