//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_LEN 1024

int main(int argc, char *argv[]) {
    int sock;
    struct hostent *host;
    char buf[BUF_LEN];
    int len;
    int res;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "Host not found\n");
        exit(1);
    }

    res = connect(sock, (struct sockaddr *)host->h_addr, host->h_length);
    if (res == -1) {
        if (errno == ECONNREFUSED) {
            printf("Host is down\n");
        } else {
            perror("connect");
        }
        exit(1);
    }

    printf("Host is up\n");

    close(sock);
    return 0;
}