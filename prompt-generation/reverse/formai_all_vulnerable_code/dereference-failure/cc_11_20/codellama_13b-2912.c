//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: romantic
/*
 * Building a SMTP Client in C
 *
 * This program is an example of a SMTP client written in C.
 * It sends an email to a SMTP server and then exits.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 25 // default port for SMTP

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <server> <from> <to> <message>\n", argv[0]);
        return 1;
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Set up the server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send the HELO command
    char helo_cmd[256];
    snprintf(helo_cmd, sizeof(helo_cmd), "HELO %s\r\n", argv[1]);
    if (send(sock, helo_cmd, strlen(helo_cmd), 0) < 0) {
        perror("send");
        return 1;
    }

    // Send the MAIL FROM command
    char mail_from_cmd[256];
    snprintf(mail_from_cmd, sizeof(mail_from_cmd), "MAIL FROM:<%s>\r\n", argv[2]);
    if (send(sock, mail_from_cmd, strlen(mail_from_cmd), 0) < 0) {
        perror("send");
        return 1;
    }

    // Send the RCPT TO command
    char rcpt_to_cmd[256];
    snprintf(rcpt_to_cmd, sizeof(rcpt_to_cmd), "RCPT TO:<%s>\r\n", argv[3]);
    if (send(sock, rcpt_to_cmd, strlen(rcpt_to_cmd), 0) < 0) {
        perror("send");
        return 1;
    }

    // Send the DATA command
    char data_cmd[256];
    snprintf(data_cmd, sizeof(data_cmd), "DATA\r\n");
    if (send(sock, data_cmd, strlen(data_cmd), 0) < 0) {
        perror("send");
        return 1;
    }

    // Send the email message
    char msg[1024];
    snprintf(msg, sizeof(msg), "%s", argv[4]);
    if (send(sock, msg, strlen(msg), 0) < 0) {
        perror("send");
        return 1;
    }

    // Send the final dot
    char dot_cmd[256];
    snprintf(dot_cmd, sizeof(dot_cmd), ".\r\n");
    if (send(sock, dot_cmd, strlen(dot_cmd), 0) < 0) {
        perror("send");
        return 1;
    }

    // Close the socket
    close(sock);

    return 0;
}