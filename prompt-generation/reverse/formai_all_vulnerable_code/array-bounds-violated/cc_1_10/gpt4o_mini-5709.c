//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 587
#define BUFFER_SIZE 1024

void send_command(int sock, const char *cmd) {
    send(sock, cmd, strlen(cmd), 0);
    printf("Sent: %s", cmd);
}

void receive_response(int sock) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';
        printf("Received: %s", buffer);
    }
}

int main() {
    int sock;
    struct sockaddr_in server_address;
    
    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return EXIT_FAILURE;
    }

    // Configure server address
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = inet_addr("SMTP_SERVER"); // Replace with actual SMTP server IP

    // Connect to SMTP server
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection to SMTP server failed");
        close(sock);
        return EXIT_FAILURE;
    }

    receive_response(sock);  // Welcome message from server

    // EHLO command
    send_command(sock, "EHLO localhost\r\n");
    receive_response(sock);

    // Start TLS
    send_command(sock, "STARTTLS\r\n");
    receive_response(sock);

    // Here, you could implement TLS handshake if needed

    // Authenticate
    send_command(sock, "AUTH LOGIN\r\n");
    receive_response(sock);
    
    // Send username and password (Base64 encoded)
    send_command(sock, "USERNAME_BASE64\r\n");  // Replace with Base64 encoded username
    receive_response(sock);
    send_command(sock, "PASSWORD_BASE64\r\n");  // Replace with Base64 encoded password
    receive_response(sock);

    // From address
    send_command(sock, "MAIL FROM:<FROM_EMAIL>\r\n"); // Replace with your email
    receive_response(sock);

    // To address
    send_command(sock, "RCPT TO:<TO_EMAIL>\r\n"); // Replace with recipient email
    receive_response(sock);

    // Email data
    send_command(sock, "DATA\r\n");
    receive_response(sock);
    
    // Email content
    send_command(sock, "Subject: Test Email\r\n");
    send_command(sock, "From: FROM_EMAIL\r\n"); // Replace with your email
    send_command(sock, "To: TO_EMAIL\r\n"); // Replace with recipient email
    send_command(sock, "\r\n");
    send_command(sock, "This is a test email sent via SMTP client in C.\r\n");
    send_command(sock, ".\r\n");
    receive_response(sock);

    // Quit command
    send_command(sock, "QUIT\r\n");
    receive_response(sock);

    // Close socket
    close(sock);
    return EXIT_SUCCESS;
}