//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 110
#define MAXLINE 4096
#define MAX_EMAIL 256
#define MAX_FNAME 256
#define MAX_RCPT 256
#define MAX_ADDR 256

int main(int argc, char *argv[]) {
    char *host, *user, *pwd;
    char buf[MAXLINE], buf2[MAXLINE];
    int sockfd, len;
    struct sockaddr_in serv_addr;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <hostname> <username>\n", argv[0]);
        exit(0);
    }

    host = argv[1];
    user = argv[2];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error opening socket\n");
        exit(0);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, host, &serv_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid hostname\n");
        exit(0);
    }

    len = sizeof(serv_addr);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, len) < 0) {
        fprintf(stderr, "Error connecting\n");
        exit(0);
    }

    printf("Connected to %s:%d\n", host, PORT);
    printf("Please enter your password: ");
    fgets(buf, MAXLINE, stdin);

    if (buf[strlen(buf) - 1]!= '\n')
        buf[strlen(buf)] = '\0';

    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        fprintf(stderr, "Error sending password\n");
        exit(0);
    }

    printf("Logging in...\n");
    if (recv(sockfd, buf, MAXLINE, 0) < 0) {
        fprintf(stderr, "Error receiving login response\n");
        exit(0);
    }

    printf("Logged in as %s\n", buf);
    printf("Type 'quit' to exit\n");

    while (1) {
        if (recv(sockfd, buf, MAXLINE, 0) < 0) {
            fprintf(stderr, "Error receiving email headers\n");
            exit(0);
        }

        printf("%s\n", buf);
        if (strcmp(buf, "quit") == 0)
            break;
    }

    printf("Disconnected\n");
    close(sockfd);
    return 0;
}