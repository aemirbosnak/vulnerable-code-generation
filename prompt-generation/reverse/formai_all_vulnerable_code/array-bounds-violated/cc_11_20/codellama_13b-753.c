//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: excited
/*
 * Building a SMTP Client example program in a excited style!
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#define SMTP_PORT 25

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <server> <email_address>\n", argv[0]);
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
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send the EHLO command
    char *cmd = "EHLO\r\n";
    if (send(sock, cmd, strlen(cmd), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive the server response
    char buf[256];
    int n = recv(sock, buf, sizeof(buf), 0);
    if (n < 0) {
        perror("recv");
        return 1;
    }

    // Parse the server response
    buf[n] = '\0';
    char *response = strtok(buf, " ");
    if (strcmp(response, "220") != 0) {
        printf("Server response was not 220\n");
        return 1;
    }

    // Send the MAIL FROM command
    cmd = "MAIL FROM:<user@example.com>\r\n";
    if (send(sock, cmd, strlen(cmd), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive the server response
    n = recv(sock, buf, sizeof(buf), 0);
    if (n < 0) {
        perror("recv");
        return 1;
    }

    // Parse the server response
    buf[n] = '\0';
    response = strtok(buf, " ");
    if (strcmp(response, "250") != 0) {
        printf("Server response was not 250\n");
        return 1;
    }

    // Send the RCPT TO command
    cmd = "RCPT TO:<user@example.com>\r\n";
    if (send(sock, cmd, strlen(cmd), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive the server response
    n = recv(sock, buf, sizeof(buf), 0);
    if (n < 0) {
        perror("recv");
        return 1;
    }

    // Parse the server response
    buf[n] = '\0';
    response = strtok(buf, " ");
    if (strcmp(response, "250") != 0) {
        printf("Server response was not 250\n");
        return 1;
    }

    // Send the DATA command
    cmd = "DATA\r\n";
    if (send(sock, cmd, strlen(cmd), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive the server response
    n = recv(sock, buf, sizeof(buf), 0);
    if (n < 0) {
        perror("recv");
        return 1;
    }

    // Parse the server response
    buf[n] = '\0';
    response = strtok(buf, " ");
    if (strcmp(response, "354") != 0) {
        printf("Server response was not 354\n");
        return 1;
    }

    // Send the message
    char *message = "Subject: Hello!\r\n\r\nHello, World!\r\n.\r\n";
    if (send(sock, message, strlen(message), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive the server response
    n = recv(sock, buf, sizeof(buf), 0);
    if (n < 0) {
        perror("recv");
        return 1;
    }

    // Parse the server response
    buf[n] = '\0';
    response = strtok(buf, " ");
    if (strcmp(response, "250") != 0) {
        printf("Server response was not 250\n");
        return 1;
    }

    // Close the socket
    close(sock);

    return 0;
}