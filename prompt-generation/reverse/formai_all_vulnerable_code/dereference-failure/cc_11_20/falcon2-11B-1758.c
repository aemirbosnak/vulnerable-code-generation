//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buf[256], *cmd = "USER";
    FILE *fp;

    portno = 110;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    server = gethostbyname("pop.gmail.com");
    if (server == NULL) {
        fprintf(stderr, "No such host\n");
        exit(EXIT_FAILURE);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }
    fprintf(stderr, "Connected to POP3 server\n");

    fp = popen("cat /dev/urandom | tr -dc 'A-Za-z0-9' | head -c 16 | fold -w 70 | fmt -w 70", "r");
    if (fp == NULL) {
        perror("popen failed");
        exit(EXIT_FAILURE);
    }
    while ((n = read(sockfd, buf, sizeof(buf))) > 0) {
        if (strcmp(buf, "OK") == 0) {
            fprintf(stderr, "Authenticated\n");
            bzero(buf, sizeof(buf));
        } else if (strcmp(buf, "USER") == 0) {
            strcpy(buf, "user1");
            write(sockfd, buf, sizeof(buf));
        } else if (strcmp(buf, "PASS") == 0) {
            strcpy(buf, "password1");
            write(sockfd, buf, sizeof(buf));
        } else if (strcmp(buf, "+OK") == 0) {
            fprintf(stderr, "Logged in\n");
            bzero(buf, sizeof(buf));
        } else if (strcmp(buf, "-ERR") == 0) {
            fprintf(stderr, "Invalid username or password\n");
            exit(EXIT_FAILURE);
        } else {
            printf("%s", buf);
        }
    }
    fprintf(stderr, "No more messages\n");
    close(sockfd);
    pclose(fp);
    return 0;
}