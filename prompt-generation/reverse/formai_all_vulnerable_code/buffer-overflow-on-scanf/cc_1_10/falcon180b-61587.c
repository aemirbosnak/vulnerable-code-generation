//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 1024

int main(int argc, char *argv[])
{
    int sockfd, ret;
    struct sockaddr_in servaddr;
    char sendline[MAX_LINE], recvline[MAX_LINE];
    char username[MAX_LINE], password[MAX_LINE];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(110);
    inet_pton(AF_INET, "localhost", &servaddr.sin_addr);

    ret = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (ret == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    sendline[0] = '\0';
    strcat(sendline, "USER ");
    strcat(sendline, username);
    strcat(sendline, "\r\n");
    ret = send(sockfd, sendline, strlen(sendline), 0);
    if (ret == -1) {
        printf("Error sending username\n");
        exit(1);
    }

    sendline[0] = '\0';
    strcat(sendline, "PASS ");
    strcat(sendline, password);
    strcat(sendline, "\r\n");
    ret = send(sockfd, sendline, strlen(sendline), 0);
    if (ret == -1) {
        printf("Error sending password\n");
        exit(1);
    }

    recvline[0] = '\0';
    ret = recv(sockfd, recvline, MAX_LINE, 0);
    if (ret == -1) {
        printf("Error receiving response\n");
        exit(1);
    }

    printf("Server response: %s", recvline);

    close(sockfd);
    return 0;
}