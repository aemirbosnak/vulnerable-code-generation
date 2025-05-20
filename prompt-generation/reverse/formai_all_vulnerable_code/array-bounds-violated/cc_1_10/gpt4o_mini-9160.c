//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>

#define PORT 110    // POP3 port number
#define BUFFER_SIZE 1024
#define MAX_EMAILS 100
#define SMTP_PORT 25 // SMTP port for sending emails
#define SMTP_SERVER "smtp.example.com" // Change this to your SMTP server

void die(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void readEmails(int socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Wait for server response
    if ((bytes_received = recv(socket, buffer, sizeof(buffer) - 1, 0)) < 0) {
        die("Failed to receive data from server");
    }
    buffer[bytes_received] = '\0';
    printf("Server: %s\n", buffer);

    // Send command to retrieve email list
    send(socket, "LIST\r\n", 6, 0);
    if ((bytes_received = recv(socket, buffer, sizeof(buffer) - 1, 0)) < 0) {
        die("Failed to receive data from server");
    }
    buffer[bytes_received] = '\0';
    printf("Email List:\n%s\n", buffer);
}

void sendEmail(const char *to, const char *subject, const char *body) {
    int sock;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
        die("Could not create socket");

    server.sin_family = AF_INET;
    server.sin_port = htons(SMTP_PORT);
    inet_pton(AF_INET, SMTP_SERVER, &server.sin_addr);

    // Connect to SMTP server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        die("Connect failed");
    }

    recv(sock, buffer, sizeof(buffer) - 1, 0); // initial server response

    snprintf(buffer, sizeof(buffer), "HELO localhost\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer) - 1, 0);

    snprintf(buffer, sizeof(buffer), "MAIL FROM:<sender@example.com>\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer) - 1, 0);

    snprintf(buffer, sizeof(buffer), "RCPT TO:<%s>\r\n", to);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer) - 1, 0);

    send(sock, "DATA\r\n", 6, 0);
    recv(sock, buffer, sizeof(buffer) - 1, 0);

    snprintf(buffer, sizeof(buffer), "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, sizeof(buffer) - 1, 0);

    send(sock, "QUIT\r\n", 6, 0);
    recv(sock, buffer, sizeof(buffer) - 1, 0);

    close(sock);
    printf("Email sent successfully to %s\n", to);
}

int main() {
    int sock;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
        die("Could not create socket");

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); // Connect to localhost for demo

    // Connect to POP3 server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        die("Connect failed");
    }

    recv(sock, buffer, BUFFER_SIZE - 1, 0); // Wait for server greeting

    readEmails(sock);

    // Example email sending
    const char *to = "recipient@example.com";
    const char *subject = "Test Email";
    const char *body = "Hello, this is a test email from our C email client!";
    sendEmail(to, subject, body);

    close(sock);
    return 0;
}