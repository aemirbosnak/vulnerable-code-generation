//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <ctype.h>

#define PORT 110
#define MAXLINE 1024
#define USER "user"
#define PASS "pass"

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    char recvline[MAXLINE];
    char sendline[MAXLINE];
    char user[20];
    char pass[20];
    int n;

    printf("Welcome to the POP3 client\n");
    printf("Enter your username: ");
    scanf("%s", user);
    printf("Enter your password: ");
    scanf("%s", pass);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        printf("Enter command (quit to exit): ");
        scanf("%s", sendline);

        if (strcmp(sendline, "quit") == 0) {
            break;
        }

        n = send(sockfd, sendline, strlen(sendline), 0);
        if (n == -1) {
            printf("Error sending command\n");
            exit(1);
        }

        memset(recvline, 0, sizeof(recvline));
        n = recv(sockfd, recvline, MAXLINE, 0);
        if (n == -1) {
            printf("Error receiving response\n");
            exit(1);
        }

        printf("Response: %s\n", recvline);
    }

    close(sockfd);
    return 0;
}