//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAXSIZE 1024

int main()
{
    int sockfd, n;
    char buffer[MAXSIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char *username = "your_username";
    char *password = "your_password";

    // Establishing the connection
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname("imap.google.com");

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(143);
    bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Logging in to the server
    sprintf(buffer, ". LOGIN %s %s\r\n", username, password);
    n = write(sockfd, buffer, strlen(buffer));

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    bzero(buffer, MAXSIZE);
    n = read(sockfd, buffer, MAXSIZE - 1);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("%s\n", buffer); // Displaying the login response message

    // Selecting the mailbox
    sprintf(buffer, ". SELECT \"INBOX\"\r\n");
    n = write(sockfd, buffer, strlen(buffer));

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    bzero(buffer, MAXSIZE);
    n = read(sockfd, buffer, MAXSIZE - 1);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("%s\n", buffer); // Displaying the select response message

    // Fetching the emails
    sprintf(buffer, ". FETCH 1:* (FLAGS BODY[HEADER.FIELDS (FROM SUBJECT DATE)])\r\n");
    n = write(sockfd, buffer, strlen(buffer));

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    bzero(buffer, MAXSIZE);
    n = read(sockfd, buffer, MAXSIZE - 1);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("%s\n", buffer); // Displaying the fetch response message

    // Logging out of the server
    sprintf(buffer, ". LOGOUT\r\n");
    n = write(sockfd, buffer, strlen(buffer));

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    bzero(buffer, MAXSIZE);
    n = read(sockfd, buffer, MAXSIZE - 1);

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("%s\n", buffer); // Displaying the logout response message

    close(sockfd); // Closing the socket

    return 0;
}