//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_THREADS 1000
#define MAX_PORTS 65535

int is_valid_ip(const char *ip) {
    struct sockaddr_in sa;
    int ret = inet_pton(AF_INET, ip, &(sa.sin_addr));
    return ret!= 0;
}

void *scan_port(void *arg) {
    char *ip = (char *) arg;
    int port;
    int sock;
    struct sockaddr_in server;

    for (port = 1; port <= MAX_PORTS; port++) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            printf("Error creating socket: %s\n", strerror(errno));
            continue;
        }

        server.sin_family = AF_INET;
        server.sin_port = htons(port);
        inet_pton(AF_INET, ip, &server.sin_addr);

        if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
            if (errno == ECONNREFUSED) {
                printf("Port %d is closed\n", port);
            } else {
                printf("Error connecting to port %d: %s\n", port, strerror(errno));
            }
            close(sock);
            continue;
        }

        close(sock);
    }

    return NULL;
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    if (!is_valid_ip(argv[1])) {
        printf("Invalid IP address\n");
        return 1;
    }

    pthread_t threads[MAX_THREADS];
    int i;

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, scan_port, argv[1]);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}