//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int port_start = 1, port_end = 0;
    char *ip_address = "127.0.0.1";
    int sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int opt = 1;
    int addrlen = sizeof(client_addr);

    if (argc < 3) {
        printf("Usage: %s <start_port> <end_port> <IP_address>\n", argv[0]);
        exit(1);
    }

    port_start = atoi(argv[1]);
    port_end = atoi(argv[2]);
    ip_address = argv[3];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        printf("Error setting socket option\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_start);
    server_addr.sin_addr.s_addr = inet_addr(ip_address);

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    printf("Scanning ports %d - %d...\n", port_start, port_end);

    for (int i = port_start; i <= port_end; i++) {
        server_addr.sin_port = htons(i);

        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
            printf("Port %d is open\n", i);
        } else {
            printf("Port %d is closed\n", i);
        }
    }

    close(sock);
    return 0;
}