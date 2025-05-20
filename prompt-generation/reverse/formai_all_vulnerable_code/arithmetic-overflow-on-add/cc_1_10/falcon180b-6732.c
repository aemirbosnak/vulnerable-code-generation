//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535

void scan_ports(int sock, int target_ip, int start_port, int end_port) {
    int port;
    struct sockaddr_in target;
    target.sin_family = AF_INET;
    target.sin_port = htons(start_port);
    target.sin_addr.s_addr = htonl(target_ip);

    for (port = start_port; port <= end_port; port++) {
        if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
            printf("Port %d is open\n", port);
        } else {
            printf("Port %d is closed\n", port);
        }
        target.sin_port = htons(port + 1);
    }
}

int main() {
    int sock, target_ip, start_port, end_port;
    char ip_str[16];

    printf("Enter the target IP address: ");
    scanf("%s", ip_str);
    target_ip = inet_addr(ip_str);

    printf("Enter the starting port: ");
    scanf("%d", &start_port);

    printf("Enter the ending port: ");
    scanf("%d", &end_port);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    scan_ports(sock, target_ip, start_port, end_port);

    close(sock);
    return 0;
}