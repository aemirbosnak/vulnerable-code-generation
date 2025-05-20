//FormAI DATASET v1.0 Category: Port Scanner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_PORT 65535
#define MAX_BUFF_SIZE 1024

int main(int argc, char *argv[]) {
    struct addrinfo hints, *result, *rp;
    char host[NI_MAXHOST];
    char port[NI_MAXSERV];
    int server_socket, status, optval = 1;
    int start = 1, end = MAX_PORT;
    char response[MAX_BUFF_SIZE], *message;

    if (argc < 2 || argc > 4) {
        fprintf(stderr, "Usage: %s hostname [start_port] [end_port]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo(argv[1], NULL, &hints, &result)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }

    for (rp = result; rp != NULL; rp = rp->ai_next) {
        if ((server_socket = socket(rp -> ai_family, rp -> ai_socktype, rp -> ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &optval,
                       sizeof(optval))) {
            perror("setsockopt");
            continue;
        }

        if (bind(server_socket, rp->ai_addr, rp->ai_addrlen) == 0) {
            break;
        }

        close(server_socket);
    }

    if (rp == NULL) {
        fprintf(stderr, "Failed to bind socket\n");
        exit(EXIT_FAILURE);
    }

    if (getnameinfo(rp->ai_addr, rp->ai_addrlen, host, NI_MAXHOST,
                    port, NI_MAXSERV, NI_NUMERICSERV) == 0) {
        printf("Scanning ports %s to %d on %s (%s):\n", argc >= 4 ? argv[3] : "1",
               argc >= 3 ? argv[2] : "65535", argv[1], host);
    }

    if (argc >= 3) {
        start = atoi(argv[2]);
    }

    if (argc >= 4) {
        end = atoi(argv[3]);
    }

    for (int i = start; i <= end; i++) {
        if (connect(server_socket, rp->ai_addr, rp->ai_addrlen) == 0) {
            printf("Port %d: open\n", i);
        }

        sleep(1);
    }

    close(server_socket);
    freeaddrinfo(result);

    return 0;
}