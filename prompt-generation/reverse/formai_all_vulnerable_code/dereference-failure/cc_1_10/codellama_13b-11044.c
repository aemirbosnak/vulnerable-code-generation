//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT_START 1024
#define PORT_END 65535

int main(int argc, char *argv[]) {
    int sock, n;
    struct sockaddr_in serv_addr;
    char buffer[256];
    char ip_addr[16];
    int port;

    if (argc != 3) {
        printf("Usage: %s <ip_address> <port_range>\n", argv[0]);
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        printf("Invalid IP address.\n");
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Socket creation failed.\n");
        return 1;
    }

    for (port = PORT_START; port <= PORT_END; port++) {
        serv_addr.sin_port = htons(port);
        if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
            printf("Port %d is closed.\n", port);
        } else {
            printf("Port %d is open.\n", port);
            close(sock);
        }
    }

    return 0;
}