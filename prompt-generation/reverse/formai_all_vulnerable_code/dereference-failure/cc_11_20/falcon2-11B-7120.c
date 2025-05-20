//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    struct addrinfo hints, *servinfo, *p;
    int rv, s, n;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if ((rv = getaddrinfo(NULL, argv[2], &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((s = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            continue;
        }

        if (connect(s, p->ai_addr, p->ai_addrlen) == -1) {
            close(s);
            continue;
        }

        break;
    }

    freeaddrinfo(servinfo);

    if (p == NULL) {
        fprintf(stderr, "Unable to connect\n");
        exit(1);
    }

    char message[256];
    int message_len = 0;

    while (1) {
        if (read(s, &message_len, sizeof(int)) == -1) {
            perror("read");
            close(s);
            exit(1);
        }

        if (message_len == 0) {
            break;
        }

        if (read(s, message, message_len) == -1) {
            perror("read");
            close(s);
            exit(1);
        }

        printf("%s\n", message);
    }

    close(s);
    return 0;
}