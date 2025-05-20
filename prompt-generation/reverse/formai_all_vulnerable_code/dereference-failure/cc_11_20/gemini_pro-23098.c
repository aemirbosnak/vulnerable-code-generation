//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFSIZE 4096

int main(int argc, char **argv) {
    int sfd, cfd, port;
    struct sockaddr_in saddr, caddr;
    char buf[BUFSIZE];
    int nread, nwritten;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    port = atoi(argv[1]);

    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sfd < 0) {
        perror("socket");
        return 1;
    }

    memset(&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = INADDR_ANY;
    saddr.sin_port = htons(port);

    if (bind(sfd, (struct sockaddr *)&saddr, sizeof(saddr)) < 0) {
        perror("bind");
        return 1;
    }

    if (listen(sfd, 5) < 0) {
        perror("listen");
        return 1;
    }

    for (;;) {
        cfd = accept(sfd, (struct sockaddr *)&caddr, (socklen_t *)sizeof(caddr));
        if (cfd < 0) {
            perror("accept");
            continue;
        }

        for (;;) {
            nread = read(cfd, buf, BUFSIZE);
            if (nread == 0) {
                break;
            } else if (nread < 0) {
                perror("read");
                break;
            }

            nwritten = write(cfd, buf, nread);
            if (nwritten < 0) {
                perror("write");
                break;
            }
        }

        close(cfd);
    }

    close(sfd);
    return 0;
}