//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE 1024
#define POP3_PORT 110

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char sendline[MAX_LINE];
    char recvline[MAX_LINE];

    if (argc!= 4) {
        printf("Usage:./client <server_ip> <username> <password>\n");
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);
    serv_addr.sin_port = htons(POP3_PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(0);
    }

    sprintf(sendline, "USER %s\r\n", argv[2]);
    send(sockfd, sendline, strlen(sendline), 0);

    n = recv(sockfd, recvline, MAX_LINE, 0);
    recvline[n] = '\0';
    printf("Received: %s", recvline);

    sprintf(sendline, "PASS %s\r\n", argv[3]);
    send(sockfd, sendline, strlen(sendline), 0);

    n = recv(sockfd, recvline, MAX_LINE, 0);
    recvline[n] = '\0';
    printf("Received: %s", recvline);

    close(sockfd);
    return 0;
}