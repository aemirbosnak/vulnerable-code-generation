//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_HOST 100
#define MAX_PORT 100
#define MAX_LINE 1000

struct host_port {
    char host[MAX_HOST];
    char port[MAX_PORT];
};

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
        exit(1);
    }

    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, file)!= NULL) {
        char *host, *port;
        struct host_port hp;

        if (sscanf(line, "%s:%s", hp.host, hp.port) == 2) {
            // Valid host:port format
            if (inet_pton(AF_INET, hp.host, &hp.host) == 1 &&
                inet_pton(AF_INET, hp.port, &hp.port) == 1) {
                // Valid IP address and port number
                printf("Valid host:port: %s:%s\n", hp.host, hp.port);
            } else {
                printf("Invalid host:port: %s:%s\n", hp.host, hp.port);
            }
        } else if (sscanf(line, "%[^:]%s", hp.host, hp.port) == 2) {
            // Valid host:port format with IPv6 address
            if (inet_pton(AF_INET6, hp.host, &hp.host) == 1 &&
                inet_pton(AF_INET, hp.port, &hp.port) == 1) {
                // Valid IPv6 address and port number
                printf("Valid host:port: %s:%s\n", hp.host, hp.port);
            } else {
                printf("Invalid host:port: %s:%s\n", hp.host, hp.port);
            }
        } else {
            printf("Invalid host:port: %s\n", line);
        }
    }

    fclose(file);
    return 0;
}