//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define BUFSIZE 1024
#define SERVER "smtp.gmail.com"
#define PORT 587
#define USER "your_email@gmail.com"
#define PASS "your_password"

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[BUFSIZE];
    struct addrinfo hints, *servinfo, *p;
    char host[NI_MAXHOST];
    char service[NI_MAXSERV];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((n = getaddrinfo(SERVER, service, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(n));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket error");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("connect error");
            close(sockfd);
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "failed to connect\n");
        exit(1);
    }

    snprintf(buffer, BUFSIZE, "EHLO %s\r\n", USER);
    send(sockfd, buffer, strlen(buffer), 0);

    while (1) {
        n = recv(sockfd, buffer, BUFSIZE, 0);
        if (n <= 0) {
            break;
        }

        buffer[n] = '\0';
        printf("Received: %s", buffer);
    }

    close(sockfd);
    freeaddrinfo(servinfo);

    return 0;
}