//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

void die(const char *s) {
    perror(s);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    int port;
    char host[NI_MAXHOST];
    char service[NI_MAXSERV];
    int rv;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s host port\n", argv[0]);
        return 1;
    }

    if (getaddrinfo(argv[1], argv[2], NULL, &rv)!= 0) {
        die("getaddrinfo");
    }

    if (rv == 0) {
        fprintf(stderr, "No address associated with hostname\n");
        return 1;
    }

    if (rv > 1) {
        fprintf(stderr, "Too many addresses associated with hostname\n");
        return 1;
    }

    strncpy(host, argv[1], NI_MAXHOST);
    strncpy(service, argv[2], NI_MAXSERV);

    for (port = 1; port < 65536; port++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);

        if (sock == -1) {
            if (errno!= EINTR) {
                die("socket");
            }
            continue;
        }

        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);

        if (inet_pton(AF_INET, host, &addr.sin_addr) <= 0) {
            close(sock);
            continue;
        }

        rv = connect(sock, (struct sockaddr *) &addr, sizeof(addr));

        if (rv!= -1 || errno!= ECONNREFUSED) {
            close(sock);
            continue;
        }

        printf("Port %d is open\n", port);
        close(sock);
    }

    return 0;
}