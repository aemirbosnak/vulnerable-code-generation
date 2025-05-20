//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 993
#define MAXLINE 1024

int main(int argc, char *argv[]) {
    // Romeo and Juliet
    if (argc < 2) {
        printf("Usage: %s <server>\n", argv[0]);
        return 1;
    }

    char server[1024];
    strncpy(server, argv[1], sizeof(server));

    // IMAP client
    int sockfd, connfd;
    struct sockaddr_in serv_addr;
    struct hostent *serverHost;
    char buffer[MAXLINE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error in socket()");
        return 1;
    }

    serverHost = gethostbyname(server);
    if (serverHost == NULL) {
        fprintf(stderr, "Error, no such host\n");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)serverHost->h_addr, serverHost->h_length);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error in connect()");
        return 1;
    }

    printf("Connected to %s on port %d\n", server, PORT);

    // Send login command
    sprintf(buffer, "LOGIN %s\r\n", "romeo@example.com");
    if (send(connfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error in send()");
        return 1;
    }

    // Send password
    sprintf(buffer, "PASS %s\r\n", "secret");
    if (send(connfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error in send()");
        return 1;
    }

    // Get list of mailboxes
    sprintf(buffer, "LIST \"\"\r\n");
    if (send(connfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error in send()");
        return 1;
    }

    // Receive and print mailbox list
    int n;
    while ((n = recv(connfd, buffer, MAXLINE, 0)) > 0) {
        printf("%s", buffer);
        if (n < MAXLINE) {
            break;
        }
    }

    printf("\n");

    // Disconnect
    sprintf(buffer, "QUIT\r\n");
    if (send(connfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error in send()");
        return 1;
    }

    close(sockfd);
    close(connfd);

    return 0;
}