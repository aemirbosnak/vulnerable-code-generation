//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock = 0, target_port = 0, target_ip = 0;
    struct sockaddr_in target;
    char ip_address[16];
    char *target_hostname = argv[1];
    int num_ports = 0;

    printf("Enter the number of ports to scan: ");
    scanf("%d", &num_ports);

    if (num_ports > MAX_PORTS || num_ports <= 0) {
        printf("Invalid number of ports.\n");
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket.\n");
        return 1;
    }

    if (inet_pton(AF_INET, target_hostname, &target_ip) <= 0) {
        printf("Invalid target IP address.\n");
        return 1;
    }

    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_port = htons(0);
    target.sin_addr.s_addr = target_ip;

    for (int i = 0; i < num_ports; i++) {
        target_port = htons(i);
        if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
            printf("Port %d is open.\n", i);
        } else {
            printf("Port %d is closed.\n", i);
        }
    }

    close(sock);
    return 0;
}