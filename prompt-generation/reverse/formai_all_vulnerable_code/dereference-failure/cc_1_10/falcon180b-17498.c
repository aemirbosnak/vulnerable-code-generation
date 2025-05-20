//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void scan_ports(char *hostname, int start_port, int end_port);

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <hostname> <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    scan_ports(hostname, start_port, end_port);

    return 0;
}

void scan_ports(char *hostname, int start_port, int end_port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(hostname, NULL, &hints, &res)!= 0) {
        printf("Error resolving hostname\n");
        exit(1);
    }

    struct sockaddr_in *addr = (struct sockaddr_in *) res->ai_addr;

    for (int port = start_port; port <= end_port; port++) {
        if (connect(sock, res->ai_addr, res->ai_addrlen) == 0) {
            printf("Port %d is open\n", port);
        } else {
            printf("Port %d is closed\n", port);
        }

        close(sock);
        sock = socket(AF_INET, SOCK_STREAM, 0);
    }

    freeaddrinfo(res);
    close(sock);
}