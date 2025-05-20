//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[BUFFER_SIZE];
    struct hostent *server;
    struct sockaddr_in serv_addr;

    if (argc != 3) {
        fprintf(stderr,"Usage: %s <hostname> <username>\n", argv[0]);
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR: no such host\n");
        exit(0);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(143);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Connected to %s\n", argv[1]);

    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("%s", buffer);

    memset(buffer, 0, BUFFER_SIZE);

    sprintf(buffer, "a001 LOGIN %s\r\n", argv[2]);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("%s", buffer);

    memset(buffer, 0, BUFFER_SIZE);

    sprintf(buffer, "a002 LIST \"\" *\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("%s", buffer);

    memset(buffer, 0, BUFFER_SIZE);

    sprintf(buffer, "a003 SELECT INBOX\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("%s", buffer);

    memset(buffer, 0, BUFFER_SIZE);

    sprintf(buffer, "a004 FETCH 1 BODY[]\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("%s", buffer);

    close(sockfd);

    return 0;
}