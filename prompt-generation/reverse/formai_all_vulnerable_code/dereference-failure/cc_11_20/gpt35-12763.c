//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

int main(int argc, char *argv[])
{
    struct sockaddr_in serveraddr;
    struct hostent *hostp;
    int sockfd;
    char buffer[BUFSIZE];
    char *username, *password;
    char *host, *port;
    int n;

    if (argc != 5) {
        fprintf(stderr, "Usage: %s <username> <password> <host> <port>\n", argv[0]);
        exit(1);
    }
    username = argv[1];
    password = argv[2];
    host = argv[3];
    port = argv[4];

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // get server hostname
    hostp = gethostbyname(host);
    if (hostp == NULL) {
        fprintf(stderr, "ERROR, no such host as %s\n", host);
        exit(1);
    }

    // build the server's Internet address
    bzero((char *)&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)hostp->h_addr, (char *)&serveraddr.sin_addr.s_addr, hostp->h_length);
    serveraddr.sin_port = htons(atoi(port));

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // receive initial greeting message from server
    bzero(buffer, BUFSIZE);
    n = read(sockfd, buffer, BUFSIZE - 1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    // send login credentials to server
    snprintf(buffer, BUFSIZE, "LOGIN %s %s\r\n", username, password);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // receive response from server
    bzero(buffer, BUFSIZE);
    n = read(sockfd, buffer, BUFSIZE - 1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    // send command to list email boxes on server
    snprintf(buffer, BUFSIZE, "LIST \"\" *\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // receive response from server
    bzero(buffer, BUFSIZE);
    n = read(sockfd, buffer, BUFSIZE - 1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    // send command to select inbox
    snprintf(buffer, BUFSIZE, "SELECT INBOX\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // receive response from server
    bzero(buffer, BUFSIZE);
    n = read(sockfd, buffer, BUFSIZE - 1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    // send command to fetch email headers
    snprintf(buffer, BUFSIZE, "FETCH 1:* (BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)])\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // receive email headers from server
    while ((n = read(sockfd, buffer, BUFSIZE - 1)) != 0) {
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        printf("%.*s", n, buffer);
    }

    // send command to logout
    snprintf(buffer, BUFSIZE, "LOGOUT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // receive response from server
    bzero(buffer, BUFSIZE);
    n = read(sockfd, buffer, BUFSIZE - 1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    // close socket
    close(sockfd);
    return 0;
}