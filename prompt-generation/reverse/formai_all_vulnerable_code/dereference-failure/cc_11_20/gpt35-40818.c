//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    // check for correct usage
    if (argc != 4) {
        printf("Usage: %s hostname port username\n", argv[0]);
        return 1;
    }

    // retrieve arguments
    char *hostname = argv[1];
    int port = atoi(argv[2]);
    char *username = argv[3];

    // resolve hostname to IP address
    struct hostent *he = gethostbyname(hostname);
    if (!he) {
        printf("Error: could not resolve hostname %s\n", hostname);
        return 1;
    }
    char *ip = inet_ntoa(*(struct in_addr*)he->h_addr);

    // create socket and connect to server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: could not create socket\n");
        return 1;
    }
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);
    addr.sin_port = htons(port);
    if (connect(sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        printf("Error: could not connect to server\n");
        return 1;
    }

    // receive welcome message from server
    char buf[BUF_SIZE];
    if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
        printf("Error: could not receive message from server\n");
        return 1;
    }
    printf("%s\n", buf);

    // login
    sprintf(buf, "LOGIN %s\r\n", username);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        printf("Error: could not send message to server\n");
        return 1;
    }
    if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
        printf("Error: could not receive message from server\n");
        return 1;
    }
    printf("%s\n", buf);

    // select mailbox and retrieve message headers
    sprintf(buf, "SELECT INBOX\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        printf("Error: could not send message to server\n");
        return 1;
    }
    if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
        printf("Error: could not receive message from server\n");
        return 1;
    }
    printf("%s\n", buf);
    sprintf(buf, "FETCH 1:* BODY[HEADER.FIELDS (FROM SUBJECT DATE)]\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        printf("Error: could not send message to server\n");
        return 1;
    }
    while (1) {
        int bytes = recv(sockfd, buf, BUF_SIZE, 0);
        if (bytes < 0) {
            printf("Error: could not receive message from server\n");
            return 1;
        } else if (bytes == 0) {
            break;
        }
        buf[bytes] = '\0';
        printf("%s", buf);
    }

    // close socket
    close(sockfd);

    return 0;
}