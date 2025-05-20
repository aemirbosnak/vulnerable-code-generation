//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX 65535

void scan(int sock, int port) {
    struct sockaddr_in server;
    int addrlen = sizeof(server);

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = htonl(INADDR_ANY);

    if (connect(sock, (struct sockaddr *)&server, addrlen) == -1) {
        if (errno == ECONNREFUSED)
            printf("%d - Closed\n", port);
        else if (errno == ETIMEDOUT)
            printf("%d - Filtered\n", port);
        else
            printf("%d - Error: %s\n", port, strerror(errno));
    } else {
        printf("%d - Open\n", port);
        close(sock);
    }
}

int main() {
    int sock, port, val;
    char ip[16];

    printf("Enter IP Address: ");
    scanf("%s", ip);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    for (port = 1; port <= MAX; port++) {
        val = connect(sock, (struct sockaddr *)&(struct sockaddr_in) {
           .sin_family = AF_INET,
           .sin_port = htons(port),
           .sin_addr.s_addr = inet_addr(ip)
        }, sizeof(struct sockaddr_in));

        if (val == -1) {
            scan(sock, port);
        }
    }

    close(sock);
    return 0;
}