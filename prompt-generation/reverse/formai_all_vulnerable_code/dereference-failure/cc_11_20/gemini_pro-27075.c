//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <server> <port> <sender> <recipient>\n", argv[0]);
        return 1;
    }

    // Parse the command-line arguments
    const char *server = argv[1];
    int port = atoi(argv[2]);
    const char *sender = argv[3];
    const char *recipient = argv[4];

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, server, &server_addr.sin_addr.s_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send the EHLO command
    char buf[1024];
    snprintf(buf, sizeof(buf), "EHLO %s\r\n", server);
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive the EHLO response
    if (recv(sock, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return 1;
    }

    // Send the MAIL FROM command
    snprintf(buf, sizeof(buf), "MAIL FROM: <%s>\r\n", sender);
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive the MAIL FROM response
    if (recv(sock, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return 1;
    }

    // Send the RCPT TO command
    snprintf(buf, sizeof(buf), "RCPT TO: <%s>\r\n", recipient);
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive the RCPT TO response
    if (recv(sock, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return 1;
    }

    // Send the DATA command
    snprintf(buf, sizeof(buf), "DATA\r\n");
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive the DATA response
    if (recv(sock, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return 1;
    }

    // Send the email message
    snprintf(buf, sizeof(buf), "Subject: A Test Email\r\n\r\nThis is a test email.\r\n");
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    // Send the . command
    snprintf(buf, sizeof(buf), ".\r\n");
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive the QUIT response
    if (recv(sock, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return 1;
    }

    // Close the socket
    close(sock);

    return 0;
}