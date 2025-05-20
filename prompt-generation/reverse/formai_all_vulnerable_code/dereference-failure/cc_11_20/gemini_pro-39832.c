//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LINE 1024

struct message {
    char *from;
    char *to;
    char *subject;
    char *body;
};

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in servaddr;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server IP address> <port>\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(2);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        fprintf(stderr, "inet_pton error for %s\n", argv[1]);
        exit(3);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(4);
    }

    char buf[MAX_LINE];
    int n;

    while ((n = read(sockfd, buf, MAX_LINE)) > 0) {
        buf[n] = '\0';
        printf("%s", buf);
        if (strstr(buf, "OK") != NULL) {
            break;
        }
    }

    if (n < 0) {
        perror("read");
        exit(5);
    }

    char cmd[MAX_LINE];
    char arg[MAX_LINE];

    while (1) {
        printf("> ");
        scanf("%s %s", cmd, arg);

        if (strcmp(cmd, "exit") == 0) {
            break;
        } else if (strcmp(cmd, "login") == 0) {
            sprintf(buf, "LOGIN %s %s\r\n", arg, argv[3]);
            write(sockfd, buf, strlen(buf));
        } else if (strcmp(cmd, "list") == 0) {
            sprintf(buf, "LIST %s\r\n", arg);
            write(sockfd, buf, strlen(buf));
        } else if (strcmp(cmd, "retr") == 0) {
            sprintf(buf, "RETRIEVE %s\r\n", arg);
            write(sockfd, buf, strlen(buf));
        }

        while ((n = read(sockfd, buf, MAX_LINE)) > 0) {
            buf[n] = '\0';
            printf("%s", buf);
            if (strstr(buf, "OK") != NULL) {
                break;
            }
        }

        if (n < 0) {
            perror("read");
            exit(5);
        }
    }

    close(sockfd);

    exit(0);
}