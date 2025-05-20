//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

#define MAX_BUFF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAX_BUFF_SIZE];

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        fprintf(stderr,"ERROR opening socket\n");
        exit(1);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        fprintf(stderr,"ERROR connecting\n");
        exit(1);
    }

    // send initial message to server
    strcpy(buffer, "a001 LOGIN user password\r\n");
    n = write(sockfd, buffer, strlen(buffer));

    if (n < 0) {
        fprintf(stderr,"ERROR writing to socket\n");
        exit(1);
    }

    bzero(buffer, MAX_BUFF_SIZE);
    n = read(sockfd, buffer, MAX_BUFF_SIZE);

    if (n < 0) {
        fprintf(stderr,"ERROR reading from socket\n");
        exit(1);
    }

    printf("%s", buffer);

    // send SELECT message to server
    strcpy(buffer, "a002 SELECT inbox\r\n");
    n = write(sockfd, buffer, strlen(buffer));

    if (n < 0) {
        fprintf(stderr,"ERROR writing to socket\n");
        exit(1);
    }

    bzero(buffer, MAX_BUFF_SIZE);
    n = read(sockfd, buffer, MAX_BUFF_SIZE);

    if (n < 0) {
        fprintf(stderr,"ERROR reading from socket\n");
        exit(1);
    }

    printf("%s", buffer);

    // send FETCH message to server
    strcpy(buffer, "a003 FETCH 1 BODY[HEADER]\r\n");
    n = write(sockfd, buffer, strlen(buffer));

    if (n < 0) {
        fprintf(stderr,"ERROR writing to socket\n");
        exit(1);
    }

    bzero(buffer, MAX_BUFF_SIZE);
    n = read(sockfd, buffer, MAX_BUFF_SIZE);

    if (n < 0) {
        fprintf(stderr,"ERROR reading from socket\n");
        exit(1);
    }

    printf("%s", buffer);

    // send LOGOUT message to server
    strcpy(buffer, "a004 LOGOUT\r\n");
    n = write(sockfd, buffer, strlen(buffer));

    if (n < 0) {
        fprintf(stderr,"ERROR writing to socket\n");
        exit(1);
    }

    bzero(buffer, MAX_BUFF_SIZE);
    n = read(sockfd, buffer, MAX_BUFF_SIZE);

    if (n < 0) {
        fprintf(stderr,"ERROR reading from socket\n");
        exit(1);
    }

    printf("%s", buffer);

    close(sockfd);

    return 0;
}