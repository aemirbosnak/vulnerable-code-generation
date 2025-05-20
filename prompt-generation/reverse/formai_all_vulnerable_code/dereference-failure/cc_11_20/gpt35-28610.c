//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFSIZE];
    if (argc < 3) {
        fprintf(stderr,"usage: %s hostname port\n", argv[0]);
        exit(1);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }
    /* Welcome message and login */
    bzero(buffer, BUFSIZE);
    n = read(sockfd, buffer, BUFSIZE);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);
    bzero(buffer, BUFSIZE);
    printf("Enter your Username:");
    fgets(buffer, BUFSIZE, stdin);
    buffer[strcspn(buffer, "\n")] = 0; /* remove newline */
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
    /* Password authentication */
    bzero(buffer, BUFSIZE);
    n = read(sockfd, buffer, BUFSIZE);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);
    bzero(buffer, BUFSIZE);
    printf("Enter your Password:");
    fgets(buffer, BUFSIZE, stdin);
    buffer[strcspn(buffer, "\n")] = 0; /* remove newline */
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
    /* Display Mailbox */
    bzero(buffer, BUFSIZE);
    n = read(sockfd, buffer, BUFSIZE);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);
    /* Loop to handle user commands */
    while (1) {
        bzero(buffer, BUFSIZE);
        printf(">>> ");
        fgets(buffer, BUFSIZE, stdin); /* get user input */
        buffer[strcspn(buffer, "\n")] = 0; /* remove newline */
        n = write(sockfd, buffer, strlen(buffer)); /* send command to server */
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
        /* Display server response */
        bzero(buffer, BUFSIZE);
        n = read(sockfd, buffer, BUFSIZE);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        printf("%s\n", buffer);
        /* Quit command */
        if (strcmp(buffer, "Bye!") == 0) {
            break;
        }
    }

    close(sockfd);
    return 0;
}