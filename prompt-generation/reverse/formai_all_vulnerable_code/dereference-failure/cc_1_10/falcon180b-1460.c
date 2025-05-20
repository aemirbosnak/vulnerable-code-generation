//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_HOST_LEN 1024
#define MAX_DATA_LEN 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s host port\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    char *port = argv[2];

    struct addrinfo hints, *servinfo, *p;
    int rv;
    int sd;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo(host, port, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sd);
            perror("connect");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "failed to connect\n");
        return 1;
    }

    char data[MAX_DATA_LEN];
    memset(data, 'A', MAX_DATA_LEN);

    if (send(sd, data, MAX_DATA_LEN, 0) == -1) {
        perror("send");
        close(sd);
        return 1;
    }

    char recv_data[MAX_DATA_LEN];
    memset(recv_data, 0, MAX_DATA_LEN);

    if (recv(sd, recv_data, MAX_DATA_LEN, 0) == -1) {
        perror("recv");
        close(sd);
        return 1;
    }

    printf("Received data:\n%s\n", recv_data);

    close(sd);

    return 0;
}