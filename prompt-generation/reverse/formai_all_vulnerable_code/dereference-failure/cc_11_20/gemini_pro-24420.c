//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define POP3_PORT 110
#define POP3_BUFF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buff[POP3_BUFF_SIZE];
    struct sockaddr_in serv_addr;

    // Connect to the POP3 server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(POP3_PORT);
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Read the welcome message
    n = read(sockfd, buff, POP3_BUFF_SIZE);
    if (n < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    printf("%s", buff);

    // Log in to the server
    sprintf(buff, "USER %s\r\n", argv[2]);
    n = write(sockfd, buff, strlen(buff));
    if (n < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    n = read(sockfd, buff, POP3_BUFF_SIZE);
    if (n < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    printf("%s", buff);

    sprintf(buff, "PASS %s\r\n", argv[3]);
    n = write(sockfd, buff, strlen(buff));
    if (n < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    n = read(sockfd, buff, POP3_BUFF_SIZE);
    if (n < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    printf("%s", buff);

    // List the messages
    sprintf(buff, "STAT\r\n");
    n = write(sockfd, buff, strlen(buff));
    if (n < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    n = read(sockfd, buff, POP3_BUFF_SIZE);
    if (n < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    printf("%s", buff);

    // Fetch a message
    sprintf(buff, "RETR 1\r\n");
    n = write(sockfd, buff, strlen(buff));
    if (n < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    n = read(sockfd, buff, POP3_BUFF_SIZE);
    if (n < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    printf("%s", buff);

    // Quit the server
    sprintf(buff, "QUIT\r\n");
    n = write(sockfd, buff, strlen(buff));
    if (n < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    n = read(sockfd, buff, POP3_BUFF_SIZE);
    if (n < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    printf("%s", buff);

    close(sockfd);
    return 0;
}