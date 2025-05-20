//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: artistic
// Behold! Here is a masterpiece SMTP client code!
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define MAXLINE 1024

int main(int argc, char **argv)
{
    int sockfd, n;
    struct sockaddr_in servaddr;
    char sendline[MAXLINE], recvline[MAXLINE];
    
    if (argc != 2) {
        fprintf(stderr, "usage: %s <IP address>\n", argv[0]);
        exit(1);
    }
    
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket error");
        exit(1);
    }
    
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(25);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        fprintf(stderr, "inet_pton error for %s\n", argv[1]);
        exit(1);
    }
    
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect error");
        exit(1);
    }
    
    n = recv(sockfd, recvline, MAXLINE, 0);
    recvline[n] = 0;
    printf("%s", recvline);
    printf("HELO\n");
    sprintf(sendline, "HELO\r\n");
    send(sockfd, sendline, strlen(sendline), 0);
    n = recv(sockfd, recvline, MAXLINE, 0);
    recvline[n] = 0;
    printf("%s", recvline);
    printf("MAIL FROM: <example@domain.com>\n");
    sprintf(sendline, "MAIL FROM: <example@domain.com>\r\n");
    send(sockfd, sendline, strlen(sendline), 0);
    n = recv(sockfd, recvline, MAXLINE, 0);
    recvline[n] = 0;
    printf("%s", recvline);
    printf("RCPT TO: <recipient@domain.com>\n");
    sprintf(sendline, "RCPT TO: <recipient@domain.com>\r\n");
    send(sockfd, sendline, strlen(sendline), 0);
    n = recv(sockfd, recvline, MAXLINE, 0);
    recvline[n] = 0;
    printf("%s", recvline);
    printf("DATA\n");
    sprintf(sendline, "DATA\r\n");
    send(sockfd, sendline, strlen(sendline), 0);
    n = recv(sockfd, recvline, MAXLINE, 0);
    recvline[n] = 0;
    printf("%s", recvline);
    
    printf("From: example@domain.com\n");
    printf("To: recipient@domain.com\n");
    printf("Subject: Test email\n");
    printf("\n");
    printf("This is a test email from my SMTP client code!\n");
    printf("\n");
    
    sprintf(sendline, "From: example@domain.com\r\n");
    send(sockfd, sendline, strlen(sendline), 0);
    sprintf(sendline, "To: recipient@domain.com\r\n");
    send(sockfd, sendline, strlen(sendline), 0);
    sprintf(sendline, "Subject: Test email\r\n");
    send(sockfd, sendline, strlen(sendline), 0);
    sprintf(sendline, "\r\n");
    send(sockfd, sendline, strlen(sendline), 0);
    sprintf(sendline, "This is a test email from my SMTP client code!\r\n");
    send(sockfd, sendline, strlen(sendline), 0);
    sprintf(sendline, ".\r\n");
    send(sockfd, sendline, strlen(sendline), 0);
    n = recv(sockfd, recvline, MAXLINE, 0);
    recvline[n] = 0;
    printf("%s", recvline);
    printf("QUIT\n");
    sprintf(sendline, "QUIT\r\n");
    send(sockfd, sendline, strlen(sendline), 0);
    n = recv(sockfd, recvline, MAXLINE, 0);
    recvline[n] = 0;
    printf("%s", recvline);
    close(sockfd);
    exit(0);
}