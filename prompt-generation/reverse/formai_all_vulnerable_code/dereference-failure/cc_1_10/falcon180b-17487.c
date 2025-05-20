//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 110
#define MAXLINE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char sendline[MAXLINE];
    char recvline[MAXLINE];

    if (argc!= 4) {
        printf("Usage:./client <server_ip> <username> <password>\n");
        exit(0);
    }

    strcpy(sendline, "USER ");
    strcat(sendline, argv[2]);
    sendline[strlen(sendline)] = '\r';
    sendline[strlen(sendline)] = '\n';

    strcpy(sendline, "PASS ");
    strcat(sendline, argv[3]);
    sendline[strlen(sendline)] = '\r';
    sendline[strlen(sendline)] = '\n';

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("Connection failed\n");
        exit(0);
    }

    while (fgets(recvline, MAXLINE, stdin)!= NULL) {
        send(sockfd, recvline, strlen(recvline), 0);
    }

    close(sockfd);

    return 0;
}