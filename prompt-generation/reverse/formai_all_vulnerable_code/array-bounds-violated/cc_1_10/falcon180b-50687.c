//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_LINE 1024
#define POP3_PORT 110


int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char sendline[MAX_LINE], recvline[MAX_LINE];
    char *user = "your_username";
    char *pass = "your_password";

    if (argc!= 3) {
        printf("Usage: %s <server_ip> <port>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        return 1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        return 1;
    }

    printf("Connected to %s:%d\n", argv[1], POP3_PORT);

    send(sockfd, "USER ", strlen("USER "), 0);
    send(sockfd, user, strlen(user), 0);
    send(sockfd, "\r\n", strlen("\r\n"), 0);

    send(sockfd, "PASS ", strlen("PASS "), 0);
    send(sockfd, pass, strlen(pass), 0);
    send(sockfd, "\r\n", strlen("\r\n"), 0);

    while ((n = recv(sockfd, recvline, MAX_LINE, 0)) > 0) {
        recvline[n] = '\0';
        printf("%s", recvline);
    }

    close(sockfd);
    return 0;
}