//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: enthusiastic
/*
 * A Simple SMTP Client Program in C
 *
 * This program sends an email using the SMTP protocol
 *
 * Usage:
 *   ./smtp_client <recipient_email> <subject> <message>
 *
 * Example:
 *   ./smtp_client user@example.com "Hello" "Hello World!"
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    // Check if the required arguments are provided
    if (argc != 4) {
        printf("Usage: ./smtp_client <recipient_email> <subject> <message>\n");
        return 1;
    }

    // Get the recipient email, subject, and message from the command line arguments
    char *recipient_email = argv[1];
    char *subject = argv[2];
    char *message = argv[3];

    // Create a socket for the SMTP protocol
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Connect to the SMTP server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(25);
    inet_pton(AF_INET, "smtp.example.com", &server_addr.sin_addr);
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send the HELO command to the server
    char *helo_msg = "HELO smtp.example.com\r\n";
    send(sock, helo_msg, strlen(helo_msg), 0);

    // Send the MAIL FROM command to the server
    char *mail_from_msg = "MAIL FROM:<user@example.com>\r\n";
    send(sock, mail_from_msg, strlen(mail_from_msg), 0);

    // Send the RCPT TO command to the server
    char *rcpt_to_msg = "RCPT TO:<";
    rcpt_to_msg = strcat(rcpt_to_msg, recipient_email);
    rcpt_to_msg = strcat(rcpt_to_msg, ">\r\n");
    send(sock, rcpt_to_msg, strlen(rcpt_to_msg), 0);

    // Send the DATA command to the server
    char *data_msg = "DATA\r\n";
    send(sock, data_msg, strlen(data_msg), 0);

    // Send the email message to the server
    char *msg = "Subject: ";
    msg = strcat(msg, subject);
    msg = strcat(msg, "\r\n\r\n");
    msg = strcat(msg, message);
    msg = strcat(msg, "\r\n.\r\n");
    send(sock, msg, strlen(msg), 0);

    // Send the QUIT command to the server
    char *quit_msg = "QUIT\r\n";
    send(sock, quit_msg, strlen(quit_msg), 0);

    // Close the socket
    close(sock);

    return 0;
}