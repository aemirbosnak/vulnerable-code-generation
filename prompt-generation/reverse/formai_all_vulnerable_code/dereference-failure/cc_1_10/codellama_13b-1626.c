//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: brave
/*
 * Brave Port Scanner Example Program
 *
 * Usage:
 *  ./port_scanner <target_ip> <start_port> <end_port>
 *
 *  target_ip: The IP address of the target to scan
 *  start_port: The first port to scan
 *  end_port: The last port to scan
 *
 * Example:
 *  ./port_scanner 192.168.1.1 1 1024
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: ./port_scanner <target_ip> <start_port> <end_port>\n");
        return 1;
    }

    char *target_ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 0 || start_port > 65535) {
        printf("Invalid start port\n");
        return 1;
    }

    if (end_port < 0 || end_port > 65535) {
        printf("Invalid end port\n");
        return 1;
    }

    if (start_port > end_port) {
        printf("Start port must be less than or equal to end port\n");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(start_port);
    inet_pton(AF_INET, target_ip, &addr.sin_addr);

    for (int port = start_port; port <= end_port; port++) {
        addr.sin_port = htons(port);

        if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
            printf("Port %d is open\n", port);
        } else {
            printf("Port %d is closed\n", port);
        }
    }

    close(sock);

    return 0;
}