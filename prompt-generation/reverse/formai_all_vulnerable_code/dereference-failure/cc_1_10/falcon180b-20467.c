//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAXLINE 1024
#define PORT 110
#define USER "your_username"
#define PASS "your_password"

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo *servinfo;
    struct sockaddr *servaddr;
    char host[NI_MAXHOST];
    char port[NI_MAXSERV];
    int rv;
    int numbytes;
    char sendline[MAXLINE];
    char recvline[MAXLINE];

    printf("Starting POP3 client...\n");

    // Create socket
    if ((rv = getaddrinfo("pop.gmail.com", "pop3", NULL, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(rv));
        exit(1);
    }

    sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);

    if (sockfd == -1) {
        fprintf(stderr, "socket error\n");
        exit(1);
    }

    // Connect to server
    if (connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) == -1) {
        fprintf(stderr, "connect error\n");
        exit(1);
    }

    // Authenticate
    sprintf(sendline, "USER %s\r\n", USER);
    send(sockfd, sendline, strlen(sendline), 0);
    numbytes = recv(sockfd, recvline, MAXLINE, 0);
    recvline[numbytes] = '\0';
    printf("Received: %s", recvline);

    sprintf(sendline, "PASS %s\r\n", PASS);
    send(sockfd, sendline, strlen(sendline), 0);
    numbytes = recv(sockfd, recvline, MAXLINE, 0);
    recvline[numbytes] = '\0';
    printf("Received: %s", recvline);

    // Send commands
    sprintf(sendline, "STAT\r\n");
    send(sockfd, sendline, strlen(sendline), 0);
    numbytes = recv(sockfd, recvline, MAXLINE, 0);
    recvline[numbytes] = '\0';
    printf("Received: %s", recvline);

    sprintf(sendline, "LIST\r\n");
    send(sockfd, sendline, strlen(sendline), 0);
    numbytes = recv(sockfd, recvline, MAXLINE, 0);
    recvline[numbytes] = '\0';
    printf("Received: %s", recvline);

    // Close socket
    close(sockfd);

    return 0;
}