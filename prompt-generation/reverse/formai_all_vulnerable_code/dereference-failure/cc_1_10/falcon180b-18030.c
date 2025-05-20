//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE 1024

void die(const char *s) {
    perror(s);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char sendline[MAX_LINE];
    char recvline[MAX_LINE];

    if (argc < 4) {
        printf("Usage: %s <SMTP server> <sender> <recipient>\n", argv[0]);
        return 1;
    }

    portno = atoi(argv[1]);
    strcpy(sendline, "MAIL FROM:<");
    strcat(sendline, argv[2]);
    strcat(sendline, ">\r\n");

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
        die("socket failed");

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        die("connect failed");

    send(sockfd, sendline, strlen(sendline), 0);
    recv(sockfd, recvline, MAX_LINE, 0);

    if (recvline[0]!= '2') {
        printf("MAIL FROM command failed\n");
        return 1;
    }

    strcpy(sendline, "RCPT TO:<");
    strcat(sendline, argv[3]);
    strcat(sendline, ">\r\n");

    send(sockfd, sendline, strlen(sendline), 0);
    recv(sockfd, recvline, MAX_LINE, 0);

    if (recvline[0]!= '2') {
        printf("RCPT TO command failed\n");
        return 1;
    }

    strcpy(sendline, "DATA\r\n");
    send(sockfd, sendline, strlen(sendline), 0);
    recv(sockfd, recvline, MAX_LINE, 0);

    if (recvline[0]!= '3') {
        printf("DATA command failed\n");
        return 1;
    }

    strcpy(sendline, "Subject: Hello World\r\n\r\nHello, world!\r\n.\r\n");
    send(sockfd, sendline, strlen(sendline), 0);

    send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0);

    close(sockfd);
    return 0;
}