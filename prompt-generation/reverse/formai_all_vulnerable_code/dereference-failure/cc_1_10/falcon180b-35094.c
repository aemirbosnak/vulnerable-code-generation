//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOSTNAME_LEN 256
#define MAX_DATA_LEN 1024

int main(int argc, char *argv[]) {
    int sock;
    struct addrinfo hints, *result;
    char hostname[MAX_HOSTNAME_LEN];
    int port;
    char data[MAX_DATA_LEN];
    int datalen;
    int rv;

    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <hostname> <port> <data>\n", argv[0]);
        return 1;
    }

    strncpy(hostname, argv[1], MAX_HOSTNAME_LEN);
    port = atoi(argv[2]);
    strncpy(data, argv[3], MAX_DATA_LEN);
    datalen = strlen(data);

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    rv = getaddrinfo(hostname, NULL, &hints, &result);
    if (rv!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 2;
    }

    sock = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sock == -1) {
        fprintf(stderr, "socket: %s\n", strerror(errno));
        return 3;
    }

    rv = connect(sock, result->ai_addr, result->ai_addrlen);
    if (rv == -1) {
        fprintf(stderr, "connect: %s\n", strerror(errno));
        close(sock);
        return 4;
    }

    send(sock, data, datalen, 0);

    char buffer[MAX_DATA_LEN];
    int bytes_received = 0;

    while ((bytes_received = recv(sock, buffer, MAX_DATA_LEN, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    close(sock);

    return 0;
}