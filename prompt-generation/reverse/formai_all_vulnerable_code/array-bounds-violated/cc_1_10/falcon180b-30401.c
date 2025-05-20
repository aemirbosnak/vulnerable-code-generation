//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE 1024
#define PORT 110
#define USER "Romeo"
#define PASS "Juliet"

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    char recv_line[MAX_LINE];
    char send_line[MAX_LINE];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    sprintf(send_line, "USER %s\r\n", USER);
    send(sockfd, send_line, strlen(send_line), 0);

    while ((n = recv(sockfd, recv_line, MAX_LINE, 0)) > 0) {
        recv_line[n] = '\0';
        printf("%s", recv_line);
    }

    if (n == 0) {
        printf("Server closed connection\n");
        exit(1);
    } else {
        printf("Error receiving data\n");
        exit(1);
    }

    close(sockfd);
    return 0;
}