//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>

#define MAXLINE 1024
#define STATUS_SIZE 128

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in servaddr;
    char sendline[MAXLINE], recvline[MAXLINE];

    if (argc != 4) {
        fprintf(stderr, "usage: %s <hostname> <port> <username>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send the username
    sprintf(sendline, "USER %s\r\n", argv[3]);
    if (send(sockfd, sendline, strlen(sendline), 0) < 0) {
        perror("send");
        exit(1);
    }
    if (recv(sockfd, recvline, MAXLINE, 0) < 0) {
        perror("recv");
        exit(1);
    }
    if (strncmp(recvline, "+OK", 3) != 0) {
        fprintf(stderr, "Error: %s\n", recvline);
        exit(1);
    }

    // Send the password
    sprintf(sendline, "PASS %s\r\n", getpass("Password: "));
    if (send(sockfd, sendline, strlen(sendline), 0) < 0) {
        perror("send");
        exit(1);
    }
    if (recv(sockfd, recvline, MAXLINE, 0) < 0) {
        perror("recv");
        exit(1);
    }
    if (strncmp(recvline, "+OK", 3) != 0) {
        fprintf(stderr, "Error: %s\n", recvline);
        exit(1);
    }

    // Send the command
    sprintf(sendline, "LIST\r\n");
    if (send(sockfd, sendline, strlen(sendline), 0) < 0) {
        perror("send");
        exit(1);
    }

    while (1) {
        if (recv(sockfd, recvline, MAXLINE, 0) < 0) {
            perror("recv");
            exit(1);
        }
        if (strncmp(recvline, "* LIST", 6) == 0) {
            break;
        }
    }

    while (1) {
        if (recv(sockfd, recvline, MAXLINE, 0) < 0) {
            perror("recv");
            exit(1);
        }
        if (strncmp(recvline, "*", 1) == 0) {
            break;
        }
        printf("%s", recvline);
    }

    // Send the QUIT command
    sprintf(sendline, "QUIT\r\n");
    if (send(sockfd, sendline, strlen(sendline), 0) < 0) {
        perror("send");
        exit(1);
    }

    close(sockfd);
    return 0;
}