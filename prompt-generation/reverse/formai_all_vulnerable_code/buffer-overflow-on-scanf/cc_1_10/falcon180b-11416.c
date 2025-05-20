//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void scan_port(int sock, int target_port) {
    struct sockaddr_in target;
    int opt = 1;
    int result;

    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_port = htons(target_port);
    target.sin_addr.s_addr = inet_addr("127.0.0.1");

    result = connect(sock, (struct sockaddr *)&target, sizeof(target));

    if (result == 0) {
        printf("Port %d is open.\n", target_port);
    } else {
        printf("Port %d is closed.\n", target_port);
    }

    close(sock);
}

int main() {
    int sock, result;
    int port_range[2];
    char ip_address[16];

    printf("Enter IP address: ");
    scanf("%s", ip_address);

    printf("Enter port range (start-end): ");
    scanf("%d-%d", &port_range[0], &port_range[1]);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        printf("Error creating socket.\n");
        exit(1);
    }

    for (int i = port_range[0]; i <= port_range[1]; i++) {
        scan_port(sock, i);
    }

    close(sock);

    return 0;
}