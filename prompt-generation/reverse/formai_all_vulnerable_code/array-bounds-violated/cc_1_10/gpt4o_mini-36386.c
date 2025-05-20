//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SMTP_PORT 587
#define BUFFER_SIZE 1024

void send_command(int socket, const char *command) {
    send(socket, command, strlen(command), 0);
    printf("Sent: %s", command);
}

void receive_response(int socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(socket, buffer, BUFFER_SIZE - 1, 0);
    buffer[bytes_received] = '\0';
    printf("Received: %s", buffer);
}

int main() {
    int smtp_socket;
    struct sockaddr_in server_addr;

    // Buffer for SMTP commands
    char buffer[BUFFER_SIZE];

    // Create socket
    smtp_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (smtp_socket < 0) {
        perror("Socket creation failed");
        return 1;
    }

    // Set up server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr("YOUR_SMTP_SERVER_IP"); // Replace with actual SMTP server IP

    // Connect to the SMTP server
    if (connect(smtp_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(smtp_socket);
        return 1;
    }

    receive_response(smtp_socket); // Get server greeting

    // Send EHLO command
    send_command(smtp_socket, "EHLO localhost\r\n");
    receive_response(smtp_socket);
    
    // Start TLS (only if your server requires it)
    send_command(smtp_socket, "STARTTLS\r\n");
    receive_response(smtp_socket);

    // Here you would typically initiate TLS connections, omitted for simplicity

    // Sending Mail from
    send_command(smtp_socket, "MAIL FROM:<sender@example.com>\r\n");
    receive_response(smtp_socket);

    // Send recipient
    send_command(smtp_socket, "RCPT TO:<recipient@example.com>\r\n");
    receive_response(smtp_socket);

    // Send DATA command
    send_command(smtp_socket, "DATA\r\n");
    receive_response(smtp_socket);

    // Sending email body
    snprintf(buffer, sizeof(buffer), 
        "Subject: Test Email\r\n"
        "From: Sender <sender@example.com>\r\n"
        "To: Recipient <recipient@example.com>\r\n\r\n"
        "This is a test email sent from my SMTP client written in C.\r\n"
        ".\r\n"); // Ending the email body with a single dot

    send(smtp_socket, buffer, strlen(buffer), 0);
    receive_response(smtp_socket);

    // Send QUIT command
    send_command(smtp_socket, "QUIT\r\n");
    receive_response(smtp_socket);

    // Clean up and close socket
    close(smtp_socket);
    printf("Connection closed.\n");

    return 0;
}