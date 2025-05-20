//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: irregular
/*
 * Building a SMTP Client
 *
 * A simple SMTP client written in C
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>

#define MAX_LINE 1024
#define MAX_COMMAND 256

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char buffer[MAX_LINE];
    char command[MAX_COMMAND];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Set up server address
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server.sin_addr);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        return 1;
    }

    // Send initial message
    strcpy(command, "HELO ");
    strcat(command, argv[1]);
    strcat(command, "\r\n");
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("send");
        return 1;
    }

    // Read server response
    if (recv(sock, buffer, MAX_LINE, 0) < 0) {
        perror("recv");
        return 1;
    }
    printf("Received: %s", buffer);

    // Send second message
    strcpy(command, "MAIL FROM:<");
    strcat(command, argv[1]);
    strcat(command, ">\r\n");
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("send");
        return 1;
    }

    // Read server response
    if (recv(sock, buffer, MAX_LINE, 0) < 0) {
        perror("recv");
        return 1;
    }
    printf("Received: %s", buffer);

    // Send third message
    strcpy(command, "RCPT TO:<");
    strcat(command, argv[1]);
    strcat(command, ">\r\n");
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("send");
        return 1;
    }

    // Read server response
    if (recv(sock, buffer, MAX_LINE, 0) < 0) {
        perror("recv");
        return 1;
    }
    printf("Received: %s", buffer);

    // Send fourth message
    strcpy(command, "DATA\r\n");
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("send");
        return 1;
    }

    // Read server response
    if (recv(sock, buffer, MAX_LINE, 0) < 0) {
        perror("recv");
        return 1;
    }
    printf("Received: %s", buffer);

    // Send message data
    strcpy(command, "From: <");
    strcat(command, argv[1]);
    strcat(command, ">\r\n");
    strcat(command, "To: <");
    strcat(command, argv[1]);
    strcat(command, ">\r\n");
    strcat(command, "Subject: Hello\r\n");
    strcat(command, "Hello, world!\r\n");
    strcat(command, "\r\n.\r\n");
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("send");
        return 1;
    }

    // Read server response
    if (recv(sock, buffer, MAX_LINE, 0) < 0) {
        perror("recv");
        return 1;
    }
    printf("Received: %s", buffer);

    // Close socket
    close(sock);

    return 0;
}