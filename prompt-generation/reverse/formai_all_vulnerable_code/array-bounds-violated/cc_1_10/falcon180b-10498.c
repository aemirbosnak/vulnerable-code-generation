//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

int main() {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    char s[NI_MAXSERV];
    int rv;
    int numbytes;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo("pop.gmail.com", "110", &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "failed to connect\n");
        exit(1);
    }

    printf("Connected to POP3 server.\n");

    char username[50] = "your_username";
    char password[50] = "your_password";
    char command[100];

    sprintf(command, "USER %s\r\n", username);
    send(sockfd, command, strlen(command), 0);

    numbytes = recv(sockfd, s, NI_MAXSERV, 0);
    s[numbytes] = '\0';
    printf("Received: %s\n", s);

    sprintf(command, "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);

    numbytes = recv(sockfd, s, NI_MAXSERV, 0);
    s[numbytes] = '\0';
    printf("Received: %s\n", s);

    close(sockfd);
    return 0;
}