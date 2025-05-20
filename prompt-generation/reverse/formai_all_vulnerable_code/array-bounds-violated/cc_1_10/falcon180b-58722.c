//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define PORT 25
#define MAXLINE 1024
#define TRUE 1
#define FALSE 0
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serveraddr;
    char sendline[MAXLINE];
    char recvline[MAXLINE];
    int n;
    time_t t;
    int ret = FALSE;

    // set up server address
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "localhost", &serveraddr.sin_addr) <= 0) {
        printf("inet_pton error occured\n");
        return -1;
    }

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("socket error occured\n");
        return -1;
    }

    // connect to server
    ret = connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    if (ret < 0) {
        printf("connect error occured\n");
        return -1;
    }

    // send HELO command
    sprintf(sendline, "HELO %s\r\n", "localhost");
    send(sockfd, sendline, strlen(sendline), 0);

    // send MAIL FROM command
    sprintf(sendline, "MAIL FROM: <test@localhost>\r\n");
    send(sockfd, sendline, strlen(sendline), 0);

    // send RCPT TO command
    sprintf(sendline, "RCPT TO: <test@localhost>\r\n");
    send(sockfd, sendline, strlen(sendline), 0);

    // send DATA command
    sprintf(sendline, "DATA\r\n");
    send(sockfd, sendline, strlen(sendline), 0);

    // send message body
    sprintf(sendline, "Subject: Test Message\r\n\r\nHello World!\r\n");
    send(sockfd, sendline, strlen(sendline), 0);

    // send QUIT command
    sprintf(sendline, "QUIT\r\n");
    send(sockfd, sendline, strlen(sendline), 0);

    // receive response
    n = recv(sockfd, recvline, BUF_SIZE, 0);
    recvline[n] = '\0';
    printf("Received response: %s", recvline);

    // close socket
    close(sockfd);

    return 0;
}