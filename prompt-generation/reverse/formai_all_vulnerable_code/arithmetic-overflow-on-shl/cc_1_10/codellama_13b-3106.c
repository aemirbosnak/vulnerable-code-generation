//Code Llama-13B DATASET v1.0 Category: Subnet Calculator ; Style: portable
// C Subnet Calculator
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SUBNETS 16

// Subnet structure
typedef struct {
    int subnet;
    int mask;
    int available_ips;
} Subnet;

// Calculate subnet mask from number of subnets
int calculate_subnet_mask(int num_subnets) {
    int mask = 0;
    for (int i = 0; i < num_subnets; i++) {
        mask += (1 << (32 - i));
    }
    return mask;
}

// Calculate available IPs for a given subnet
int calculate_available_ips(int subnet, int mask) {
    return (1 << (32 - mask)) - 2;
}

// Calculate subnets for a given IP and mask
void calculate_subnets(int ip, int mask) {
    int num_subnets = 16;
    int subnet_mask = calculate_subnet_mask(num_subnets);
    int available_ips = calculate_available_ips(ip, subnet_mask);

    for (int i = 0; i < num_subnets; i++) {
        Subnet subnet = {
            .subnet = ip + (i * (1 << (32 - subnet_mask))),
            .mask = subnet_mask,
            .available_ips = available_ips
        };
        printf("Subnet %d: %d.%d.%d.%d/%d\n", i,
            (subnet.subnet >> 24) & 0xFF,
            (subnet.subnet >> 16) & 0xFF,
            (subnet.subnet >> 8) & 0xFF,
            subnet.subnet & 0xFF,
            subnet.mask);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    int ip = atoi(argv[1]);
    calculate_subnets(ip, 24);
    return 0;
}