//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SMTP_PORT   25
#define BUFFER_SIZE 1024

const char *server_ip = "smtp.server.com";
const char *sender_email = "sender@server.com";
const char *receiver_email = "receiver@server.com";
const char *subject = "Test email";
const char *message = "This is a test email.";

int main() {
    // Create a socket for connecting to the SMTP server
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Resolve the SMTP server's IP address
    struct hostent *server = gethostbyname(server_ip);
    if (server == NULL) {
        fprintf(stderr, "Failed to resolve server IP address\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the server address structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // Connect to the SMTP server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Wait for the server's greeting message
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        perror("Receiving greeting message failed");
        exit(EXIT_FAILURE);
    }
    printf("%.*s", bytes_received, buffer);

    // Send the HELO command
    const char *helo_command = "HELO client.server.com\r\n";
    if (send(sock, helo_command, strlen(helo_command), 0) < 0) {
        perror("Sending HELO command failed");
        exit(EXIT_FAILURE);
    }
    printf("%s", helo_command);

    // Wait for the server's response
    bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        perror("Receiving response failed");
        exit(EXIT_FAILURE);
    }
    printf("%.*s", bytes_received, buffer);

    // Send the MAIL FROM command
    const char *mail_from_command = "MAIL FROM: <sender@server.com>\r\n";
    if (send(sock, mail_from_command, strlen(mail_from_command), 0) < 0) {
        perror("Sending MAIL FROM command failed");
        exit(EXIT_FAILURE);
    }
    printf("%s", mail_from_command);

    // Wait for the server's response
    bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        perror("Receiving response failed");
        exit(EXIT_FAILURE);
    }
    printf("%.*s", bytes_received, buffer);

    // Send the RCPT TO command
    const char *rcpt_to_command = "RCPT TO: <receiver@server.com>\r\n";
    if (send(sock, rcpt_to_command, strlen(rcpt_to_command), 0) < 0) {
        perror("Sending RCPT TO command failed");
        exit(EXIT_FAILURE);
    }
    printf("%s", rcpt_to_command);

    // Wait for the server's response
    bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        perror("Receiving response failed");
        exit(EXIT_FAILURE);
    }
    printf("%.*s", bytes_received, buffer);

    // Send the DATA command
    const char *data_command = "DATA\r\n";
    if (send(sock, data_command, strlen(data_command), 0) < 0) {
        perror("Sending DATA command failed");
        exit(EXIT_FAILURE);
    }
    printf("%s", data_command);

    // Wait for the server's response
    bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        perror("Receiving response failed");
        exit(EXIT_FAILURE);
    }
    printf("%.*s", bytes_received, buffer);

    // Send the email contents
    char email[BUFFER_SIZE];
    sprintf(email, "From: <%s>\r\nTo: <%s>\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", sender_email, receiver_email, subject, message);
    if (send(sock, email, strlen(email), 0) < 0) {
        perror("Sending email failed");
        exit(EXIT_FAILURE);
    }
    printf("%s", email);

    // Wait for the server's response
    bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        perror("Receiving response failed");
        exit(EXIT_FAILURE);
    }
    printf("%.*s", bytes_received, buffer);

    // Send the QUIT command
    const char *quit_command = "QUIT\r\n";
    if (send(sock, quit_command, strlen(quit_command), 0) < 0) {
        perror("Sending QUIT command failed");
        exit(EXIT_FAILURE);
    }
    printf("%s", quit_command);

    // Wait for the server's response
    bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        perror("Receiving response failed");
        exit(EXIT_FAILURE);
    }
    printf("%.*s", bytes_received, buffer);

    // Close the socket
    close(sock);

    return 0;
}