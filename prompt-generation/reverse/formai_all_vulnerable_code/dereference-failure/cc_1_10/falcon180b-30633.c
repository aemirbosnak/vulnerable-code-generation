//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>

bool scan_port(int sockfd, struct sockaddr *addr, int addrlen, int port) {
    int result = connect(sockfd, addr, addrlen);
    if (result == 0) {
        printf("Port %d is open!\n", port);
        close(sockfd);
        return true;
    } else if (errno == ECONNREFUSED) {
        printf("Port %d is closed.\n", port);
        close(sockfd);
        return false;
    } else {
        printf("Error: %s\n", strerror(errno));
        close(sockfd);
        return false;
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <IP address> <start port> <end port>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port > end_port) {
        printf("Invalid port range.\n");
        return 1;
    }

    printf("Scanning ports from %d to %d on %s...\n", start_port, end_port, ip);

    for (int port = start_port; port <= end_port; port++) {
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            printf("Error opening socket: %s\n", strerror(errno));
            return 1;
        }

        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        inet_pton(AF_INET, ip, &server_addr.sin_addr);

        if (scan_port(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr), port)) {
            printf("\n");
        }
    }

    return 0;
}