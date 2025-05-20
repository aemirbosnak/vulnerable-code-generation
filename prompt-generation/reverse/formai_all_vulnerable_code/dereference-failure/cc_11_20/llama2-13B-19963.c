//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024
#define MAX_HOST_LEN 100

struct host_info {
    int port;
    char host[MAX_HOST_LEN];
};

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    struct host_info *hosts = calloc(1, sizeof(struct host_info));
    if (!hosts) {
        perror("calloc() failed");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    for (i = 1; i < argc; i++) {
        if (inet_pton(AF_INET, argv[i], &hosts[i].host) <= 0) {
            perror("inet_pton() failed");
            exit(EXIT_FAILURE);
        }
        hosts[i].port = atoi(argv[i + 1]);
        if (hosts[i].port < 0 || hosts[i].port > 65535) {
            fprintf(stderr, "Invalid port number: %d\n", hosts[i].port);
            exit(EXIT_FAILURE);
        }
        i++;
    }

    for (i = 0; i < argc; i++) {
        if (connect(sock, (struct sockaddr *)&hosts[i].host, sizeof(hosts[i].host)) < 0) {
            perror("connect() failed");
            exit(EXIT_FAILURE);
        }
        if (send(sock, "Hello, world!", 13, 0) < 0) {
            perror("send() failed");
            exit(EXIT_FAILURE);
        }
        if (recv(sock, NULL, 0, 0) < 0) {
            perror("recv() failed");
            exit(EXIT_FAILURE);
        }
        close(sock);
    }

    free(hosts);
    return 0;
}