//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 1024

int main(int argc, char *argv[])
{
    int sockfd, n;
    char sendline[MAXLINE], recvline[MAXLINE];
    struct sockaddr_in servaddr;

    if (argc != 3) {
        fprintf(stderr, "usage: %s <host IP address> <message>\n", argv[0]);
        exit(1);
    }

    // Create a socket for sending data
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Specify the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(25); // SMTP port

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect error");
        exit(1);
    }

    // Receive the server's greeting
    n = recv(sockfd, recvline, MAXLINE, 0);
    if (n < 0) {
        perror("recv error");
        exit(1);
    }
    printf("Server: %s\n", recvline);

    // Send the HELO command
    strcpy(sendline, "HELO Watson\r\n");
    n = send(sockfd, sendline, strlen(sendline), 0);
    if (n < 0) {
        perror("send error");
        exit(1);
    }

    // Receive the server's response
    n = recv(sockfd, recvline, MAXLINE, 0);
    if (n < 0) {
        perror("recv error");
        exit(1);
    }
    printf("Server: %s\n", recvline);

    // Send the MAIL FROM command
    strcpy(sendline, "MAIL FROM: <sherlock@bakerstreet.net>\r\n");
    n = send(sockfd, sendline, strlen(sendline), 0);
    if (n < 0) {
        perror("send error");
        exit(1);
    }

    // Receive the server's response
    n = recv(sockfd, recvline, MAXLINE, 0);
    if (n < 0) {
        perror("recv error");
        exit(1);
    }
    printf("Server: %s\n", recvline);

    // Send the RCPT TO command
    strcpy(sendline, "RCPT TO: <john@watson.net>\r\n");
    n = send(sockfd, sendline, strlen(sendline), 0);
    if (n < 0) {
        perror("send error");
        exit(1);
    }

    // Receive the server's response
    n = recv(sockfd, recvline, MAXLINE, 0);
    if (n < 0) {
        perror("recv error");
        exit(1);
    }
    printf("Server: %s\n", recvline);

    // Send the DATA command
    strcpy(sendline, "DATA\r\n");
    n = send(sockfd, sendline, strlen(sendline), 0);
    if (n < 0) {
        perror("send error");
        exit(1);
    }

    // Receive the server's response
    n = recv(sockfd, recvline, MAXLINE, 0);
    if (n < 0) {
        perror("recv error");
        exit(1);
    }
    printf("Server: %s\n", recvline);

    // Send the message body
    strcpy(sendline, argv[2]);
    strcat(sendline, "\r\n.\r\n");
    n = send(sockfd, sendline, strlen(sendline), 0);
    if (n < 0) {
        perror("send error");
        exit(1);
    }

    // Receive the server's response
    n = recv(sockfd, recvline, MAXLINE, 0);
    if (n < 0) {
        perror("recv error");
        exit(1);
    }
    printf("Server: %s\n", recvline);

    // Send the QUIT command
    strcpy(sendline, "QUIT\r\n");
    n = send(sockfd, sendline, strlen(sendline), 0);
    if (n < 0) {
        perror("send error");
        exit(1);
    }

    // Close the socket
    close(sockfd);

    return 0;
}