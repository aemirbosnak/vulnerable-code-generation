//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char **argv)
{
    int sockfd, n;
    char buffer[1024];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Authentication
    bzero(buffer,1024);
    sprintf(buffer, ". login username password\n");
    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    bzero(buffer,1024);
    n = read(sockfd,buffer,1024);
    if (n < 0) {
         perror("ERROR reading from socket");
         exit(1);
    }

    // Select mailbox
    bzero(buffer,1024);
    sprintf(buffer, ". select INBOX\n");
    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    bzero(buffer,1024);
    n = read(sockfd,buffer,1024);
    if (n < 0) {
         perror("ERROR reading from socket");
         exit(1);
    }

    // Get latest emails
    bzero(buffer,1024);
    sprintf(buffer, ". fetch 1:* body[text]\n");
    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    bzero(buffer,1024);
    n = read(sockfd,buffer,1024);
    if (n < 0) {
         perror("ERROR reading from socket");
         exit(1);
    }

    // Print email details
    printf("%s", buffer);

    // Logout
    bzero(buffer,1024);
    sprintf(buffer, ". logout\n");
    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    close(sockfd);
    return 0;
}