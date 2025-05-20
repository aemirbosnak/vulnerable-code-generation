//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUF_SIZE 4096
#define MAX_COMMAND 1024

int main(int argc, char *argv[])
{
    int sockfd, n;
    char buf[BUF_SIZE];
    char command[MAX_COMMAND];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Romeo and Juliet style
    printf("O IMAP server, why doth thou forsake me?\n");
    printf("Nay, my love, I have not forsaken thee.\n");
    printf("Then why hath thou not responded to my commands?\n");
    printf("I cannot answer that, dear Romeo. Perhaps thou hath not sent the proper commands.\n");

    // check for correct command line usage
    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    // get server information
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host.\n");
        exit(1);
    }

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: could not create socket.\n");
        exit(1);
    }

    // initialize serv_addr
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    // connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error: could not connect to server.\n");
        exit(1);
    }

    // exchange greetings with server
    n = recv(sockfd, buf, BUF_SIZE, 0);
    if (n < 0) {
        fprintf(stderr, "Error: could not read from socket.\n");
        exit(1);
    }
    buf[n] = '\0';
    printf("%s", buf);

    // authenticate with server
    sprintf(command, "1 LOGIN %s %s\r\n", "username", "password");
    n = send(sockfd, command, strlen(command), 0);
    if (n < 0) {
        fprintf(stderr, "Error: could not write to socket.\n");
        exit(1);
    }
    n = recv(sockfd, buf, BUF_SIZE, 0);
    if (n < 0) {
        fprintf(stderr, "Error: could not read from socket.\n");
        exit(1);
    }
    buf[n] = '\0';
    printf("%s", buf);

    // select inbox
    sprintf(command, "2 SELECT INBOX\r\n");
    n = send(sockfd, command, strlen(command), 0);
    if (n < 0) {
        fprintf(stderr, "Error: could not write to socket.\n");
        exit(1);
    }
    n = recv(sockfd, buf, BUF_SIZE, 0);
    if (n < 0) {
        fprintf(stderr, "Error: could not read from socket.\n");
        exit(1);
    }
    buf[n] = '\0';
    printf("%s", buf);

    // fetch list of messages
    sprintf(command, "3 FETCH 1:* (FLAGS BODY[HEADER.FIELDS (SUBJECT FROM)])\r\n");
    n = send(sockfd, command, strlen(command), 0);
    if (n < 0) {
        fprintf(stderr, "Error: could not write to socket.\n");
        exit(1);
    }
    n = recv(sockfd, buf, BUF_SIZE, 0);
    if (n < 0) {
        fprintf(stderr, "Error: could not read from socket.\n");
        exit(1);
    }
    buf[n] = '\0';
    printf("%s", buf);

    // close connection
    sprintf(command, "4 LOGOUT\r\n");
    n = send(sockfd, command, strlen(command), 0);
    if (n < 0) {
        fprintf(stderr, "Error: could not write to socket.\n");
        exit(1);
    }
    n = recv(sockfd, buf, BUF_SIZE, 0);
    if (n < 0) {
        fprintf(stderr, "Error: could not read from socket.\n");
        exit(1);
    }
    buf[n] = '\0';
    printf("%s", buf);

    // Romeo and Juliet style
    printf("Farewell, my love, until we meet again.\n");

    close(sockfd);
    return 0;
}