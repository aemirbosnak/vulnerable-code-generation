//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define SMTP_PORT 587
#define BUFFER_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void send_command(int socket, const char *cmd) {
    if (send(socket, cmd, strlen(cmd), 0) < 0) {
        die("Send failed");
    }
}

void read_response(int socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // For paranoia, we ensure the buffer is zeroed out
    memset(buffer, 0, sizeof(buffer));
    bytes_received = recv(socket, buffer, sizeof(buffer) - 1, 0);
    
    if (bytes_received < 0) {
        die("Receive failed");
    }

    buffer[bytes_received] = '\0'; // Null-terminate the response
    printf("Server response: %s", buffer);
    
    // Check for success code
    if (strncmp(buffer, "250", 3) != 0 && strncmp(buffer, "220", 3) != 0 && strncmp(buffer, "354", 3) != 0) {
        fprintf(stderr, "Unexpected response from server: %s", buffer);
        exit(EXIT_FAILURE);
    }
}

int main() {
    const char *server = "smtp.example.com"; // Replace with your SMTP server
    const char *user = "user@example.com";    // SMTP user
    const char *pass = "password";            // SMTP password
    const char *recipient = "recipient@example.com"; // Recipient email
    const char *subject = "Test Email";       // Subject of the email
    const char *message = "Hello, this is a test email."; // Email content

    int socket_desc;
    struct sockaddr_in server_address;
    
    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        die("Could not create socket");
    }

    // Setup server address struct
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SMTP_PORT);
    if (inet_pton(AF_INET, server, &server_address.sin_addr) <= 0) {
        die("Invalid address");
    }

    // Connect to server
    if (connect(socket_desc, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        die("Connect failed");
    }
    
    // Receive welcome message
    read_response(socket_desc);

    // Send EHLO
    char ehlo_command[BUFFER_SIZE];
    snprintf(ehlo_command, sizeof(ehlo_command), "EHLO %s\r\n", user);
    send_command(socket_desc, ehlo_command);
    read_response(socket_desc);

    // Authenticate with AUTH LOGIN
    send_command(socket_desc, "AUTH LOGIN\r\n");
    read_response(socket_desc);

    // Send username
    char encoded_user[BUFFER_SIZE]; // This would normally be base64 encoded for real use.
    snprintf(encoded_user, sizeof(encoded_user), "%s\r\n", "dXNlckBleGFtcGxlLmNvbQ=="); // base64 of "user@example.com"
    send_command(socket_desc, encoded_user);
    read_response(socket_desc);

    // Send password
    char encoded_pass[BUFFER_SIZE]; // This would normally be base64 encoded for real use.
    snprintf(encoded_pass, sizeof(encoded_pass), "%s\r\n", "cGFzc3dvcmQ=\n"); // base64 of "password"
    send_command(socket_desc, encoded_pass);
    read_response(socket_desc);

    // Send MAIL FROM
    char mail_from_command[BUFFER_SIZE];
    snprintf(mail_from_command, sizeof(mail_from_command), "MAIL FROM:<%s>\r\n", user);
    send_command(socket_desc, mail_from_command);
    read_response(socket_desc);

    // Send RCPT TO
    char rcpt_to_command[BUFFER_SIZE];
    snprintf(rcpt_to_command, sizeof(rcpt_to_command), "RCPT TO:<%s>\r\n", recipient);
    send_command(socket_desc, rcpt_to_command);
    read_response(socket_desc);

    // Send DATA
    send_command(socket_desc, "DATA\r\n");
    read_response(socket_desc);

    // Send email content
    char email_content[BUFFER_SIZE];
    snprintf(email_content, sizeof(email_content), "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, message);
    send_command(socket_desc, email_content);
    read_response(socket_desc);

    // Send QUIT
    send_command(socket_desc, "QUIT\r\n");
    read_response(socket_desc);

    // Cleanup
    close(socket_desc);
    
    printf("Email sent successfully!\n");
    return 0;
}