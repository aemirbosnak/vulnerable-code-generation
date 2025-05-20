//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: visionary
/*
 * SMTP Client Example Program
 *
 * This program demonstrates how to build a simple SMTP client in C
 * that can send an email to a recipient using the SMTP protocol.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERVER "smtp.example.com"
#define PORT 25

int main(int argc, char **argv) {
    int sockfd, n;
    char sendbuf[1024], recvbuf[1024];
    struct sockaddr_in servaddr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set up the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, SERVER, &servaddr.sin_addr) <= 0) {
        perror("ERROR setting up server address");
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("ERROR connecting to server");
        exit(1);
    }

    // Send the HELO command
    sprintf(sendbuf, "HELO %s\r\n", argv[1]);
    n = send(sockfd, sendbuf, strlen(sendbuf), 0);
    if (n < 0) {
        perror("ERROR sending HELO command");
        exit(1);
    }

    // Send the MAIL FROM command
    sprintf(sendbuf, "MAIL FROM:<%s>\r\n", argv[2]);
    n = send(sockfd, sendbuf, strlen(sendbuf), 0);
    if (n < 0) {
        perror("ERROR sending MAIL FROM command");
        exit(1);
    }

    // Send the RCPT TO command
    sprintf(sendbuf, "RCPT TO:<%s>\r\n", argv[3]);
    n = send(sockfd, sendbuf, strlen(sendbuf), 0);
    if (n < 0) {
        perror("ERROR sending RCPT TO command");
        exit(1);
    }

    // Send the DATA command
    sprintf(sendbuf, "DATA\r\n");
    n = send(sockfd, sendbuf, strlen(sendbuf), 0);
    if (n < 0) {
        perror("ERROR sending DATA command");
        exit(1);
    }

    // Send the message
    sprintf(sendbuf, "%s\r\n.\r\n", argv[4]);
    n = send(sockfd, sendbuf, strlen(sendbuf), 0);
    if (n < 0) {
        perror("ERROR sending message");
        exit(1);
    }

    // Send the QUIT command
    sprintf(sendbuf, "QUIT\r\n");
    n = send(sockfd, sendbuf, strlen(sendbuf), 0);
    if (n < 0) {
        perror("ERROR sending QUIT command");
        exit(1);
    }

    // Close the socket
    close(sockfd);

    return 0;
}