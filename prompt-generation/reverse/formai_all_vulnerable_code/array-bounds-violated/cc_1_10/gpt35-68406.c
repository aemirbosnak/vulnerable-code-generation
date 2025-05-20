//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_NO 21
#define MAXSIZE 1024

int open_socket(const char *hostname, const char *portname) {
    struct addrinfo hints, *res, *ressave;
    int sockfd, n;

    bzero(&hints, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((n = getaddrinfo(hostname, portname, &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo error for %s, %s: %s\n", hostname, portname, gai_strerror(n));
        exit(1);
    }

    ressave = res;

    do {
        sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

        if (sockfd < 0)
            continue;

        if (connect(sockfd, res->ai_addr, res->ai_addrlen) == 0)
            break;

        close(sockfd);
    } while ((res = res->ai_next) != NULL);

    if (res == NULL) {
        fprintf(stderr, "error: can't connect to %s:%s (%s)\n", hostname, portname, strerror(errno));
        exit(1);
    }

    freeaddrinfo(ressave);
    return sockfd;
}

void do_login(int sockfd, char *username, char *password) {
    char reply[MAXSIZE];
    char message[MAXSIZE];

    sprintf(message, "USER %s\r\n", username);
    send(sockfd, message, strlen(message), 0);
    recv(sockfd, reply, MAXSIZE, 0);

    if (reply[0] == '2') {
        sprintf(message, "PASS %s\r\n", password);
        send(sockfd, message, strlen(message), 0);
        recv(sockfd, reply, MAXSIZE, 0);
    } else {
        fprintf(stderr, "error: %s", reply + 4);
        exit(1);
    }

    printf("%s", reply);
}

void do_ftp(int sockfd) {
    char command[MAXSIZE];
    char reply[MAXSIZE];
    int n;

    for (;;) {
        printf("ftp> ");
        fflush(stdout);

        if (fgets(command, sizeof(command), stdin) == NULL)
            break;

        n = strlen(command);

        if (command[n - 1] == '\n') {
            command[n - 1] = 0;
            n--;
        }

        if (strcmp(command, "quit") == 0) {
            send(sockfd, command, strlen(command), 0);
            recv(sockfd, reply, MAXSIZE, 0);
            printf("%s", reply);
            break;
        }

        send(sockfd, command, strlen(command), 0);
        recv(sockfd, reply, MAXSIZE, 0);
        printf("%s", reply);
    }

    close(sockfd);
}

int main(int argc, char **argv) {
    int sockfd;

    if (argc != 4) {
        fprintf(stderr, "usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    sockfd = open_socket(argv[1], "21");
    do_login(sockfd, argv[2], argv[3]);
    do_ftp(sockfd);
}