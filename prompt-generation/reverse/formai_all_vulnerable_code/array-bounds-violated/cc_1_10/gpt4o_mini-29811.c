//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

void send_command(int socket, const char *command) {
    send(socket, command, strlen(command), 0);
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(socket, buffer, BUFFER_SIZE - 1, 0);
    buffer[bytes_received] = '\0'; // Null-terminate the response
    printf("Server Response: %s", buffer);
}

int main() {
    char *server_address = "smtp.example.com"; // Change to actual SMTP server
    char *from_email = "your_email@example.com"; // Change to your email
    char *to_email = "recipient_email@example.com"; // Change to recipient's email
    char *subject = "Subject: Test Email\r\n";
    char *body = "Hello, this is a test email sent from a simple SMTP client.\r\n";
    
    int sock;
    struct sockaddr_in server;
    
    // Creating TCP socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Unable to create socket");
        return EXIT_FAILURE;
    }
    
    // Server information
    server.sin_family = AF_INET;
    server.sin_port = htons(SMTP_PORT);
    inet_pton(AF_INET, server_address, &server.sin_addr);
    
    // Connecting to the SMTP server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connection failed");
        return EXIT_FAILURE;
    }
    
    // Initial SMTP handshake
    send_command(sock, "HELO localhost\r\n");
    
    // Send MAIL FROM command
    char mail_from_command[BUFFER_SIZE];
    snprintf(mail_from_command, BUFFER_SIZE, "MAIL FROM:<%s>\r\n", from_email);
    send_command(sock, mail_from_command);
    
    // Send RCPT TO command
    char rcpt_to_command[BUFFER_SIZE];
    snprintf(rcpt_to_command, BUFFER_SIZE, "RCPT TO:<%s>\r\n", to_email);
    send_command(sock, rcpt_to_command);
    
    // Send DATA command
    send_command(sock, "DATA\r\n");
    
    // Preparing email header and body
    char email_message[BUFFER_SIZE];
    snprintf(email_message, BUFFER_SIZE,
             "%sFrom: %s\r\nTo: %s\r\n%s\r\n%s.\r\n",
             subject,
             from_email,
             to_email,
             "Content-Type: text/plain; charset=UTF-8\r\n",
             body);
    
    // Send the email message
    send_command(sock, email_message);

    // Sending QUIT command
    send_command(sock, "QUIT\r\n");

    // Closing the socket
    close(sock);
    printf("Email sent successfully!\n");

    return EXIT_SUCCESS;
}