//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535

// Function to check if a port is open
int is_port_open(int sock, int port) {
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
        close(sock);
        return 1;
    } else {
        close(sock);
        return 0;
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage:./portscanner <IP Address> <Port Range>\n");
        exit(1);
    }

    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port + MAX_PORTS;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    printf("Scanning ports from %d to %d on %s...\n", start_port, end_port, ip);

    for (int i = start_port; i <= end_port; i++) {
        if (is_port_open(sock, i)) {
            printf("Port %d is open\n", i);
        }
    }

    close(sock);
    return 0;
}