//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 21
#define MAX_LINE 1024

int main(int argc, char *argv[])
{
    int sockfd, ret;
    struct sockaddr_in servaddr;
    char buf[MAX_LINE];

    if (argc != 3) {
        fprintf(stderr, "usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    // create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // connect to the server
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
    ret = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (ret == -1) {
        perror("connect");
        exit(1);
    }

    // send USER command
    strcpy(buf, "USER anonymous\r\n");
    ret = send(sockfd, buf, strlen(buf), 0);
    if (ret == -1) {
        perror("send");
        exit(1);
    }

    // receive response
    memset(buf, 0, MAX_LINE);
    ret = recv(sockfd, buf, MAX_LINE, 0);
    if (ret == -1) {
        perror("recv");
        exit(1);
    }

    if (strncmp(buf, "331", 3) != 0) {
        fprintf(stderr, "Error: %s\n", buf);
        exit(1);
    }

    // send PASS command
    strcpy(buf, "PASS guest@example.com\r\n");
    ret = send(sockfd, buf, strlen(buf), 0);
    if (ret == -1) {
        perror("send");
        exit(1);
    }

    // receive response
    memset(buf, 0, MAX_LINE);
    ret = recv(sockfd, buf, MAX_LINE, 0);
    if (ret == -1) {
        perror("recv");
        exit(1);
    }

    if (strncmp(buf, "230", 3) != 0) {
        fprintf(stderr, "Error: %s\n", buf);
        exit(1);
    }

    // send LIST command
    strcpy(buf, "LIST\r\n");
    ret = send(sockfd, buf, strlen(buf), 0);
    if (ret == -1) {
        perror("send");
        exit(1);
    }

    // receive response
    while ((ret = recv(sockfd, buf, MAX_LINE, 0)) > 0) {
        printf("%s", buf);
        memset(buf, 0, MAX_LINE);
    }

    if (ret == -1) {
        perror("recv");
        exit(1);
    }

    // send QUIT command
    strcpy(buf, "QUIT\r\n");
    ret = send(sockfd, buf, strlen(buf), 0);
    if (ret == -1) {
        perror("send");
        exit(1);
    }

    // close the socket
    close(sockfd);

    return 0;
}