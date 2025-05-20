//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

// Function to scan ports
void scan_ports(int sock, char *ip, int num_ports) {
    int i;
    char *port_str;
    struct sockaddr_in target;

    for (i = 1; i <= num_ports; i++) {
        port_str = malloc(6);
        sprintf(port_str, "%d", i);
        target.sin_family = AF_INET;
        target.sin_port = htons(i);
        inet_pton(AF_INET, ip, &target.sin_addr);

        // Connect to the port
        if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
            printf("Port %s is open\n", port_str);
        } else {
            printf("Port %s is closed\n", port_str);
        }

        free(port_str);
    }
}

// Function to resolve IP address
struct sockaddr_in get_addr(char *ip) {
    struct sockaddr_in target;
    target.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &target.sin_addr);
    target.sin_port = htons(0);
    return target;
}

int main(int argc, char *argv[]) {
    int sock, num_ports;
    char *ip;

    if (argc < 3) {
        printf("Usage:./portscanner <IP address> <number of ports>\n");
        exit(1);
    }

    ip = argv[1];
    num_ports = atoi(argv[2]);

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    // Resolve IP address
    struct sockaddr_in target = get_addr(ip);

    // Scan ports
    scan_ports(sock, ip, num_ports);

    // Close socket
    close(sock);

    return 0;
}