//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: shocked
/*
 *  unique_port_scanner.c
 *
 *  A simple port scanner written in C.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PORTS 1024

int main(int argc, char **argv) {
    int sock, i, port;
    struct sockaddr_in server;
    char *host, *port_str;

    if (argc != 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    host = argv[1];
    port_str = argv[2];

    port = atoi(port_str);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    if (inet_pton(AF_INET, host, &server.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    for (i = 0; i < MAX_PORTS; i++) {
        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
            printf("Port %d is open\n", port);
            break;
        }
        port++;
    }

    close(sock);

    return 0;
}