//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <ctype.h>
#include <errno.h>

#define MAXLINE 1024
#define MAX_MAILBOXES 10

int main(int argc, char *argv[]) {

    if (argc!= 2) {
        printf("Usage: %s <server>\n", argv[0]);
        return 1;
    }

    char hostname[MAXLINE];
    strncpy(hostname, argv[1], MAXLINE);
    hostname[MAXLINE-1] = '\0';

    struct addrinfo hints, *servinfo, *p;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    int sockfd;
    if ((sockfd = getaddrinfo(hostname, "imap", &hints, &servinfo)) < 0) {
        perror("getaddrinfo");
        exit(EXIT_FAILURE);
    }

    for(p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }
        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("connect");
            close(sockfd);
            continue;
        }
        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Failed to connect\n");
        return 1;
    }

    int n = 0;
    char line[MAXLINE], buffer[MAXLINE];
    for(;;) {
        if (n == MAX_MAILBOXES) {
            printf("Maximum number of mailboxes reached.\n");
            return 0;
        }
        memset(buffer, '\0', MAXLINE);
        memset(line, '\0', MAXLINE);
        if (n > 0) {
            printf("(%d) ", n);
        }
        if (n == 0) {
            printf("List ");
        }
        printf("*\n");

        if (fgets(line, MAXLINE, stdin) == NULL) {
            perror("fgets");
            return 1;
        }
        if (line[strlen(line)-1] == '\n') {
            line[strlen(line)-1] = '\0';
        }

        if (n == 0) {
            if (strncmp(line, "List ", 5)!= 0) {
                printf("Error: mailbox name not specified\n");
                continue;
            }
        }
        else {
            if (strncmp(line, "* ", 2)!= 0) {
                printf("Error: mailbox name not specified\n");
                continue;
            }
        }

        if (send(sockfd, line, strlen(line), 0) == -1) {
            perror("send");
            return 1;
        }
        if (recv(sockfd, buffer, MAXLINE, 0) == -1) {
            perror("recv");
            return 1;
        }

        printf("%s\n", buffer);
        n++;
    }

    return 0;
}