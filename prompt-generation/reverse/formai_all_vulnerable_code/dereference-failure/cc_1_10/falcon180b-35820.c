//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_HOSTS 1000
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int port_range_start = 1;
    int port_range_end = 65535;

    printf("Scanning ports on %s\n", ip_address);

    int max_fd = 0;
    struct sockaddr_in *hosts[MAX_HOSTS];
    int num_hosts = 0;

    for (int i = port_range_start; i <= port_range_end; i++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            printf("Error: %s\n", strerror(errno));
            continue;
        }

        struct sockaddr_in host;
        memset(&host, 0, sizeof(host));
        host.sin_family = AF_INET;
        host.sin_port = htons(i);

        inet_pton(AF_INET, ip_address, &host.sin_addr);

        if (connect(sock, (struct sockaddr *)&host, sizeof(host)) == -1) {
            if (errno == ECONNREFUSED) {
                printf("Port %d is closed\n", i);
            } else {
                printf("Port %d is filtered\n", i);
            }
            close(sock);
        } else {
            printf("Port %d is open\n", i);
            close(sock);
        }
    }

    return 0;
}