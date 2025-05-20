//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: recursive
#include <stdio.h>
#include <string.h>

typedef struct {
    unsigned int address;
    unsigned int subnet_mask;
    unsigned int wildcard_mask;
    unsigned int network_address;
    unsigned int broadcast_address;
    unsigned int host_min;
    unsigned int host_max;
    unsigned int num_hosts;
} subnet_info;

void calculate_subnet(subnet_info *info, unsigned int address, unsigned int subnet_mask) {
    info->address = address;
    info->subnet_mask = subnet_mask;
    info->wildcard_mask = ~subnet_mask;

    // Calculate network address
    info->network_address = address & subnet_mask;

    // Calculate broadcast address
    info->broadcast_address = info->network_address | ~info->wildcard_mask;

    // Calculate host min and max
    info->host_min = info->network_address + 1;
    info->host_max = info->broadcast_address - 1;

    // Calculate number of hosts
    info->num_hosts = (1 << (32 - bitcount(subnet_mask))) - 2;
}

int bitcount(unsigned int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

void print_subnet_info(subnet_info *info) {
    printf("Address: %u.%u.%u.%u\n",
        (info->address >> 24) & 0xFF,
        (info->address >> 16) & 0xFF,
        (info->address >> 8) & 0xFF,
        info->address & 0xFF);

    printf("Subnet mask: %u.%u.%u.%u\n",
        (info->subnet_mask >> 24) & 0xFF,
        (info->subnet_mask >> 16) & 0xFF,
        (info->subnet_mask >> 8) & 0xFF,
        info->subnet_mask & 0xFF);

    printf("Wildcard mask: %u.%u.%u.%u\n",
        (info->wildcard_mask >> 24) & 0xFF,
        (info->wildcard_mask >> 16) & 0xFF,
        (info->wildcard_mask >> 8) & 0xFF,
        info->wildcard_mask & 0xFF);

    printf("Network address: %u.%u.%u.%u\n",
        (info->network_address >> 24) & 0xFF,
        (info->network_address >> 16) & 0xFF,
        (info->network_address >> 8) & 0xFF,
        info->network_address & 0xFF);

    printf("Broadcast address: %u.%u.%u.%u\n",
        (info->broadcast_address >> 24) & 0xFF,
        (info->broadcast_address >> 16) & 0xFF,
        (info->broadcast_address >> 8) & 0xFF,
        info->broadcast_address & 0xFF);

    printf("Host min: %u.%u.%u.%u\n",
        (info->host_min >> 24) & 0xFF,
        (info->host_min >> 16) & 0xFF,
        (info->host_min >> 8) & 0xFF,
        info->host_min & 0xFF);

    printf("Host max: %u.%u.%u.%u\n",
        (info->host_max >> 24) & 0xFF,
        (info->host_max >> 16) & 0xFF,
        (info->host_max >> 8) & 0xFF,
        info->host_max & 0xFF);

    printf("Number of hosts: %u\n", info->num_hosts);
}

int main() {
    unsigned int address, subnet_mask;
    subnet_info info;

    printf("Enter the IP address: ");
    scanf("%u", &address);

    printf("Enter the subnet mask: ");
    scanf("%u", &subnet_mask);

    calculate_subnet(&info, address, subnet_mask);
    print_subnet_info(&info);

    return 0;
}