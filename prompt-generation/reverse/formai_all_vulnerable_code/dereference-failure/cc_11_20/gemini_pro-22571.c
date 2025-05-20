//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFERSIZE 1024

int main(int argc, char **argv) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFERSIZE];
    char cmd[BUFFERSIZE];
    char *host;
    char *user;
    char *pass;

    if (argc < 5) {
        fprintf(stderr, "Usage: %s <hostname> <port> <username> <password>\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    portno = atoi(argv[2]);
    user = argv[3];
    pass = argv[4];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    bzero(buffer, BUFFERSIZE);
    if (read(sockfd, buffer, BUFFERSIZE) < 0) {
        perror("read");
        exit(1);
    }

    printf("%s", buffer);

    snprintf(cmd, BUFFERSIZE, "USER %s\r\n", user);
    if (write(sockfd, cmd, strlen(cmd)) < 0) {
        perror("write");
        exit(1);
    }

    bzero(buffer, BUFFERSIZE);
    if (read(sockfd, buffer, BUFFERSIZE) < 0) {
        perror("read");
        exit(1);
    }

    printf("%s", buffer);

    snprintf(cmd, BUFFERSIZE, "PASS %s\r\n", pass);
    if (write(sockfd, cmd, strlen(cmd)) < 0) {
        perror("write");
        exit(1);
    }

    bzero(buffer, BUFFERSIZE);
    if (read(sockfd, buffer, BUFFERSIZE) < 0) {
        perror("read");
        exit(1);
    }

    printf("%s", buffer);

    while (1) {
        bzero(buffer, BUFFERSIZE);
        printf("> ");
        fgets(buffer, BUFFERSIZE, stdin);

        if (strncmp(buffer, "quit", 4) == 0) {
            break;
        }

        if (write(sockfd, buffer, strlen(buffer)) < 0) {
            perror("write");
            exit(1);
        }

        bzero(buffer, BUFFERSIZE);
        if (read(sockfd, buffer, BUFFERSIZE) < 0) {
            perror("read");
            exit(1);
        }

        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}