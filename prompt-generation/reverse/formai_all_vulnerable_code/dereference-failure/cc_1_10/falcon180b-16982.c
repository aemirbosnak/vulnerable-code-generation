//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    int opt = 1;
    int port;

    if (argc!= 3) {
        printf("Usage: %s <IP address> <port range>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket.\n");
        exit(1);
    }

    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        printf("Error setting SO_REUSEADDR.\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server.sin_addr);

    for (port = 1; port <= MAX_PORTS; port++) {
        if (port == atoi(argv[2]))
            continue;

        server.sin_port = htons(port);

        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
            printf("Port %d is open.\n", port);
            close(sock);
            exit(0);
        }
    }

    printf("All ports are closed.\n");
    close(sock);
    exit(0);
}