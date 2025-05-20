//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT_RANGE 1024

void scan_ports(const char* hostname, int port_range) {
    struct hostent* host_info = gethostbyname(hostname);
    if (host_info == NULL) {
        printf("Error: Host not found.\n");
        return;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port_range);
    addr.sin_addr = *((struct in_addr*) host_info->h_addr_list[0]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error: Could not create socket.\n");
        return;
    }

    int result = connect(sock, (struct sockaddr*) &addr, sizeof(addr));
    if (result < 0) {
        printf("Error: Could not connect to host.\n");
        return;
    }

    printf("Connected to host %s on port %d.\n", hostname, port_range);

    close(sock);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    for (int i = 0; i < PORT_RANGE; i++) {
        scan_ports(argv[1], i);
    }

    return 0;
}