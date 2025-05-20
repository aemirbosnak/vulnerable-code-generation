//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SMTP_PORT 587
#define BUFFER_SIZE 1024

void send_command(int socket, const char *command) {
    send(socket, command, strlen(command), 0);
    printf("Sent: %s", command);
}

void read_response(int socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';
        printf("Received: %s", buffer);
    } else {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
}

int create_socket() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sock;
}

void connect_to_server(int socket, const char *server_name) {
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SMTP_PORT);
    inet_pton(AF_INET, server_name, &server_address.sin_addr);

    if (connect(socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }
    printf("Connected to SMTP server: %s\n", server_name);
}

void authenticate(int socket, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    // HELO command
    send_command(socket, "HELO localhost\r\n");
    read_response(socket);

    // AUTH LOGIN command
    send_command(socket, "AUTH LOGIN\r\n");
    read_response(socket);

    // Sending username
    snprintf(command, sizeof(command), "%s\r\n", username);
    send_command(socket, command);
    read_response(socket);

    // Sending password
    snprintf(command, sizeof(command), "%s\r\n", password);
    send_command(socket, command);
    read_response(socket);
}

void send_email(int socket, const char *from, const char *to, const char *subject, const char *body) {
    char command[BUFFER_SIZE];

    // MAIL FROM command
    snprintf(command, sizeof(command), "MAIL FROM:<%s>\r\n", from);
    send_command(socket, command);
    read_response(socket);

    // RCPT TO command
    snprintf(command, sizeof(command), "RCPT TO:<%s>\r\n", to);
    send_command(socket, command);
    read_response(socket);

    // DATA command
    send_command(socket, "DATA\r\n");
    read_response(socket);

    // Sending email headers and body
    snprintf(command, sizeof(command), "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    send_command(socket, command);
    read_response(socket);
}

void quit_connection(int socket) {
    send_command(socket, "QUIT\r\n");
    read_response(socket);
    close(socket);
    printf("Disconnected from SMTP server.\n");
}

int main() {
    const char *smtp_server = "smtp.example.com"; // Replace with actual SMTP server
    const char *username = "your_username"; // Replace with actual username
    const char *password = "your_password"; // Replace with actual password
    const char *from = "you@example.com"; // Replace with actual sender email
    const char *to = "recipient@example.com"; // Replace with actual recipient email
    const char *subject = "Shockingly Simple SMTP Test";
    const char *body = "Hello! This is a shocking SMTP client test message sent from C!";

    int socket = create_socket();
    connect_to_server(socket, smtp_server);
    authenticate(socket, username, password);
    send_email(socket, from, to, subject, body);
    quit_connection(socket);

    return 0;
}