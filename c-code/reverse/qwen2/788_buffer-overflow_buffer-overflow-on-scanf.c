#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    char ip[16];
    int subnet_mask;

    printf("Enter an IP address: ");
    scanf("%s", ip);

    printf("Enter a subnet mask (in CIDR notation): ");
    scanf("%d", &subnet_mask);

    // Calculate network address
    unsigned long ip_addr = inet_addr(ip);
    unsigned long net_addr = ip_addr & ((1 << (32 - subnet_mask)) - 1);

    // Print results
    printf("Network Address: %lu\n", net_addr);

    return 0;
}
