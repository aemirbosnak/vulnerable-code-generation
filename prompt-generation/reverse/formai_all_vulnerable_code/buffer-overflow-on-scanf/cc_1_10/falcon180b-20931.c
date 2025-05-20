//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFSIZ 1024
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in serveraddr;
    char username[50], password[50], command[100];
    char buf[BUFSIZ];
    int n;

    printf("Enter your POP3 username: ");
    scanf("%s", username);

    printf("Enter your POP3 password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket failed: %s\n", strerror(errno));
        exit(1);
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(110);
    inet_pton(AF_INET, "localhost", &serveraddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        printf("connect failed: %s\n", strerror(errno));
        exit(1);
    }

    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send(sockfd, command, strlen(command), 0);

    n = recv(sockfd, buf, BUFSIZ, 0);
    if (n <= 0) {
        printf("recv failed: %s\n", strerror(errno));
        exit(1);
    }

    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);

    n = recv(sockfd, buf, BUFSIZ, 0);
    if (n <= 0) {
        printf("recv failed: %s\n", strerror(errno));
        exit(1);
    }

    printf("POP3 server connected successfully!\n");

    close(sockfd);

    return 0;
}