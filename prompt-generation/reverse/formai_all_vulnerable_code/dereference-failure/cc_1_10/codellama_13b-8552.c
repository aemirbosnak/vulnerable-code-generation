//Code Llama-13B DATASET v1.0 Category: Building a IMAP Client ; Style: safe
/*
 * Building a IMAP Client example program in a safe style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFSIZE 1024
#define HOST "imap.example.com"
#define PORT 993

int main(int argc, char **argv)
{
    int sockfd, n;
    char buf[BUFSIZE];
    struct sockaddr_in serveraddr;
    struct hostent *server;

    // create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // lookup the server address
    server = gethostbyname(HOST);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host: %s\n", HOST);
        exit(1);
    }

    // set up the server address
    memset((char *) &serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    memcpy((char *) &serveraddr.sin_addr.s_addr, (char *) server->h_addr, server->h_length);

    // connect to the server
    if (connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // send the IMAP login command
    sprintf(buf, "LOGIN %s\r\n", argv[1]);
    send(sockfd, buf, strlen(buf), 0);

    // read the server response
    memset(buf, 0, BUFSIZE);
    n = recv(sockfd, buf, BUFSIZE, 0);
    if (n < 0) {
        perror("ERROR reading response");
        exit(1);
    }

    printf("Response: %s\n", buf);

    // close the socket
    close(sockfd);

    return 0;
}