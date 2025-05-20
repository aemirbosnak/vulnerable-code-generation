//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char sendline[MAX_LINE];
    char recvline[MAX_LINE];

    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <host> <user> <password>\n", argv[0]);
        exit(1);
    }

    strcpy(sendline, "LOGIN ");
    strcat(sendline, argv[2]);
    strcat(sendline, " ");
    strcat(sendline, argv[3]);
    strcat(sendline, "\r\n");

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(143);
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    send(sockfd, sendline, strlen(sendline), 0);

    while (1) {
        n = recv(sockfd, recvline, MAX_LINE, 0);
        if (n <= 0) {
            break;
        }
        recvline[n - 1] = '\0';
        printf("%s", recvline);
    }

    close(sockfd);
    return 0;
}