#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

void print_ip(const char *ip) {
    struct in_addr addr;
    if (inet_pton(AF_INET, ip, &addr) <= 0) {
        fprintf(stderr, "Invalid IP address: %s\n", ip);
        exit(EXIT_FAILURE);
    }
    printf("%d.%d.%d.%d\n", addr.s_addr & 0xFF, (addr.s_addr >> 8) & 0xFF, (addr.s_addr >> 16) & 0xFF, (addr.s_addr >> 24) & 0xFF);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP> <subnet_mask>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct in_addr ip_addr, netmask, broadcast;
    if (inet_pton(AF_INET, argv[1], &ip_addr) <= 0 || inet_pton(AF_INET, argv[2], &netmask) <= 0) {
        fprintf(stderr, "Invalid IP address or subnet mask.\n");
        return EXIT_FAILURE;
    }

    broadcast.s_addr = ip_addr.s_addr | (~netmask.s_addr);

    printf("Subnet IP: ");
    print_ip(inet_ntoa(ip_addr));
    printf("Subnet Mask: ");
    print_ip(inet_ntoa(netmask));
    printf("Broadcast Address: ");
    print_ip(inet_ntoa(broadcast));

    return EXIT_SUCCESS;
}
