//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define SMTP_PORT 587

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int socket, const char *command) {
    send(socket, command, strlen(command), 0);
}

void receive_response(int socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(socket, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        error("Receive failed");
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);
}

int main() {
    int socket_desc;
    struct sockaddr_in server;
    char recipient[100], sender[100], subject[100], message[500];

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        error("Could not create socket");
    }
    printf("Socket created successfully!\n");

    // Setup server info
    server.sin_family = AF_INET;
    server.sin_port = htons(SMTP_PORT);
    server.sin_addr.s_addr = inet_addr("smtp.gmail.com");

    // Connect to the server
    if (connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        error("Connection failed");
    }
    printf("Connected to SMTP server!\n");

    receive_response(socket_desc); // Receive greeting from the server
    send_command(socket_desc, "HELO localhost\r\n");
    receive_response(socket_desc);

    // User input for email
    printf("Enter sender's email: ");
    fgets(sender, sizeof(sender), stdin);
    sender[strcspn(sender, "\n")] = 0; // Remove newline
    printf("Enter recipient's email: ");
    fgets(recipient, sizeof(recipient), stdin);
    recipient[strcspn(recipient, "\n")] = 0; // Remove newline
    printf("Enter subject: ");
    fgets(subject, sizeof(subject), stdin);
    subject[strcspn(subject, "\n")] = 0; // Remove newline
    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0; // Remove newline

    // Send AUTH LOGIN
    send_command(socket_desc, "AUTH LOGIN\r\n");
    receive_response(socket_desc);

    // For simplicity: Login credentials are not base64 encoded
    send_command(socket_desc, "base64_encoded_username\r\n");
    receive_response(socket_desc);
    send_command(socket_desc, "base64_encoded_password\r\n");
    receive_response(socket_desc);

    // Begin Mail
    send_command(socket_desc, "MAIL FROM:<");
    send_command(socket_desc, sender);
    send_command(socket_desc, ">\r\n");
    receive_response(socket_desc);

    // Recipient
    send_command(socket_desc, "RCPT TO:<");
    send_command(socket_desc, recipient);
    send_command(socket_desc, ">\r\n");
    receive_response(socket_desc);

    // Data
    send_command(socket_desc, "DATA\r\n");
    receive_response(socket_desc);

    // Send email headers
    send_command(socket_desc, "Subject: ");
    send_command(socket_desc, subject);
    send_command(socket_desc, "\r\n");
    send_command(socket_desc, "\r\n"); // To start the message body
    send_command(socket_desc, message);
    send_command(socket_desc, "\r\n.\r\n"); // Ending the email
    receive_response(socket_desc);

    // Quit
    send_command(socket_desc, "QUIT\r\n");
    receive_response(socket_desc);

    close(socket_desc);
    printf("Email sent successfully! Exiting...\n");
    return 0;
}