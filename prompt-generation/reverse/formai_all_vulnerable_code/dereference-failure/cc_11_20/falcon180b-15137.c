//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    char *host;
    int port_range[2];
    int num_ports;
    int i;
    int sock;
    struct hostent *he;
    struct sockaddr_in addr;
    int opt = 1;
    char buf[BUF_SIZE];

    if (argc!= 4) {
        printf("Usage: %s <host> <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    host = argv[1];
    port_range[0] = atoi(argv[2]);
    port_range[1] = atoi(argv[3]);

    if (port_range[0] > port_range[1]) {
        printf("Invalid port range\n");
        return 1;
    }

    num_ports = port_range[1] - port_range[0] + 1;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        printf("Error setting socket option\n");
        close(sock);
        return 1;
    }

    he = gethostbyname(host);
    if (he == NULL) {
        printf("Error resolving host\n");
        close(sock);
        return 1;
    }

    memcpy(&addr.sin_addr, he->h_addr, he->h_length);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port_range[0]);

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        printf("Error connecting to host\n");
        close(sock);
        return 1;
    }

    for (i = 0; i < num_ports; i++) {
        addr.sin_port = htons(port_range[0] + i);
        if (send(sock, "", 0, 0) == -1) {
            if (errno!= ECONNRESET) {
                printf("Port %d is closed\n", port_range[0] + i);
            }
        } else {
            if (recv(sock, buf, BUF_SIZE, 0) > 0) {
                printf("Port %d is open\n", port_range[0] + i);
            } else {
                printf("Error receiving data on port %d\n", port_range[0] + i);
            }
        }
    }

    close(sock);

    return 0;
}