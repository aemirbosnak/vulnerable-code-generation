//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define POP3_PORT 110
#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <server> <user>\n", argv[0]);
        return 1;
    }

    char *server = argv[1];
    char *user = argv[2];


    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 2;
    }

    struct hostent *he = gethostbyname(server);
    if (he == NULL) {
        perror("gethostbyname");
        return 3;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(POP3_PORT);
    addr.sin_addr = *(struct in_addr *)he->h_addr_list[0];

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        return 4;
    }

    char line[MAX_LINE_LENGTH];

    // Receive the welcome message
    if (recv(sockfd, line, MAX_LINE_LENGTH, 0) == -1) {
        perror("recv");
        return 5;
    }

    printf("%s", line);

    // Send the user command
    snprintf(line, MAX_LINE_LENGTH, "USER %s\r\n", user);
    if (send(sockfd, line, strlen(line), 0) == -1) {
        perror("send");
        return 6;
    }

    // Receive the response
    if (recv(sockfd, line, MAX_LINE_LENGTH, 0) == -1) {
        perror("recv");
        return 7;
    }

    printf("%s", line);

    // Send the pass command
    snprintf(line, MAX_LINE_LENGTH, "PASS ********\r\n");
    if (send(sockfd, line, strlen(line), 0) == -1) {
        perror("send");
        return 8;
    }

    // Receive the response
    if (recv(sockfd, line, MAX_LINE_LENGTH, 0) == -1) {
        perror("recv");
        return 9;
    }

    printf("%s", line);

    // Send the stat command
    if (send(sockfd, "STAT\r\n", strlen("STAT\r\n"), 0) == -1) {
        perror("send");
        return 10;
    }

    // Receive the response
    if (recv(sockfd, line, MAX_LINE_LENGTH, 0) == -1) {
        perror("recv");
        return 11;
    }

    printf("%s", line);

    // Send the list command
    if (send(sockfd, "LIST\r\n", strlen("LIST\r\n"), 0) == -1) {
        perror("send");
        return 12;
    }

    // Receive the response
    while (1) {
        if (recv(sockfd, line, MAX_LINE_LENGTH, 0) == -1) {
            perror("recv");
            return 13;
        }

        printf("%s", line);

        if (strcmp(line, ".\r\n") == 0) {
            break;
        }
    }

    // Send the quit command
    if (send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0) == -1) {
        perror("send");
        return 14;
    }

    // Receive the response
    if (recv(sockfd, line, MAX_LINE_LENGTH, 0) == -1) {
        perror("recv");
        return 15;
    }

    printf("%s", line);

    close(sockfd);
    return 0;
}