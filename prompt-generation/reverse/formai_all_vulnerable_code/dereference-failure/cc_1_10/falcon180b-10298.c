//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void scan_ports(int host, int start_port, int end_port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(start_port);
    server.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr *)host));

    int max_sd = socket(AF_INET, SOCK_STREAM, 0);
    if (max_sd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    for (int port = start_port; port <= end_port; port++) {
        server.sin_port = htons(port);
        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
            printf("Port %d is open\n", port);
        } else {
            printf("Port %d is closed\n", port);
        }
    }

    close(sock);
    close(max_sd);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage:./port_scanner <host> <start_port> <end_port>\n");
        exit(1);
    }

    char *host = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port > end_port) {
        printf("Invalid port range\n");
        exit(1);
    }

    scan_ports(inet_addr(host), start_port, end_port);

    return 0;
}