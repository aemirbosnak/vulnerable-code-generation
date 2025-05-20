//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    struct sockaddr_in target;
    int sock, res, port;
    char ip[16];
    char buffer[BUFFER_SIZE];
    int num_ports;

    if (argc!= 3) {
        printf("Usage:./port_scanner <IP Address> <Number of Ports>\n");
        exit(1);
    }

    strcpy(ip, argv[1]);
    num_ports = atoi(argv[2]);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    printf("Scanning %d ports on %s...\n", num_ports, ip);

    for (port = 1; port <= num_ports; port++) {
        target.sin_family = AF_INET;
        target.sin_port = htons(port);
        target.sin_addr.s_addr = inet_addr(ip);

        res = connect(sock, (struct sockaddr *)&target, sizeof(target));

        if (res == 0) {
            printf("Port %d is open\n", port);
        } else if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", port);
        } else {
            printf("Error scanning port %d\n", port);
        }
    }

    close(sock);

    return 0;
}