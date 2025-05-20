//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 512

void send_email(int sock, const char *sender, const char *recipient, const char *subject, const char *message) {
    char buffer[BUFFER_SIZE];
    
    // Send HELO command
    sprintf(buffer, "HELO localhost\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("Server: %s", buffer);
    
    // Send MAIL FROM command
    sprintf(buffer, "MAIL FROM:<%s>\r\n", sender);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("Server: %s", buffer);
    
    // Send RCPT TO command
    sprintf(buffer, "RCPT TO:<%s>\r\n", recipient);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("Server: %s", buffer);
    
    // Send DATA command
    sprintf(buffer, "DATA\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("Server: %s", buffer);
    
    // Prepare and send email body
    sprintf(buffer, "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, message);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("Server: %s", buffer);
    
    // Send QUIT command
    sprintf(buffer, "QUIT\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer), 0);
    printf("Server: %s", buffer);
}

int main() {
    int sock;
    struct sockaddr_in server;
    char server_ip[256];
    char sender[256], recipient[256], subject[256], message[1024];

    // Set up server information
    printf("Enter SMTP Server IP Address: ");
    scanf("%s", server_ip);

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return 1;
    }

    // Configure server structure
    server.sin_family = AF_INET;
    server.sin_port = htons(25); // SMTP port
    server.sin_addr.s_addr = inet_addr(server_ip);

    // Connect to the SMTP server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connection to the server failed");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    recv(sock, buffer, sizeof(buffer), 0);
    printf("Server: %s", buffer);

    // Gather email information
    printf("Enter your email address (sender): ");
    scanf("%s", sender);
    printf("Enter recipient email address: ");
    scanf("%s", recipient);
    printf("Enter email subject: ");
    scanf(" %[^\n]", subject); // Read string with spaces
    printf("Enter email message: ");
    scanf(" %[^\n]", message); // Read string with spaces
    
    // Send the email
    send_email(sock, sender, recipient, subject, message);
    
    // Clean up and close the socket
    close(sock);
    printf("Email sent successfully!\n");

    return 0;
}