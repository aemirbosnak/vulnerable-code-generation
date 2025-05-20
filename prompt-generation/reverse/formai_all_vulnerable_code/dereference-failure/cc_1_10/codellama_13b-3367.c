//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: inquisitive
// Port Scanner Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_PORTS 1000

void print_usage(char *progname) {
    printf("Usage: %s <ip_address> <port_range>\n", progname);
    printf("  ip_address: IP address to scan\n");
    printf("  port_range: port range to scan (e.g. 1-100)\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        print_usage(argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    char *port_range = argv[2];

    int port_start = atoi(strtok(port_range, "-"));
    int port_end = atoi(strtok(NULL, "-"));

    if (port_start > port_end) {
        printf("Invalid port range: %s\n", port_range);
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port_start);
    addr.sin_addr.s_addr = inet_addr(ip_address);

    for (int i = port_start; i <= port_end; i++) {
        if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
            printf("Port %d is open\n", i);
        }
        addr.sin_port = htons(i + 1);
    }

    close(sock);

    return 0;
}