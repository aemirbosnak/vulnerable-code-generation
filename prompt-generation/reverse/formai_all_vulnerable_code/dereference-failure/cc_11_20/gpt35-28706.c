//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAX_SIZE], *user, *password, *mailbox;
    if (argc < 5) {
        printf("Error: Usage %s hostname portnumber username password mailbox\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error: No such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting\n");
        exit(1);
    }

    // Login to server
    user = argv[3];
    password = argv[4];
    sprintf(buffer, ". login %s %s\n", user, password);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        printf("Error writing to socket\n");
        exit(1);
    }

    bzero(buffer, MAX_SIZE);
    n = read(sockfd, buffer, MAX_SIZE-1);
    if (n < 0) {
        printf("Error reading from socket\n");
        exit(1);
    }
    printf("%s", buffer);
    
    // Select mailbox
    mailbox = argv[5];
    sprintf(buffer, ". select %s\n", mailbox);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        printf("Error writing to socket\n");
        exit(1);
    }

    bzero(buffer, MAX_SIZE);
    n = read(sockfd, buffer, MAX_SIZE-1);
    if (n < 0) {
        printf("Error reading from socket\n");
        exit(1);
    }
    printf("%s", buffer);

    // List messages
    sprintf(buffer, ". uid fetch 1:* flags\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        printf("Error writing to socket\n");
        exit(1);
    }

    bzero(buffer, MAX_SIZE);
    n = read(sockfd, buffer, MAX_SIZE-1);
    if (n < 0) {
        printf("Error reading from socket\n");
        exit(1);
    }
    printf("%s", buffer);

    // Logout of server
    sprintf(buffer, ". logout\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        printf("Error writing to socket\n");
        exit(1);
    }

    bzero(buffer, MAX_SIZE);
    n = read(sockfd, buffer, MAX_SIZE-1);
    if (n < 0) {
        printf("Error reading from socket\n");
        exit(1);
    }
    printf("%s", buffer);

    close(sockfd);
    return 0;
}