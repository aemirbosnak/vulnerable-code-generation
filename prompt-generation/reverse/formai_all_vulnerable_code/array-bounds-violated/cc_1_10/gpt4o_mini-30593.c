//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

void error_exit(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void send_command(int socket, const char *command) {
    if (send(socket, command, strlen(command), 0) == -1) {
        error_exit("Failed to send command");
    }
}

void read_response(int socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received <= 0) {
        error_exit("Failed to read response");
    }
    buffer[bytes_received] = '\0';
    printf("%s", buffer);
}

int main() {
    int socket_fd;
    struct sockaddr_in smtp_server;
    const char *server_address = "smtp.example.com"; // Replace with actual SMTP server
    const char *from_address = "sender@example.com"; // Change to your sender address
    const char *to_address = "recipient@example.com"; // Change to your recipient address
    const char *subject = "Test Email";
    const char *message = "Hello, this is a test email from my SMTP client!";

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        error_exit("Unable to create socket");
    }

    smtp_server.sin_family = AF_INET;
    smtp_server.sin_port = htons(SMTP_PORT);
    smtp_server.sin_addr.s_addr = inet_addr("192.0.2.1"); // Replace with actual SMTP server IP

    if (connect(socket_fd, (struct sockaddr *)&smtp_server, sizeof(smtp_server)) < 0) {
        error_exit("Connection to SMTP server failed");
    }

    read_response(socket_fd);

    send_command(socket_fd, "HELO localhost\r\n");
    read_response(socket_fd);

    send_command(socket_fd, "MAIL FROM:<sender@example.com>\r\n");
    read_response(socket_fd);

    send_command(socket_fd, "RCPT TO:<recipient@example.com>\r\n");
    read_response(socket_fd);

    send_command(socket_fd, "DATA\r\n");
    read_response(socket_fd);

    // Constructing the email headers and body
    char email_buffer[BUFFER_SIZE];
    snprintf(email_buffer, sizeof(email_buffer),
        "From: %s\r\n"
        "To: %s\r\n"
        "Subject: %s\r\n"
        "\r\n"
        "%s\r\n"
        ".\r\n",
        from_address, to_address, subject, message);

    send_command(socket_fd, email_buffer);
    read_response(socket_fd);

    send_command(socket_fd, "QUIT\r\n");
    read_response(socket_fd);

    close(socket_fd);
    return 0;
}