//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 512
#define MAX_RESPONSE_LENGTH 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo hints, *serverinfo, *p;
    char host[NI_MAXHOST];
    char port[NI_MAXSERV];
    int rv;
    char username[MAX_COMMAND_LENGTH];
    char password[MAX_COMMAND_LENGTH];

    printf("Enter POP3 server hostname: ");
    scanf("%s", host);

    printf("Enter POP3 server port number: ");
    scanf("%s", port);

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    rv = getaddrinfo(host, port, &hints, &serverinfo);

    if (rv!= 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (p = serverinfo; p!= NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);

        if (sockfd == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("connect");
            close(sockfd);
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "Could not connect to POP3 server\n");
        exit(1);
    }

    char command[MAX_COMMAND_LENGTH];
    sprintf(command, "USER %s", username);
    send(sockfd, command, strlen(command), 0);

    char response[MAX_RESPONSE_LENGTH];
    recv(sockfd, response, MAX_RESPONSE_LENGTH, 0);
    printf("Server response: %s\n", response);

    sprintf(command, "PASS %s", password);
    send(sockfd, command, strlen(command), 0);

    recv(sockfd, response, MAX_RESPONSE_LENGTH, 0);
    printf("Server response: %s\n", response);

    close(sockfd);
    freeaddrinfo(serverinfo);
    return 0;
}