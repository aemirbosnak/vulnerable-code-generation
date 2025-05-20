//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: scalable
/*
 * C Port Scanner
 *
 * Author: [Your Name]
 * Date: [Date]
 *
 * Description: A scalable C program that scans a given IP address for open ports.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT_RANGE_MIN 1024
#define PORT_RANGE_MAX 65535
#define IP_ADDR_SIZE 16
#define SOCKET_TIMEOUT 5

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <ip_address>\n", argv[0]);
        return 1;
    }

    char ip_addr[IP_ADDR_SIZE];
    strcpy(ip_addr, argv[1]);

    for (int port = PORT_RANGE_MIN; port <= PORT_RANGE_MAX; port++) {
        struct sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        inet_pton(AF_INET, ip_addr, &server_addr.sin_addr);

        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("socket()");
            continue;
        }

        struct timeval timeout;
        timeout.tv_sec = SOCKET_TIMEOUT;
        timeout.tv_usec = 0;
        setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            close(sock);
            continue;
        }

        printf("Port %d is open\n", port);

        close(sock);
    }

    return 0;
}