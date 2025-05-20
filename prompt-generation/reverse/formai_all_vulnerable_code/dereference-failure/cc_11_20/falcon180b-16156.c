//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct addrinfo hints, *servinfo, *p;
    char s[NI_MAXHOST];
    char c[NI_MAXSERV];
    int rv;
    int numbytes;
    char buffer[BUFFER_SIZE];

    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(argv[1], argv[2], &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if (p->ai_family!= AF_INET) {
            continue;
        }

        if ((sock = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            exit(1);
        }

        if (connect(sock, p->ai_addr, p->ai_addrlen) == -1) {
            close(sock);
            perror("connect");
            exit(1);
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "ftp: No address associated with hostname\n");
        exit(1);
    }

    if (getnameinfo(p->ai_addr, p->ai_addrlen, s, NI_MAXHOST, c, NI_MAXSERV, 0) == -1) {
        fprintf(stderr, "getnameinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    fprintf(stdout, "Connected to %s:%s\n", s, c);

    if (login(sock, argv[1], argv[2], argv[3]) == -1) {
        fprintf(stderr, "Login failed\n");
        exit(1);
    }

    while (1) {
        fprintf(stdout, "> ");
        fflush(stdout);

        if ((numbytes = read(0, buffer, BUFFER_SIZE)) == 0) {
            break;
        }

        if (write(sock, buffer, numbytes) == -1) {
            perror("write");
            exit(1);
        }

        if ((numbytes = read(sock, buffer, BUFFER_SIZE)) == 0) {
            fprintf(stdout, "Connection closed\n");
            break;
        }

        buffer[numbytes] = '\0';
        fprintf(stdout, "%s", buffer);
    }

    close(sock);

    return 0;
}