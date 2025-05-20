//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock, res;
    struct sockaddr_in target;
    int port = 1;
    char buffer[BUFFER_SIZE];
    int num_open_ports = 0;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    inet_pton(AF_INET, argv[1], &target.sin_addr);

    while (num_open_ports < MAX_PORTS) {
        res = connect(sock, (struct sockaddr *)&target, sizeof(target));
        if (res == -1) {
            if (errno == ECONNREFUSED) {
                printf("%d is closed\n", ntohs(target.sin_port));
            } else {
                fprintf(stderr, "Error connecting to port %d: %s\n", ntohs(target.sin_port), strerror(errno));
            }
        } else {
            printf("%d is open\n", ntohs(target.sin_port));
            close(sock);
        }
        target.sin_port = htons(++port);
        num_open_ports++;
    }

    return 0;
}