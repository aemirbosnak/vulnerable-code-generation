//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <time.h>

#define MAX_LINE 1024
#define SERVER "localhost"
#define PORT 25

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    char sendline[MAX_LINE];
    char recvline[MAX_LINE];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, SERVER, &serv_addr.sin_addr);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to %s:%d\n", SERVER, PORT);

    while (1) {
        printf("Enter message: ");
        fgets(sendline, MAX_LINE, stdin);
        sendline[strcspn(sendline, "\r\n")] = '\0';
        send(sockfd, sendline, strlen(sendline), 0);
        bzero(recvline, sizeof(recvline));
        if ((n = recv(sockfd, recvline, sizeof(recvline), 0)) < 0) {
            perror("recv failed");
            exit(EXIT_FAILURE);
        }
        recvline[n] = '\0';
        printf("Received: %s", recvline);
    }

    close(sockfd);
    return 0;
}