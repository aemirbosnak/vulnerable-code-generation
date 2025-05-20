//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server;
    struct hostent *host;
    int port;
    char *ip;
    int opt = 1;
    int count = 0;
    int max_connections = 10;
    int *sockets = malloc(max_connections * sizeof(int));

    if (argc!= 3) {
        printf("Usage: %s <ip> <port>\n", argv[0]);
        exit(1);
    }

    ip = argv[1];
    port = atoi(argv[2]);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(1);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(1);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &server.sin_addr) <= 0) {
        if (host = gethostbyname(ip)) {
            memcpy(&server.sin_addr, host->h_addr, host->h_length);
        } else {
            printf("gethostbyname error for %s\n", ip);
            exit(1);
        }
    }

    printf("Scanning %s:%d...\n", ip, port);

    for (int i = 0; i < max_connections; i++) {
        if ((sockets[i] = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            perror("socket failed");
            exit(1);
        }

        if (connect(sockets[i], (struct sockaddr *)&server, sizeof(server))) {
            close(sockets[i]);
            continue;
        }

        count++;
        printf("Connection %d established.\n", count);
        close(sockets[i]);
    }

    return 0;
}