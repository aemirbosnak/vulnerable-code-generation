//FormAI DATASET v1.0 Category: Port Scanner ; Style: dynamic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

void printUsage() {
    printf("Usage: ./portscanner hostname/ip_address first_port_number last_port_number\n");
}

int main(int argc, char** argv) {
    if (argc < 4) {
        printUsage();
        return 0;
    }

    char* hostname = argv[1];
    int first_port = strtol(argv[2], NULL, 10);
    int last_port = strtol(argv[3], NULL, 10);

    struct hostent* host_info = NULL;
    struct sockaddr_in addr;
    int sock = -1;

    // resolve hostname to IP address
    host_info = gethostbyname(hostname);
    if (host_info == NULL) {
        printf("Error: hostname cannot be resolved\n");
        return 0;
    }
    memset(&addr, 0, sizeof(struct sockaddr_in));
    memcpy(&addr.sin_addr.s_addr, host_info->h_addr, host_info->h_length);

    // scan ports
    for (int port = first_port; port <= last_port; port++) {
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        sock = socket(AF_INET, SOCK_STREAM, 0);

        if (sock == -1) {
            printf("Error creating socket: %s\n", strerror(errno));
            return 0;
        }

        if (connect(sock, (struct sockaddr*) &addr, sizeof(addr)) == 0) {
            printf("%d: OPEN\n", port);
        } else {
            printf("%d: CLOSED\n", port);
        }

        close(sock);
    }

    return 0;
}