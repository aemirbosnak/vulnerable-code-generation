//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PORTS 65535

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip address> <port range>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *ip_address = argv[1];
    char *port_range = argv[2];

    int start_port, end_port;
    if (sscanf(port_range, "%d:%d", &start_port, &end_port) != 2) {
        fprintf(stderr, "Invalid port range: %s\n", port_range);
        return EXIT_FAILURE;
    }

    if (start_port < 0 || start_port > MAX_PORTS || end_port < 0 || end_port > MAX_PORTS || start_port > end_port) {
        fprintf(stderr, "Invalid port range: %s\n", port_range);
        return EXIT_FAILURE;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(start_port);
    addr.sin_addr.s_addr = inet_addr(ip_address);

    int i;
    for (i = start_port; i <= end_port; i++) {
        addr.sin_port = htons(i);

        if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
            printf("Port %d: OPEN\n", i);
        } else {
            printf("Port %d: CLOSED\n", i);
        }
    }

    close(sock);

    return EXIT_SUCCESS;
}