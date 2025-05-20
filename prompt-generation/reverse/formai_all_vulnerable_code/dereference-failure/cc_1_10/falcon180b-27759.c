//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOST_NAME 256
#define MAX_DATA_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct hostent *host;
    struct sockaddr_in addr;
    char hostname[MAX_HOST_NAME];
    char data[MAX_DATA_SIZE];
    int datalen;
    int res;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname [port]\n", argv[0]);
        exit(1);
    }

    strncpy(hostname, argv[1], MAX_HOST_NAME);
    hostname[MAX_HOST_NAME - 1] = '\0';

    if (argc > 2) {
        addr.sin_port = htons(atoi(argv[2]));
    } else {
        addr.sin_port = htons(7); // Echo port
    }

    if ((res = getaddrinfo(hostname, NULL, NULL, &addr))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(res));
        exit(1);
    }

    if ((sock = socket(addr.sin_family, SOCK_STREAM, 0)) == -1) {
        fprintf(stderr, "socket: %s\n", strerror(errno));
        exit(1);
    }

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        fprintf(stderr, "connect: %s\n", strerror(errno));
        exit(1);
    }

    fprintf(stdout, "Connected to %s:%d\n", hostname, ntohs(addr.sin_port));

    while (1) {
        fprintf(stdout, "Enter data to send (max %d bytes): ", MAX_DATA_SIZE);
        fgets(data, MAX_DATA_SIZE, stdin);
        datalen = strlen(data);

        if (send(sock, data, datalen, 0)!= datalen) {
            fprintf(stderr, "send: %s\n", strerror(errno));
            exit(1);
        }

        res = recv(sock, data, MAX_DATA_SIZE, 0);
        if (res <= 0) {
            fprintf(stdout, "Disconnected\n");
            break;
        }

        data[res] = '\0';
        fprintf(stdout, "Received: %s\n", data);
    }

    close(sock);
    exit(0);
}