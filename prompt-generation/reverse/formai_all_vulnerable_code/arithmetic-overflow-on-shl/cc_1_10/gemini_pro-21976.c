//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define LOG_2(x) ((sizeof(x) << 3) - __builtin_clz(x))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

typedef struct {
    unsigned int prefix;
    unsigned int mask;
    unsigned int broadcast;
    unsigned int network;
    unsigned int first_host;
    unsigned int last_host;
    unsigned int num_hosts;
} subnet_info;

int calculate_subnet_info(unsigned int ip_address, unsigned int prefix, subnet_info *info) {
    if (prefix > 32) {
        printf("Error: Prefix must be between 0 and 32\n");
        return -1;
    }

    info->prefix = prefix;
    info->mask = ~((1 << (32 - prefix)) - 1);
    info->broadcast = ip_address | ~info->mask;
    info->network = ip_address & info->mask;
    info->first_host = info->network + 1;
    info->last_host = info->broadcast - 1;
    info->num_hosts = (1 << (32 - prefix)) - 2;

    return 0;
}

void print_subnet_info(subnet_info *info) {
    printf("Prefix: %u\n", info->prefix);
    printf("Mask: %u\n", info->mask);
    printf("Broadcast: %u\n", info->broadcast);
    printf("Network: %u\n", info->network);
    printf("First host: %u\n", info->first_host);
    printf("Last host: %u\n", info->last_host);
    printf("Number of hosts: %u\n", info->num_hosts);
}

int main() {
    unsigned int ip_address, prefix;
    subnet_info info;

    printf("Enter IP address (in dotted decimal notation): ");
    scanf("%u", &ip_address);

    printf("Enter prefix: ");
    scanf("%u", &prefix);

    if (calculate_subnet_info(ip_address, prefix, &info) == 0) {
        printf("\nSubnet information:\n");
        print_subnet_info(&info);
    }

    return 0;
}