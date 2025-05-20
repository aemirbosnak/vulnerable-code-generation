//FormAI DATASET v1.0 Category: Port Scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TIMEOUT_MS 500

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <target IP> <port range>\n", argv[0]);
        return 0;
    }

    char* targetIP = argv[1];
    char* portRange = argv[2];

    printf("Scanning %s...\n", targetIP);

    struct sockaddr_in targetAddr;
    targetAddr.sin_family = AF_INET;
    targetAddr.sin_addr.s_addr = inet_addr(targetIP);

    int startPort, endPort;
    sscanf(portRange, "%d-%d", &startPort, &endPort);

    for (int port = startPort; port <= endPort; port++) {
        targetAddr.sin_port = htons(port);

        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("socket creation failed");
            return 0;
        }

        // Set timeout for connect() call
        struct timeval timeout;
        timeout.tv_sec = TIMEOUT_MS / 1000;
        timeout.tv_usec = (TIMEOUT_MS % 1000) * 1000;
        setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout));
        
        if (connect(sock, (struct sockaddr *)&targetAddr, sizeof(targetAddr)) < 0) {
            close(sock);
            continue;
        }

        printf("Port %d is open\n", port);
        close(sock);
    }

    printf("Scan complete\n");
    return 0;
}