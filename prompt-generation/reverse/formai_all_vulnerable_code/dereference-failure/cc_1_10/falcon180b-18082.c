//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char buf[BUF_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <server> <port>\n", argv[0]);
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("socket() failed: %s\n", strerror(errno));
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &server.sin_addr) <= 0) {
        printf("inet_pton() failed: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("connect() failed: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    printf("Connected to %s:%d\n", argv[1], atoi(argv[2]));

    while (1) {
        memset(buf, 0, BUF_SIZE);
        if (recv(sock, buf, BUF_SIZE, 0) <= 0) {
            printf("recv() failed: %s\n", strerror(errno));
            break;
        }

        printf("Received: %s\n", buf);
    }

    close(sock);
    return 0;
}