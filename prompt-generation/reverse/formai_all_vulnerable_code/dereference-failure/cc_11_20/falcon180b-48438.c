//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
    int s, maxfd, ret, val, i, num_ports;
    fd_set master, readfds;
    char hostname[1024];
    struct sockaddr_in target;
    struct hostent *he;
    struct timeval timeout;

    if (argc!= 3) {
        printf("Usage: %s <hostname> <number of ports>\n", argv[0]);
        exit(1);
    }

    num_ports = atoi(argv[2]);

    if ((he = gethostbyname(argv[1])) == NULL) {
        printf("Error: Host not found.\n");
        exit(1);
    }

    if (he->h_addrtype!= AF_INET) {
        printf("Error: Host is not an IPv4 address.\n");
        exit(1);
    }

    memcpy(&target.sin_addr, he->h_addr, he->h_length);
    target.sin_family = AF_INET;
    target.sin_port = 0;

    if ((s = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error: Socket creation failed: %s\n", strerror(errno));
        exit(1);
    }

    if (connect(s, (struct sockaddr *)&target, sizeof(target)) == -1) {
        printf("Error: Connection failed: %s\n", strerror(errno));
        exit(1);
    }

    FD_ZERO(&master);
    FD_ZERO(&readfds);

    FD_SET(s, &master);
    maxfd = s;

    for (i = 1; i <= num_ports; i++) {
        target.sin_port = htons(i);

        if (connect(s, (struct sockaddr *)&target, sizeof(target))!= -1) {
            FD_SET(s, &readfds);
            if (s > maxfd) {
                maxfd = s;
            }
        }
    }

    timeout.tv_sec = 5;
    timeout.tv_usec = 0;

    ret = select(maxfd + 1, &readfds, NULL, NULL, &timeout);

    if (ret == -1) {
        printf("Error: Select failed: %s\n", strerror(errno));
        exit(1);
    }

    for (i = 1; i <= num_ports; i++) {
        if (FD_ISSET(i, &readfds)) {
            printf("Port %d is open.\n", i);
        } else {
            printf("Port %d is closed.\n", i);
        }
    }

    close(s);

    return 0;
}