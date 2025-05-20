//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE 1024
#define PORT 25

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char sendline[MAX_LINE];
    char recvline[MAX_LINE];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr("smtp.gmail.com");

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Send HELO command
    sprintf(sendline, "HELO %s\r\n", argv[0]);
    send(sockfd, sendline, strlen(sendline), 0);

    // Send MAIL FROM command
    sprintf(sendline, "MAIL FROM:<%s>\r\n", argv[0]);
    send(sockfd, sendline, strlen(sendline), 0);

    // Send RCPT TO command
    sprintf(sendline, "RCPT TO:<%s>\r\n", argv[1]);
    send(sockfd, sendline, strlen(sendline), 0);

    // Send DATA command
    sprintf(sendline, "DATA\r\n");
    send(sockfd, sendline, strlen(sendline), 0);

    // Send message body
    sprintf(sendline, "Subject: Test Message\r\n\r\nHello, this is a test message.\r\n");
    send(sockfd, sendline, strlen(sendline), 0);

    // Send QUIT command
    sprintf(sendline, "QUIT\r\n");
    send(sockfd, sendline, strlen(sendline), 0);

    // Read server response
    bzero(recvline, sizeof(recvline));
    bzero(sendline, sizeof(sendline));
    while ((n = recv(sockfd, recvline, MAX_LINE, 0)) > 0) {
        recvline[n] = '\0';
        printf("%s", recvline);
        bzero(recvline, sizeof(recvline));
    }

    close(sockfd);
    return 0;
}