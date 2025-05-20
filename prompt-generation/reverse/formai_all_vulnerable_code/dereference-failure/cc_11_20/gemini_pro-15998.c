//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define POP3_PORT 110

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <server> <username>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host\n");
        exit(2);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: socket");
        exit(3);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(POP3_PORT);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error: connect");
        exit(4);
    }

    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        perror("Error: read");
        exit(5);
    }

    printf("%s", buffer);

    bzero(buffer, 256);
    sprintf(buffer, "USER %s\r\n", argv[2]);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error: write");
        exit(6);
    }

    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        perror("Error: read");
        exit(7);
    }

    printf("%s", buffer);

    bzero(buffer, 256);
    sprintf(buffer, "PASS %s\r\n", argv[3]);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error: write");
        exit(8);
    }

    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        perror("Error: read");
        exit(9);
    }

    printf("%s", buffer);

    bzero(buffer, 256);
    sprintf(buffer, "STAT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error: write");
        exit(10);
    }

    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        perror("Error: read");
        exit(11);
    }

    printf("%s", buffer);

    bzero(buffer, 256);
    sprintf(buffer, "LIST\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error: write");
        exit(12);
    }

    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        perror("Error: read");
        exit(13);
    }

    printf("%s", buffer);

    bzero(buffer, 256);
    sprintf(buffer, "RETR 1\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error: write");
        exit(14);
    }

    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        perror("Error: read");
        exit(15);
    }

    printf("%s", buffer);

    bzero(buffer, 256);
    sprintf(buffer, "QUIT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error: write");
        exit(16);
    }

    close(sockfd);
    return 0;
}