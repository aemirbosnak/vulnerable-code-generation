//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);
    struct addrinfo hints, *server;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    char host[NI_MAXHOST];
    char service[NI_MAXSERV];
    snprintf(service, sizeof(service), "%d", port);

    if (getaddrinfo(NULL, service, &hints, &server)!= 0) {
        error("getaddrinfo");
    }

    int sock = socket(server->ai_family, server->ai_socktype, server->ai_protocol);
    if (sock == -1) {
        error("socket");
    }

    if (connect(sock, server->ai_addr, server->ai_addrlen) == -1) {
        error("connect");
    }

    freeaddrinfo(server);

    char buf[MAX_LINE];
    while (fgets(buf, MAX_LINE, stdin)!= NULL) {
        send(sock, buf, strlen(buf), 0);
    }

    close(sock);

    return 0;
}