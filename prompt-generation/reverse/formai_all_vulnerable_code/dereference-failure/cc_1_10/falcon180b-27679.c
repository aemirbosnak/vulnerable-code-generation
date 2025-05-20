//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define BUF_SIZE 1024
#define PORT 110
#define USER "apocalypse"
#define PASS "12345"

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct hostent *host = gethostbyname("localhost");

    if (host == NULL) {
        printf("Error getting host\n");
        exit(1);
    }

    struct sockaddr_in server;

    memset(&server, 0, sizeof(server));

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = *(unsigned long *) host->h_addr;

    if (connect(sockfd, (struct sockaddr *) &server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    char buffer[BUF_SIZE];

    snprintf(buffer, BUF_SIZE, "USER %s\r\n", USER);

    send(sockfd, buffer, strlen(buffer), 0);

    char response[BUF_SIZE];

    memset(response, 0, BUF_SIZE);

    if (recv(sockfd, response, BUF_SIZE, 0) == -1) {
        printf("Error receiving response\n");
        exit(1);
    }

    printf("Response: %s\n", response);

    snprintf(buffer, BUF_SIZE, "PASS %s\r\n", PASS);

    send(sockfd, buffer, strlen(buffer), 0);

    memset(response, 0, BUF_SIZE);

    if (recv(sockfd, response, BUF_SIZE, 0) == -1) {
        printf("Error receiving response\n");
        exit(1);
    }

    printf("Response: %s\n", response);

    close(sockfd);

    return 0;
}