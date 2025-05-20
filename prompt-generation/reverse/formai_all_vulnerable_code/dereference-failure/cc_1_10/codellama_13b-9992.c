//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: beginner-friendly
/*
 * SMTP Client Example Program
 *
 * This program demonstrates how to send an email using the Simple Mail Transfer Protocol (SMTP).
 * It uses the `sendmail()` function to send the email to a specified recipient.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define SMTP_PORT 25
#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    // Check the number of command-line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <recipient> <message>\n", argv[0]);
        exit(1);
    }

    // Get the recipient and message from the command-line arguments
    char *recipient = argv[1];
    char *message = argv[2];

    // Create a socket for communication with the SMTP server
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        exit(1);
    }

    // Connect to the SMTP server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr("smtp.example.com");
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect() failed");
        exit(1);
    }

    // Send the HELO command to the SMTP server
    char buf[BUFSIZE];
    snprintf(buf, BUFSIZE, "HELO %s\r\n", "example.com");
    send(sock, buf, strlen(buf), 0);

    // Send the MAIL FROM command to the SMTP server
    snprintf(buf, BUFSIZE, "MAIL FROM:<%s>\r\n", "sender@example.com");
    send(sock, buf, strlen(buf), 0);

    // Send the RCPT TO command to the SMTP server
    snprintf(buf, BUFSIZE, "RCPT TO:<%s>\r\n", recipient);
    send(sock, buf, strlen(buf), 0);

    // Send the DATA command to the SMTP server
    snprintf(buf, BUFSIZE, "DATA\r\n");
    send(sock, buf, strlen(buf), 0);

    // Send the message to the SMTP server
    send(sock, message, strlen(message), 0);

    // Send the terminating dot to the SMTP server
    snprintf(buf, BUFSIZE, ".\r\n");
    send(sock, buf, strlen(buf), 0);

    // Send the QUIT command to the SMTP server
    snprintf(buf, BUFSIZE, "QUIT\r\n");
    send(sock, buf, strlen(buf), 0);

    // Close the socket
    close(sock);

    return 0;
}