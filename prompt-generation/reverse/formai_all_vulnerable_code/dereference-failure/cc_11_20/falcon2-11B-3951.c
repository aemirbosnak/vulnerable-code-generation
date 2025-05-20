//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 143
#define SERVER "imap.example.com"

int main() {
    int sockfd, n;
    struct sockaddr_in serveraddr;
    struct hostent *server;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket creation error");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(SERVER);
    if (server == NULL) {
        perror("host not found");
        exit(EXIT_FAILURE);
    }

    bzero((char *)&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr, server->h_length);
    serveraddr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("connecting to server failed");
        exit(EXIT_FAILURE);
    }

    char buf[1024];
    printf("IMAP client connected to %s\n", SERVER);

    n = send("LOGIN anonymous anonymous\r\n", 25, 0, sockfd);
    if (n == -1) {
        perror("Sending login command failed");
        exit(EXIT_FAILURE);
    }

    n = recv(sockfd, buf, 1024, 0);
    if (n == -1) {
        perror("Receiving welcome message failed");
        exit(EXIT_FAILURE);
    }
    printf("Server responded: %s\n", buf);

    n = send("LIST \"\" \"\"\r\n", 29, 0, sockfd);
    if (n == -1) {
        perror("Sending list command failed");
        exit(EXIT_FAILURE);
    }

    n = recv(sockfd, buf, 1024, 0);
    if (n == -1) {
        perror("Receiving list response failed");
        exit(EXIT_FAILURE);
    }
    printf("Server responded: %s\n", buf);

    char *mailbox = strtok(buf, " \t");
    int num_mailboxes = atoi(mailbox);
    for (int i = 0; i < num_mailboxes; i++) {
        mailbox = strtok(NULL, " \t");
        printf("Mailbox %s\n", mailbox);
    }

    n = send("SELECT INBOX\r\n", 16, 0, sockfd);
    if (n == -1) {
        perror("Sending select command failed");
        exit(EXIT_FAILURE);
    }

    n = recv(sockfd, buf, 1024, 0);
    if (n == -1) {
        perror("Receiving select response failed");
        exit(EXIT_FAILURE);
    }
    printf("Server responded: %s\n", buf);

    n = send("UID LATEST\r\n", 14, 0, sockfd);
    if (n == -1) {
        perror("Sending UID command failed");
        exit(EXIT_FAILURE);
    }

    n = recv(sockfd, buf, 1024, 0);
    if (n == -1) {
        perror("Receiving UID response failed");
        exit(EXIT_FAILURE);
    }
    printf("Server responded: %s\n", buf);

    n = send("UID 1\r\n", 8, 0, sockfd);
    if (n == -1) {
        perror("Sending UID command failed");
        exit(EXIT_FAILURE);
    }

    n = recv(sockfd, buf, 1024, 0);
    if (n == -1) {
        perror("Receiving message data failed");
        exit(EXIT_FAILURE);
    }
    printf("Message data: %s\n", buf);

    close(sockfd);
    return 0;
}