//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

void scan_network(const char *address, int port) {
    struct sockaddr_in server_addr;
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(sock_fd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if(inet_pton(AF_INET, address, &server_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    if(connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("No device found at %s:%d\n", address, port);
    } else {
        printf("Device found at %s:%d\n", address, port);
    }

    close(sock_fd);
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Please provide an IP address range to scan\n");
        exit(EXIT_FAILURE);
    }

    char base_address[16];
    int start, end;
    int i, j, k;

    sscanf(argv[1], "%[^.].%d-%d", base_address, &start, &end);

    for(i = start; i <= end; i++) {
        char address[16];
        sprintf(address, "%s.%d", base_address, i);
        for(j = 0; j <= 255; j++) {
            for(k = 0; k <= 255; k++) {
                char broadcast_address[16];
                sprintf(broadcast_address, "%s.%d.%d", address, j, k);
                scan_network(broadcast_address, PORT);
            }
        }
    }

    return 0;
}