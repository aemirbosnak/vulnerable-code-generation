//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: grateful
/*
 * Building a SMTP Client in C
 *
 * This program demonstrates how to build a simple SMTP client in C.
 * It sends an email to a specified recipient using the SMTP protocol.
 *
 * Usage: ./smtp_client <recipient_address> <subject> <message>
 *
 * Example: ./smtp_client user@example.com "Hello from C" "This is a test message"
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SMTP_PORT 25
#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Check command line arguments
    if (argc != 4) {
        printf("Usage: %s <recipient_address> <subject> <message>\n", argv[0]);
        return 1;
    }

    // Get recipient address, subject, and message
    char *recipient_address = argv[1];
    char *subject = argv[2];
    char *message = argv[3];

    // Create a socket for communicating with the SMTP server
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Resolve the SMTP server's address
    struct hostent *server = gethostbyname("smtp.example.com");
    if (server == NULL) {
        fprintf(stderr, "Could not resolve SMTP server address\n");
        return 1;
    }

    // Connect to the SMTP server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr = *((struct in_addr *)server->h_addr);
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send the HELO command
    char buffer[MAX_BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "HELO %s\r\n", inet_ntoa(server_addr.sin_addr));
    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        return 1;
    }

    // Send the MAIL FROM command
    snprintf(buffer, sizeof(buffer), "MAIL FROM:<%s>\r\n", "user@example.com");
    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        return 1;
    }

    // Send the RCPT TO command
    snprintf(buffer, sizeof(buffer), "RCPT TO:<%s>\r\n", recipient_address);
    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        return 1;
    }

    // Send the DATA command
    if (send(sock, "DATA\r\n", 5, 0) < 0) {
        perror("send");
        return 1;
    }

    // Send the email message
    snprintf(buffer, sizeof(buffer), "From: user@example.com\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.\r\n",
             recipient_address, subject, message);
    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        return 1;
    }

    // Send the QUIT command
    if (send(sock, "QUIT\r\n", 5, 0) < 0) {
        perror("send");
        return 1;
    }

    // Close the socket
    close(sock);

    return 0;
}