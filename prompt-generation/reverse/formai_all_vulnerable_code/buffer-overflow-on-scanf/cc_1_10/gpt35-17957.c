//FormAI DATASET v1.0 Category: Port Scanner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Function to scan ports
int scan_port(const char *ip, int port) {
    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        return -1;
    }

    // Setup address structure
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(ip);
    address.sin_port = htons(port);

    // Connect to address
    int result = connect(sock, (struct sockaddr *)&address, sizeof(address));
    close(sock);
    return result;
}

int main() {
    char target_ip[16];
    printf("Enter IP address to scan for open ports: ");
    scanf("%s", target_ip);

    int port_min, port_max;
    printf("Enter range of ports to scan (min max): ");
    scanf("%d %d", &port_min, &port_max);

    printf("Scanning ports %d through %d on %s\n", port_min, port_max, target_ip);
    printf("===========================================\n");

    // Loop through ports and check for open ones
    for (int i = port_min; i <= port_max; i++) {
        if (scan_port(target_ip, i) == 0) {
            printf("Port %d: OPEN\n", i);
        } else {
            printf("Port %d: CLOSED\n", i);
        }
    }

    printf("===========================================\n");
    printf("Scan complete!\n");
    return 0;
}