//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define POP3_PORT    110
#define BUFSIZE     1024

int main(int argc, char *argv[])
{
    int sockfd, n;
    char buf[BUFSIZE];
    struct sockaddr_in servaddr;
    struct hostent *hptr;
    char *host, *username, *password;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <host> <username> <password>\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    username = argv[2];
    password = argv[3];

    if ((hptr = gethostbyname(host)) == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(POP3_PORT);
    memcpy(&servaddr.sin_addr, hptr->h_addr_list[0], sizeof(servaddr.sin_addr));

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    if ((n = read(sockfd, buf, BUFSIZE)) < 0) {
        perror("read");
        exit(1);
    }

    printf("%s", buf);

    snprintf(buf, BUFSIZE, "USER %s\r\n", username);
    if ((n = write(sockfd, buf, strlen(buf))) < 0) {
        perror("write");
        exit(1);
    }

    if ((n = read(sockfd, buf, BUFSIZE)) < 0) {
        perror("read");
        exit(1);
    }

    printf("%s", buf);

    snprintf(buf, BUFSIZE, "PASS %s\r\n", password);
    if ((n = write(sockfd, buf, strlen(buf))) < 0) {
        perror("write");
        exit(1);
    }

    if ((n = read(sockfd, buf, BUFSIZE)) < 0) {
        perror("read");
        exit(1);
    }

    printf("%s", buf);

    snprintf(buf, BUFSIZE, "LIST\r\n");
    if ((n = write(sockfd, buf, strlen(buf))) < 0) {
        perror("write");
        exit(1);
    }

    if ((n = read(sockfd, buf, BUFSIZE)) < 0) {
        perror("read");
        exit(1);
    }

    printf("%s", buf);

    snprintf(buf, BUFSIZE, "QUIT\r\n");
    if ((n = write(sockfd, buf, strlen(buf))) < 0) {
        perror("write");
        exit(1);
    }

    if ((n = read(sockfd, buf, BUFSIZE)) < 0) {
        perror("read");
        exit(1);
    }

    printf("%s", buf);

    close(sockfd);

    return 0;
}