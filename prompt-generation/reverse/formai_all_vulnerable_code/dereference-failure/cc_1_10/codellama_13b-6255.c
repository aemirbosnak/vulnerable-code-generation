//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: retro
/*
 * SMTP Client
 *
 * A simple SMTP client written in C using the BSD Sockets library.
 *
 * Compile with:
 *   gcc -o smtp_client smtp_client.c -lsocket
 *
 * Usage:
 *   ./smtp_client <host> <port> <from> <to> <subject> <message>
 *
 * Example:
 *   ./smtp_client smtp.gmail.com 587 john.doe@gmail.com jane.doe@gmail.com "Hello, Jane!" "Hi Jane, how are you?"
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 6) {
        fprintf(stderr, "Usage: %s <host> <port> <from> <to> <subject> <message>\n", argv[0]);
        return 1;
    }

    // Get command line arguments
    char *host = argv[1];
    int port = atoi(argv[2]);
    char *from = argv[3];
    char *to = argv[4];
    char *subject = argv[5];
    char *message = argv[6];

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Connect to server
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, host, &server.sin_addr);
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        return 1;
    }

    // Send EHLO command
    char buf[BUF_SIZE];
    snprintf(buf, BUF_SIZE, "EHLO %s\r\n", host);
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    // Send MAIL FROM command
    snprintf(buf, BUF_SIZE, "MAIL FROM: <%s>\r\n", from);
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    // Send RCPT TO command
    snprintf(buf, BUF_SIZE, "RCPT TO: <%s>\r\n", to);
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    // Send DATA command
    if (send(sock, "DATA\r\n", strlen("DATA\r\n"), 0) < 0) {
        perror("send");
        return 1;
    }

    // Send message
    snprintf(buf, BUF_SIZE, "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, message);
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    // Send QUIT command
    if (send(sock, "QUIT\r\n", strlen("QUIT\r\n"), 0) < 0) {
        perror("send");
        return 1;
    }

    // Close socket
    close(sock);

    return 0;
}