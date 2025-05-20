//FormAI DATASET v1.0 Category: Port Scanner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define TIMEOUT_SEC 5

int main(int argc, char **argv) {
    if(argc < 3) {
        printf("Usage: %s <target_host> <start_port> <end_port>\n", argv[0]);
        exit(1);
    }

    char *target_host = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    if(inet_aton(target_host, &addr.sin_addr) == 0) {
        printf("Invalid IP address\n");
        exit(1);
    }

    // Check range of valid ports
    if(start_port < 1 || start_port > 65535 ||
            end_port < 1 || end_port > 65535 ||
            start_port > end_port) {
        printf("Invalid port range\n");
        exit(1);
    }

    printf("Scanning target: %s, ports: %d-%d\n", target_host, start_port, end_port);

    int i, sock, conn_sock, ret, enable = 1;
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT_SEC;
    timeout.tv_usec = 0;

    for(i = start_port; i <= end_port; i++) {
        sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if(sock < 0) {
            printf("Error creating socket\n");
            exit(1);
        }

        // Set socket options
        setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable));
        setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout));
        setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout));

        // Set destination address
        addr.sin_port = htons(i);

        // Connect to target
        ret = connect(sock, (struct sockaddr*)&addr, sizeof(addr));

        if(ret == 0) {
            printf("Port %d is open\n", i);
        }

        close(sock);
    }

    printf("Scan completed\n");

    return 0;
}