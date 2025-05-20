//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAXLINE 1024
#define PORT 21
#define USER "sherlock"
#define PASS "holmes"

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serveraddr;
    char sendline[MAXLINE], recvline[MAXLINE];
    char *ptr, *token;
    FILE *fp;
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &serveraddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        perror("connect");
        exit(1);
    }

    printf("Connected to server\n");

    if (login(sockfd, USER, PASS) == 0) {
        printf("Login successful\n");

        while (1) {
            printf("FTP> ");
            fgets(sendline, MAXLINE, stdin);
            n = strlen(sendline);

            if (sendline[n-1] == '\n') {
                sendline[n-1] = '\0';
            }

            if (send(sockfd, sendline, n, 0) == -1) {
                perror("send");
                exit(1);
            }

            n = 0;
            while ((n < MAXLINE) && ((ptr = fgets(recvline, MAXLINE, stdin))!= NULL)) {
                strcat(sendline, ptr);
                n += strlen(ptr);
            }

            if (send(sockfd, sendline, n, 0) == -1) {
                perror("send");
                exit(1);
            }

            if (strcmp(sendline, "bye") == 0) {
                break;
            }

            if (strcmp(sendline, "ls") == 0) {
                recv(sockfd, recvline, MAXLINE, 0);
                printf("%s", recvline);
            } else if (strcmp(sendline, "get") == 0) {
                token = strtok(sendline, " ");
                fp = fopen(token, "wb");
                if (fp == NULL) {
                    printf("Error opening file\n");
                } else {
                    while (1) {
                        n = recv(sockfd, recvline, MAXLINE, 0);
                        if (n <= 0) {
                            break;
                        }
                        fwrite(recvline, sizeof(char), n, fp);
                    }
                    fclose(fp);
                }
            } else if (strcmp(sendline, "put") == 0) {
                token = strtok(sendline, " ");
                fp = fopen(token, "rb");
                if (fp == NULL) {
                    printf("Error opening file\n");
                } else {
                    while (fread(sendline, sizeof(char), MAXLINE, fp) > 0) {
                        send(sockfd, sendline, strlen(sendline), 0);
                    }
                    fclose(fp);
                }
            }
        }

        close(sockfd);
        exit(0);
    } else {
        printf("Login failed\n");
        close(sockfd);
        exit(1);
    }
}