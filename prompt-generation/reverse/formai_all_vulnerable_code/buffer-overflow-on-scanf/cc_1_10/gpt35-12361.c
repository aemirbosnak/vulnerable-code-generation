//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 4096
#define SCAN_PORT 80

void check_error(int val, const char *msg) {
    if (val == -1) {
        perror(msg);
        exit(EXIT_FAILURE);
    }
}

void scan_network(const char *ip_start, const char *ip_end) {
    struct in_addr addr_start, addr_end;
    int count = 0;

    if (inet_aton(ip_start, &addr_start) == 0) {
        fprintf(stderr, "Invalid start IP address format.\n");
        return;
    }

    if (inet_aton(ip_end, &addr_end) == 0) {
        fprintf(stderr, "Invalid end IP address format.\n");
        return;
    }

    for (uint32_t i = ntohl(addr_start.s_addr); i <= ntohl(addr_end.s_addr); i++) {
        struct in_addr addr;
        addr.s_addr = htonl(i);

        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        check_error(sockfd, "Cannot create socket");

        struct sockaddr_in addr_in;
        memset(&addr_in, 0, sizeof(addr_in));
        addr_in.sin_family = AF_INET;
        addr_in.sin_addr = addr;
        addr_in.sin_port = htons(SCAN_PORT);

        if (connect(sockfd, (struct sockaddr *)&addr_in, sizeof(addr_in)) == 0) {
            count++;
            printf("Device %d: %s is available.\n", count, inet_ntoa(addr));
        }

        close(sockfd);
    }

    printf("Scan complete. Found %d devices on the network.\n", count);
}

int main() {
    char ip_start[16];
    char ip_end[16];

    printf("Welcome to the Wireless Network Scanner!\n");
    printf("Please enter the start IP address to scan: ");
    scanf("%s", ip_start);
    printf("Please enter the end IP address to scan: ");
    scanf("%s", ip_end);

    printf("Scanning network...\n");
    scan_network(ip_start, ip_end);

    return 0;
}