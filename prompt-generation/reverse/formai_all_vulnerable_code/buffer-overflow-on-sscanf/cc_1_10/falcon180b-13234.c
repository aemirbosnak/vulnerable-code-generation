//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if(argc!= 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        exit(1);
    }

    // Convert IP address from string to binary format
    struct in_addr ip;
    if(inet_pton(AF_INET, argv[1], &ip) <= 0) {
        printf("Invalid IP Address\n");
        exit(1);
    }

    // Convert port range from string to integers
    int start_port, end_port;
    if(sscanf(argv[2], "%d-%d", &start_port, &end_port)!= 2) {
        printf("Invalid Port Range\n");
        exit(1);
    }

    for(int port = start_port; port <= end_port; port++) {
        // Create socket
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if(sock == -1) {
            printf("Error creating socket: %s\n", strerror(errno));
            exit(1);
        }

        // Set socket options
        struct timeval timeout;
        timeout.tv_sec = 5;
        timeout.tv_usec = 0;
        setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));
        setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

        // Connect to remote host
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr = ip;

        if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
            if(errno == ECONNREFUSED) {
                printf("%d - Closed\n", port);
            } else if(errno == ECONNRESET) {
                printf("%d - Reset\n", port);
            } else {
                printf("%d - Error: %s\n", port, strerror(errno));
            }
        } else {
            printf("%d - Open\n", port);
            close(sock);
        }
    }

    return 0;
}