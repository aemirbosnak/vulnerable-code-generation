//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_CHARACTERS 1024
#define SMTP_PORT 25

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char buffer[MAX_CHARACTERS], message[MAX_CHARACTERS];
    struct hostent *host;

    if (argc < 3) {
        printf("Usage: %s hostname message\n", argv[0]);
        return 1;
    }

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Could not create socket\n");
        return 1;
    }

    // Resolve hostname to IP address
    if ((host = gethostbyname(argv[1])) == NULL) {
        printf("Could not resolve hostname\n");
        return 1;
    }

    // Set server details
    server.sin_addr.s_addr = *((unsigned long*) host->h_addr);
    server.sin_family = AF_INET;
    server.sin_port = htons(SMTP_PORT);

    // Connect to SMTP server
    if (connect(sock, (struct sockaddr*) &server, sizeof(server)) < 0) {
        printf("Could not connect to SMTP server\n");
        return 1;
    }

    // Receive initial message from server
    if (recv(sock, buffer, MAX_CHARACTERS, 0) < 0) {
        printf("Error while receiving initial message from server\n");
        return 1;
    }

    printf("%s\n", buffer);

    // Send 'EHLO' message to server
    snprintf(message, sizeof(message), "EHLO %s\r\n", argv[1]);
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("Error while sending EHLO message\n");
        return 1;
    }

    // Receive response from server
    if (recv(sock, buffer, MAX_CHARACTERS, 0) < 0) {
        printf("Error while receiving response from server\n");
        return 1;
    }

    printf("%s\n", buffer);

    // Send 'MAIL FROM' message
    snprintf(message, sizeof(message), "MAIL FROM:<%s>\r\n", "sender@example.com");
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("Error while sending MAIL FROM message\n");
        return 1;
    }

    // Receive response from server
    if (recv(sock, buffer, MAX_CHARACTERS, 0) < 0) {
        printf("Error while receiving response from server\n");
        return 1;
    }

    printf("%s\n", buffer);

    // Send 'RCPT TO' message
    snprintf(message, sizeof(message), "RCPT TO:<%s>\r\n", argv[2]);
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("Error while sending RCPT TO message\n");
        return 1;
    }

    // Receive response from server
    if (recv(sock, buffer, MAX_CHARACTERS, 0) < 0) {
        printf("Error while receiving response from server\n");
        return 1;
    }

    printf("%s\n", buffer);

    // Send 'DATA' message
    snprintf(message, sizeof(message), "DATA\r\n");
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("Error while sending DATA message\n");
        return 1;
    }

    // Receive response from server
    if (recv(sock, buffer, MAX_CHARACTERS, 0) < 0) {
        printf("Error while receiving response from server\n");
        return 1;
    }

    printf("%s\n", buffer);

    // Send message body
    snprintf(message, sizeof(message), "Subject: SMTP Client Example\r\n\r\nHello World!\r\n.\r\n");
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("Error while sending message body\n");
        return 1;
    }

    // Receive response from server
    if (recv(sock, buffer, MAX_CHARACTERS, 0) < 0) {
        printf("Error while receiving response from server\n");
        return 1;
    }

    printf("%s\n", buffer);

    // Send 'QUIT' message
    snprintf(message, sizeof(message), "QUIT\r\n");
    if (send(sock, message, strlen(message), 0) < 0) {
        printf("Error while sending QUIT message\n");
        return 1;
    }

    // Receive response from server
    if (recv(sock, buffer, MAX_CHARACTERS, 0) < 0) {
        printf("Error while receiving response from server\n");
        return 1;
    }

    printf("%s\n", buffer);

    // Close socket
    close(sock);

    return 0;
}