//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE 512
#define SMTP_PORT 25

int main(int argc, char *argv[])
{
    int sockfd, n;
    struct sockaddr_in servaddr;
    char sendline[MAX_LINE], recvline[MAX_LINE];

    if (argc != 4)
    {
        fprintf(stderr, "usage: %s <smtp_server> <sender_email> <receiver_email>\n", argv[0]);
        exit(1);
    }

    // create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket");
        exit(1);
    }

    // get the server address
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL)
    {
        fprintf(stderr, "gethostbyname: %s\n", hstrerror(h_errno));
        exit(1);
    }

    // set the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SMTP_PORT);
    memcpy(&servaddr.sin_addr, host->h_addr, host->h_length);

    // connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("connect");
        exit(1);
    }

    // receive the greeting message from the server
    memset(recvline, 0, MAX_LINE);
    if (read(sockfd, recvline, MAX_LINE) < 0)
    {
        perror("read");
        exit(1);
    }

    printf("Received: %s", recvline);

    // send the HELO command
    snprintf(sendline, MAX_LINE, "HELO smtp.example.com\r\n");
    if (write(sockfd, sendline, strlen(sendline)) < 0)
    {
        perror("write");
        exit(1);
    }

    // receive the response from the server
    memset(recvline, 0, MAX_LINE);
    if (read(sockfd, recvline, MAX_LINE) < 0)
    {
        perror("read");
        exit(1);
    }

    printf("Received: %s", recvline);

    // send the MAIL FROM command
    snprintf(sendline, MAX_LINE, "MAIL FROM: %s\r\n", argv[2]);
    if (write(sockfd, sendline, strlen(sendline)) < 0)
    {
        perror("write");
        exit(1);
    }

    // receive the response from the server
    memset(recvline, 0, MAX_LINE);
    if (read(sockfd, recvline, MAX_LINE) < 0)
    {
        perror("read");
        exit(1);
    }

    printf("Received: %s", recvline);

    // send the RCPT TO command
    snprintf(sendline, MAX_LINE, "RCPT TO: %s\r\n", argv[3]);
    if (write(sockfd, sendline, strlen(sendline)) < 0)
    {
        perror("write");
        exit(1);
    }

    // receive the response from the server
    memset(recvline, 0, MAX_LINE);
    if (read(sockfd, recvline, MAX_LINE) < 0)
    {
        perror("read");
        exit(1);
    }

    printf("Received: %s", recvline);

    // send the DATA command
    snprintf(sendline, MAX_LINE, "DATA\r\n");
    if (write(sockfd, sendline, strlen(sendline)) < 0)
    {
        perror("write");
        exit(1);
    }

    // receive the response from the server
    memset(recvline, 0, MAX_LINE);
    if (read(sockfd, recvline, MAX_LINE) < 0)
    {
        perror("read");
        exit(1);
    }

    printf("Received: %s", recvline);

    // send the email body
    snprintf(sendline, MAX_LINE, "Subject: This is a test email\r\n\r\nThis is the body of the email.\r\n.\r\n");
    if (write(sockfd, sendline, strlen(sendline)) < 0)
    {
        perror("write");
        exit(1);
    }

    // receive the response from the server
    memset(recvline, 0, MAX_LINE);
    if (read(sockfd, recvline, MAX_LINE) < 0)
    {
        perror("read");
        exit(1);
    }

    printf("Received: %s", recvline);

    // send the QUIT command
    snprintf(sendline, MAX_LINE, "QUIT\r\n");
    if (write(sockfd, sendline, strlen(sendline)) < 0)
    {
        perror("write");
        exit(1);
    }

    // receive the response from the server
    memset(recvline, 0, MAX_LINE);
    if (read(sockfd, recvline, MAX_LINE) < 0)
    {
        perror("read");
        exit(1);
    }

    printf("Received: %s", recvline);

    // close the socket
    close(sockfd);

    return 0;
}