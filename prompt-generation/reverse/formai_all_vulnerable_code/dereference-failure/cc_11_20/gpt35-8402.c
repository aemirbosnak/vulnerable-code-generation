//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, port, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFSIZE];

    // check if enough arguments are passed
    if (argc < 3) {
        fprintf(stderr,"Usage: %s server_name port_number\n", argv[0]);
        exit(0);
    }

    // lookup server's host name
    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr, "Error: no such host %s\n", argv[1]);
        exit(0);
    }

    // get port number from argument
    port = atoi(argv[2]);

    // open a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    // initialize address structure
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // receive server's greeting
    memset(buffer, 0, BUFFSIZE);
    n = recv(sockfd, buffer, BUFFSIZE - 1, 0);

    if (n < 0) {
        perror("Error receiving message from server");
        exit(1);
    }

    printf("%s\n", buffer);

    // send login command
    memset(buffer, 0, BUFFSIZE);
    strcpy(buffer, "a001 LOGIN test@example.com password\n");
    n = send(sockfd, buffer, strlen(buffer), 0);

    if (n < 0) {
        perror("Error sending message to server");
        exit(1);
    }

    // receive response from server
    memset(buffer, 0, BUFFSIZE);
    n = recv(sockfd, buffer, BUFFSIZE - 1, 0);

    if (n < 0) {
        perror("Error receiving message from server");
        exit(1);
    }

    printf("%s\n", buffer);

    // send select command
    memset(buffer, 0, BUFFSIZE);
    strcpy(buffer, "a002 SELECT inbox\n");
    n = send(sockfd, buffer, strlen(buffer), 0);

    if (n < 0) {
        perror("Error sending message to server");
        exit(1);
    }

    // receive response from server
    memset(buffer, 0, BUFFSIZE);
    n = recv(sockfd, buffer, BUFFSIZE - 1, 0);

    if (n < 0) {
        perror("Error receiving message from server");
        exit(1);
    }

    printf("%s\n", buffer);

    // send fetch command
    memset(buffer, 0, BUFFSIZE);
    strcpy(buffer, "a003 FETCH 1 BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)]\n");
    n = send(sockfd, buffer, strlen(buffer), 0);

    if (n < 0) {
        perror("Error sending message to server");
        exit(1);
    }

    // receive response from server
    memset(buffer, 0, BUFFSIZE);
    n = recv(sockfd, buffer, BUFFSIZE - 1, 0);

    if (n < 0) {
        perror("Error receiving message from server");
        exit(1);
    }

    printf("%s\n", buffer);

    close(sockfd);

    return 0;
}