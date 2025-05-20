//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: realistic
// port_scanner.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_PORTS 1000

void scan_ports(const char *ip_addr, int port_range_start, int port_range_end) {
    int sock_fd;
    struct sockaddr_in addr;
    struct sockaddr_in remote_addr;
    socklen_t remote_addr_len = sizeof(remote_addr);
    char buf[1024];
    int port;

    // create a socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        perror("socket");
        exit(1);
    }

    // set up the server address
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port_range_start);
    addr.sin_addr.s_addr = inet_addr(ip_addr);

    // iterate through the port range
    for (port = port_range_start; port <= port_range_end; port++) {
        // set the server address
        addr.sin_port = htons(port);

        // connect to the server
        if (connect(sock_fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
            continue;
        }

        // read the response
        read(sock_fd, buf, 1024);
        printf("Port %d is open\n", port);

        // close the socket
        close(sock_fd);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <ip_addr> <port_range_start> <port_range_end>\n", argv[0]);
        return 1;
    }

    scan_ports(argv[1], atoi(argv[2]), atoi(argv[3]));

    return 0;
}