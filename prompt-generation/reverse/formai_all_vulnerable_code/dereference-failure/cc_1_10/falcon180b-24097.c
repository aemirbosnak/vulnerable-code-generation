//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 1024
#define MAX_COMMAND 1024
#define POP3_PORT 110
#define USER "user"
#define PASS "password"

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char sendline[MAX_LINE], recvline[MAX_LINE];
    char user[MAX_LINE], pass[MAX_LINE];

    if (argc!= 4) {
        fprintf(stderr, "Usage: %s hostname username password\n", argv[0]);
        exit(1);
    }

    strcpy(user, argv[2]);
    strcpy(pass, argv[3]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: socket() failed\n");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(POP3_PORT);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        fprintf(stderr, "Error: inet_pton() failed\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        fprintf(stderr, "Error: connect() failed\n");
        exit(1);
    }

    fprintf(stdout, "Connected to %s:%d\n", argv[1], POP3_PORT);

    sprintf(sendline, "USER %s\r\n", user);
    send(sockfd, sendline, strlen(sendline), 0);

    n = recv(sockfd, recvline, MAX_LINE, 0);
    if (n <= 0) {
        fprintf(stderr, "Error: recv() failed\n");
        exit(1);
    }

    fprintf(stdout, "Received: %s", recvline);

    sprintf(sendline, "PASS %s\r\n", pass);
    send(sockfd, sendline, strlen(sendline), 0);

    n = recv(sockfd, recvline, MAX_LINE, 0);
    if (n <= 0) {
        fprintf(stderr, "Error: recv() failed\n");
        exit(1);
    }

    fprintf(stdout, "Received: %s", recvline);

    close(sockfd);
    return 0;
}