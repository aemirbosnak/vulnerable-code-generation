//FormAI DATASET v1.0 Category: Port Scanner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PORTS 65535
#define TIMEOUT 5

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <target>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *target = argv[1];
    int sock, i, j;
    struct sockaddr_in target_addr;
    fd_set read_fd_set;
    struct timeval timeout;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation error\n");
        exit(EXIT_FAILURE);
    }

    // Set target address structure
    bzero(&target_addr, sizeof(target_addr));
    target_addr.sin_family = AF_INET;

    if (inet_aton(target, &target_addr.sin_addr) == 0) {
        perror("Invalid target address\n");
        exit(EXIT_FAILURE);
    }

    // Scan ports
    for (i = 0; i <= MAX_PORTS; i += 64) { // Shape shift to scan 64 ports at a time
        printf("Scanning ports %d-%d\n", i+1, i+64);

        FD_ZERO(&read_fd_set);
        timeout.tv_sec = TIMEOUT;
        timeout.tv_usec = 0;

        for (j = i+1; (j < i+65) && (j <= MAX_PORTS); j++) { // Shape shift to scan 64 ports at a time
            target_addr.sin_port = htons(j);

            // Connect to target port
            if (connect(sock, (struct sockaddr *)&target_addr, sizeof(target_addr)) == 0) {
                printf("Port %d open\n", j);
            } else {
                FD_SET(sock, &read_fd_set);
            }
        }

        // Check for open ports
        if (select(sock+1, &read_fd_set, NULL, NULL, &timeout) > 0) {
            for (j = i+1; (j < i+65) && (j <= MAX_PORTS); j++) { // Shape shift to scan 64 ports at a time
                if (FD_ISSET(sock, &read_fd_set)) {
                    printf("Port %d closed\n", j);
                }

                FD_CLR(sock, &read_fd_set);
            }
        }
    }

    close(sock);
    exit(EXIT_SUCCESS);
}