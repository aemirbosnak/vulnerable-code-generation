//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

void die(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void check_response(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
        die("Failed to read response from server");
    }
    buffer[bytes_received] = 0; // Null terminate the received string
    printf("Server Response: %s", buffer);
}

void send_command(int sockfd, const char *command) {
    send(sockfd, command, strlen(command), 0);
    check_response(sockfd);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        die("Socket creation failed");
    }

    // Prepare the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        die("Invalid address / Address not supported");
    }

    // Connect to the SMTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        die("Connection to the SMTP server failed");
    }

    // Handshake with the SMTP server
    check_response(sockfd); // Expecting a greeting response
    send_command(sockfd, "HELO localhost\r\n");

    // Prepare email parameters
    const char *from = "sender@example.com";
    const char *to = "recipient@example.com";
    const char *subject = "Test Email";
    const char *body = "This is a test email sent from a paranoid C SMTP client.";

    // Set sender
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "MAIL FROM:<%s>\r\n", from);
    send_command(sockfd, command);

    // Set recipient
    snprintf(command, sizeof(command), "RCPT TO:<%s>\r\n", to);
    send_command(sockfd, command);

    // Start the email transmission
    send_command(sockfd, "DATA\r\n");

    // Prepare and send the email data
    snprintf(command, sizeof(command), "Subject: %s\r\nFrom: %s\r\nTo: %s\r\n\r\n%s\r\n.\r\n", 
             subject, from, to, body);
    send(sockfd, command, strlen(command), 0);
    check_response(sockfd); // Expecting a response after sending data

    // End the session
    send_command(sockfd, "QUIT\r\n");

    // Close the socket
    close(sockfd);
    return 0;
}