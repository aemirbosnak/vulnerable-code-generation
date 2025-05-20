//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_HOSTS 254
#define MAX_SUBNETS 8

typedef struct {
    uint8_t ip[4];
    uint8_t subnet_mask[4];
    uint8_t network[4];
    uint8_t broadcast[4];
    uint32_t total_hosts;
} SubnetInfo;

void print_ip(uint8_t ip[4]) {
    printf("%d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
}

void calculate_subnet(SubnetInfo *subnet_info) {
    // Calculate network address
    for (int i = 0; i < 4; i++) {
        subnet_info->network[i] = subnet_info->ip[i] & subnet_info->subnet_mask[i];
    }

    // Calculate broadcast address
    for (int i = 0; i < 4; i++) {
        subnet_info->broadcast[i] = subnet_info->network[i] | ~subnet_info->subnet_mask[i];
    }

    // Total hosts calculation
    subnet_info->total_hosts = (1 << (32 - (subnet_info->subnet_mask[0] + subnet_info->subnet_mask[1] + subnet_info->subnet_mask[2] + subnet_info->subnet_mask[3] - 24))) - 2;
}

void get_subnet_mask(int cidr, uint8_t *subnet_mask) {
    for (int i = 0; i < 4; i++) {
        if (cidr >= 8) {
            subnet_mask[i] = 255;
            cidr -= 8;
        } else {
            subnet_mask[i] = 256 - (1 << (8 - cidr));
            cidr = 0;
        }
    }
}

void print_subnet_info(SubnetInfo *subnet_info) {
    printf("\nSubnet Information:\n");
    printf("IP Address: ");
    print_ip(subnet_info->ip);
    printf("\nSubnet Mask: ");
    print_ip(subnet_info->subnet_mask);
    printf("\nNetwork Address: ");
    print_ip(subnet_info->network);
    printf("\nBroadcast Address: ");
    print_ip(subnet_info->broadcast);
    printf("\nTotal Usable Hosts: %u\n", subnet_info->total_hosts);
}

int main() {
    SubnetInfo subnet_info;
    char input[20];
    int cidr;

    printf("Welcome to the Retro C Subnet Calculator!\n");
    printf("-----------------------------------------\n");
    
    // Input IP Address
    printf("Enter an IP Address (e.g., 192.168.1.1): ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%hhu.%hhu.%hhu.%hhu", &subnet_info.ip[0], &subnet_info.ip[1], &subnet_info.ip[2], &subnet_info.ip[3]);

    // Input CIDR notation
    printf("Enter CIDR notation (e.g., 24 for 255.255.255.0): ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &cidr);

    // Validate input values
    for (int i = 0; i < 4; i++) {
        if (subnet_info.ip[i] > 255) {
            printf("Invalid IP address entered!\n");
            return 1;
        }
    }
    if (cidr < 0 || cidr > 32) {
        printf("Invalid CIDR value! Must be between 0 and 32.\n");
        return 1;
    }

    // Calculate subnet mask
    get_subnet_mask(cidr, subnet_info.subnet_mask);

    // Calculate network and broadcast addresses and total hosts
    calculate_subnet(&subnet_info);

    // Display results
    print_subnet_info(&subnet_info);

    printf("-----------------------------------------\n");
    printf("Thank you for using the Retro C Subnet Calculator!\n");

    return 0;
}