//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void print_usage() {
    printf("Usage: portscan <target> <port-range>\n");
    printf("Example: portscan 192.168.1.1 1-1000\n");
}

int main(int argc, char **argv) {
    if (argc != 3) {
        print_usage();
        return 1;
    }

    char *target = argv[1];
    char *port_range = argv[2];

    int start_port, end_port;
    if (sscanf(port_range, "%d-%d", &start_port, &end_port) != 2) {
        printf("Invalid port range: %s\n", port_range);
        return 1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(target);

    for (int i = start_port; i <= end_port; i++) {
        addr.sin_port = htons(i);

        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            perror("socket");
            continue;
        }

        int result = connect(sock, (struct sockaddr *)&addr, sizeof(addr));
        if (result == 0) {
            printf("Port %d is open\n", i);
        } else {
            printf("Port %d is closed\n", i);
        }

        close(sock);
    }

    return 0;
}