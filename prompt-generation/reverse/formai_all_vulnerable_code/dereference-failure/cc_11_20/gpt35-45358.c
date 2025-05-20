//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFSIZE 1024
#define SERVER_PORT 143

int main(int argc, char *argv[])
{
    int sockfd, n, i;
    struct sockaddr_in serveraddr;
    struct hostent *server;
    char buf[BUFSIZE];

    // check for command-line arguments
    if (argc != 3) {
        fprintf(stderr,"usage: %s <hostname> <username>\n", argv[0]);
        exit(0);
    }

    // get server address
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"Error: Host not found\n");
        exit(0);
    }

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr,"Error: Could not open socket\n");
        exit(0);
    }

    // set server address
    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&serveraddr.sin_addr.s_addr,
          server->h_length);
    serveraddr.sin_port = htons(SERVER_PORT);

    // connect to server
    if (connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0) {
        fprintf(stderr,"Error: Could not connect to server\n");
        exit(0);
    }

    // receive initial greeting from server
    bzero(buf, BUFSIZE);
    n = read(sockfd, buf, BUFSIZE-1);
    if (n < 0) {
        fprintf(stderr,"Error: Could not read from server\n");
        exit(0);
    }
    printf("%s\n", buf);

    // send login information to server
    sprintf(buf, ". login %s\n", argv[2]);
    n = write(sockfd, buf, strlen(buf));
    if (n < 0) {
        fprintf(stderr,"Error: Could not write to server\n");
        exit(0);
    }

    // receive response from server
    bzero(buf, BUFSIZE);
    n = read(sockfd, buf, BUFSIZE-1);
    if (n < 0) {
        fprintf(stderr,"Error: Could not read from server\n");
        exit(0);
    }
    printf("%s\n", buf);

    // select inbox
    sprintf(buf, ". select inbox\n");
    n = write(sockfd, buf, strlen(buf));
    if (n < 0) {
        fprintf(stderr,"Error: Could not write to server\n");
        exit(0);
    }

    // receive response from server
    bzero(buf, BUFSIZE);
    n = read(sockfd, buf, BUFSIZE-1);
    if (n < 0) {
        fprintf(stderr,"Error: Could not read from server\n");
        exit(0);
    }
    printf("%s\n", buf);

    // retrieve first 10 messages in inbox
    sprintf(buf, ". fetch 1:10 full\n");
    n = write(sockfd, buf, strlen(buf));
    if (n < 0) {
        fprintf(stderr,"Error: Could not write to server\n");
        exit(0);
    }

    // receive response from server
    bzero(buf, BUFSIZE);
    n = read(sockfd, buf, BUFSIZE-1);
    if (n < 0) {
        fprintf(stderr,"Error: Could not read from server\n");
        exit(0);
    }
    printf("%s\n", buf);

    // logout and close connection
    sprintf(buf, ". logout\n");
    n = write(sockfd, buf, strlen(buf));
    if (n < 0) {
        fprintf(stderr,"Error: Could not write to server\n");
        exit(0);
    }

    close(sockfd);
    exit(0);
}