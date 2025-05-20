//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAX_LINE 1024
#define SMTP_PORT 25
#define SMTP_SERVER "smtp.gmail.com"

int main() {
    int sockfd, n;
    struct sockaddr_in serveraddr;
    char sendline[MAX_LINE];
    char recvline[MAX_LINE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(SMTP_PORT);
    inet_pton(AF_INET, SMTP_SERVER, &serveraddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("connected to %s:%d\n", SMTP_SERVER, SMTP_PORT);

    while (1) {
        printf("enter command: ");
        fgets(sendline, MAX_LINE, stdin);
        n = strlen(sendline);
        if (sendline[n - 1] == '\n') {
            sendline[n - 1] = '\0';
        }
        send(sockfd, sendline, n, 0);
        memset(recvline, 0, sizeof(recvline));
        n = recv(sockfd, recvline, MAX_LINE, 0);
        if (n <= 0) {
            perror("recv failed");
            exit(EXIT_FAILURE);
        }
        printf("response: %s", recvline);
    }

    close(sockfd);
    return 0;
}