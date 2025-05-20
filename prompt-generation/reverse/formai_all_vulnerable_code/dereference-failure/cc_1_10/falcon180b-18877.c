//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

void die(const char *s) {
    perror(s);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s host port [timeout]\n", argv[0]);
        exit(1);
    }

    char *host = argv[1];
    char *port = argv[2];
    int timeout = 5;
    if (argc == 4) {
        timeout = atoi(argv[3]);
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        die("socket");
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(port));
    if (inet_pton(AF_INET, host, &serv_addr.sin_addr) <= 0) {
        die("inet_pton");
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        close(sock);
        if (errno == ECONNREFUSED) {
            printf("Port %s is closed\n", port);
        } else if (errno == ETIMEDOUT) {
            printf("Connection timed out\n");
        } else {
            die("connect");
        }
        return 0;
    }

    close(sock);
    printf("Port %s is open\n", port);
    return 0;
}