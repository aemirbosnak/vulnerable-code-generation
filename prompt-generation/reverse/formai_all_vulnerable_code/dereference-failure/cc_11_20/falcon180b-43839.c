//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netdb.h>

#define MAX_HOST_LEN 256
#define MAX_DATA_LEN 64
#define TRUE 1
#define FALSE 0
#define PORT 7
#define TIMEOUT 5

int main(int argc, char *argv[]) {
    char host[MAX_HOST_LEN];
    int sock, len, ret;
    struct sockaddr_in server;
    struct hostent *he;
    char data[MAX_DATA_LEN];
    int datalen;
    struct timeval tv;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    strncpy(host, argv[1], MAX_HOST_LEN);
    host[MAX_HOST_LEN - 1] = '\0';

    if ((he = gethostbyname(host)) == NULL) {
        fprintf(stderr, "gethostbyname error: %s\n", strerror(errno));
        exit(1);
    }

    if (he->h_addrtype!= AF_INET) {
        fprintf(stderr, "Invalid address type\n");
        exit(1);
    }

    memcpy(&server.sin_addr, he->h_addr, he->h_length);
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        fprintf(stderr, "socket error: %s\n", strerror(errno));
        exit(1);
    }

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        fprintf(stderr, "connect error: %s\n", strerror(errno));
        exit(1);
    }

    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    if (setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (char *)&tv, sizeof(tv)) == -1) {
        fprintf(stderr, "setsockopt error: %s\n", strerror(errno));
        exit(1);
    }

    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv)) == -1) {
        fprintf(stderr, "setsockopt error: %s\n", strerror(errno));
        exit(1);
    }

    if ((len = send(sock, "PING", strlen("PING"), 0)) == -1) {
        fprintf(stderr, "send error: %s\n", strerror(errno));
        exit(1);
    }

    memset(data, 0, MAX_DATA_LEN);
    datalen = recv(sock, data, MAX_DATA_LEN, 0);

    if (datalen <= 0) {
        fprintf(stderr, "recv error: %s\n", strerror(errno));
        exit(1);
    }

    if (strncmp(data, "PONG", strlen("PONG")) == 0) {
        printf("Ping successful\n");
    } else {
        printf("Ping failed\n");
    }

    close(sock);
    exit(0);
}