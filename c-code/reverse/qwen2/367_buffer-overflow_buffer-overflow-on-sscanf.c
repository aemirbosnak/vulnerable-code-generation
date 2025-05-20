#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

void print_broadcast_address(const char *ip, const char *subnet_mask) {
    struct in_addr ip_addr;
    struct in_addr subnet_addr;
    struct in_addr broadcast_addr;

    if (inet_pton(AF_INET, ip, &ip_addr) <= 0 || inet_pton(AF_INET, subnet_mask, &subnet_addr) <= 0) {
        fprintf(stderr, "Invalid IP address or subnet mask\n");
        return;
    }

    for (int i = 0; i < 4; ++i) {
        broadcast_addr.s_addr |= (ip_addr.s_addr & subnet_addr.s_addr) | (~subnet_addr.s_addr);
    }

    printf("Broadcast Address: %s\n", inet_ntoa(broadcast_addr));
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP address> <Subnet Mask>\n", argv[0]);
        return 1;
    }

    print_broadcast_address(argv[1], argv[2]);

    return 0;
}
