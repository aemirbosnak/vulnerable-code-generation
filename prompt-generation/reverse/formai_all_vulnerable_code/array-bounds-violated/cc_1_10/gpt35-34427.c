//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAXLEN 1024

int main(int argc, char *argv[])
{
    int sockfd, n;
    struct sockaddr_in servaddr;
    char sendline[MAXLEN], recvline[MAXLEN];

    if (argc != 3)
    {
        printf("usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Error: Could not create socket.\n");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
    {
        printf("Error: Invalid IP address.\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        printf("Error: Connection failed.\n");
        exit(1);
    }

    n = recv(sockfd, recvline, MAXLEN, 0);
    recvline[n] = '\0';
    printf("Server response: %s\n", recvline);

    // Establishing connection to SMTP server
    sprintf(sendline, "HELO SMTP Client\r\n");
    send(sockfd, sendline, strlen(sendline), 0);
    n = recv(sockfd, recvline, MAXLEN, 0);
    recvline[n] = '\0';
    printf("Server response: %s\n", recvline);

    // Sending sender address to SMTP server
    sprintf(sendline, "MAIL FROM: <%s>\r\n", "sender@domain.com");
    send(sockfd, sendline, strlen(sendline), 0);
    n = recv(sockfd, recvline, MAXLEN, 0);
    recvline[n] = '\0';
    printf("Server response: %s\n", recvline);

    // Sending recipient address to SMTP server
    sprintf(sendline, "RCPT TO: <%s>\r\n", "recipient@domain.com");
    send(sockfd, sendline, strlen(sendline), 0);
    n = recv(sockfd, recvline, MAXLEN, 0);
    recvline[n] = '\0';
    printf("Server response: %s\n", recvline);

    // Sending message data to SMTP server
    sprintf(sendline, "DATA\r\n");
    send(sockfd, sendline, strlen(sendline), 0);
    n = recv(sockfd, recvline, MAXLEN, 0);
    recvline[n] = '\0';
    printf("Server response: %s\n", recvline);

    sprintf(sendline, "Subject: SMTP Client Test\r\n");
    send(sockfd, sendline, strlen(sendline), 0);

    sprintf(sendline, "From: sender@domain.com\r\n");
    send(sockfd, sendline, strlen(sendline), 0);

    sprintf(sendline, "To: recipient@domain.com\r\n");
    send(sockfd, sendline, strlen(sendline), 0);

    sprintf(sendline, "\r\nTest message sent by SMTP client program.\r\n.\r\n");
    send(sockfd, sendline, strlen(sendline), 0);
    n = recv(sockfd, recvline, MAXLEN, 0);
    recvline[n] = '\0';
    printf("Server response: %s\n", recvline);

    // Closing the connection with SMTP server
    sprintf(sendline, "QUIT\r\n");
    send(sockfd, sendline, strlen(sendline), 0);
    n = recv(sockfd, recvline, MAXLEN, 0);
    recvline[n] = '\0';
    printf("Server response: %s\n", recvline);

    close(sockfd);
    exit(0);
}