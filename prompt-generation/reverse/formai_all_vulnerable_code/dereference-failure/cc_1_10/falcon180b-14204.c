//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        exit(1);
    }

    char *ip = argv[1];
    struct in_addr in;
    if (inet_pton(AF_INET, ip, &in) <= 0) {
        printf("Invalid IP Address\n");
        exit(1);
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    struct hostent *host = gethostbyaddr((void *)&in, sizeof(in), AF_INET);
    if (host == NULL) {
        printf("Error resolving hostname\n");
        exit(1);
    }

    char hostname[BUFFER_SIZE];
    strncpy(hostname, host->h_name, BUFFER_SIZE);

    printf("Scanning %s...\n", hostname);

    for (int i = 1; i <= MAX_PORTS; i++) {
        int port = htons(i);
        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = port;
        addr.sin_addr.s_addr = in.s_addr;

        if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
            printf("Port %d is open\n", i);
        } else {
            printf("Port %d is closed\n", i);
        }
    }

    close(sock);
    return 0;
}