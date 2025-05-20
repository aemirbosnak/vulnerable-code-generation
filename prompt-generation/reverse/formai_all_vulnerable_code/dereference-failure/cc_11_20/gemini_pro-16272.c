//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SMTP_PORT 25

int main()
{
    // Step 1: Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    // Step 2: Set up the server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Step 3: Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Step 4: Send the HELO command
    char buffer[256];
    sprintf(buffer, "HELO localhost\r\n");
    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Step 5: Receive the response from the server
    memset(buffer, 0, sizeof(buffer));
    if (recv(sock, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        exit(1);
    }

    // Step 6: Send the MAIL FROM command
    sprintf(buffer, "MAIL FROM: <sender@localhost>\r\n");
    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Step 7: Receive the response from the server
    memset(buffer, 0, sizeof(buffer));
    if (recv(sock, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        exit(1);
    }

    // Step 8: Send the RCPT TO command
    sprintf(buffer, "RCPT TO: <recipient@localhost>\r\n");
    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Step 9: Receive the response from the server
    memset(buffer, 0, sizeof(buffer));
    if (recv(sock, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        exit(1);
    }

    // Step 10: Send the DATA command
    sprintf(buffer, "DATA\r\n");
    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Step 11: Receive the response from the server
    memset(buffer, 0, sizeof(buffer));
    if (recv(sock, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        exit(1);
    }

    // Step 12: Send the message body
    const char *message = "Hello world!\r\n";
    if (send(sock, message, strlen(message), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Step 13: Send the dot (.) to indicate the end of the message
    sprintf(buffer, ".\r\n");
    if (send(sock, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Step 14: Receive the response from the server
    memset(buffer, 0, sizeof(buffer));
    if (recv(sock, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        exit(1);
    }

    // Step 15: Close the connection
    close(sock);

    return 0;
}