//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LEN 16
#define MAX_MASK_LEN 5

typedef struct {
    unsigned long address;
    unsigned long mask;
    unsigned long network_address;
    unsigned long broadcast_address;
    unsigned long usable_hosts;
} subnet_info;

int get_ip_address(char *ip_address, unsigned long *address) {
    int octets[4];
    if (sscanf(ip_address, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]) != 4) {
        return -1;
    }

    for (int i = 0; i < 4; i++) {
        if (octets[i] < 0 || octets[i] > 255) {
            return -1;
        }
    }

    *address = (octets[0] << 24) | (octets[1] << 16) | (octets[2] << 8) | octets[3];
    return 0;
}

int get_subnet_mask(char *subnet_mask, unsigned long *mask) {
    int octets[4];
    if (sscanf(subnet_mask, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]) != 4) {
        return -1;
    }

    for (int i = 0; i < 4; i++) {
        if (octets[i] < 0 || octets[i] > 255) {
            return -1;
        }
    }

    *mask = (octets[0] << 24) | (octets[1] << 16) | (octets[2] << 8) | octets[3];
    return 0;
}

int calculate_subnet_info(subnet_info *info) {
    info->network_address = info->address & info->mask;
    info->broadcast_address = info->network_address | ~info->mask;
    info->usable_hosts = ~info->mask & 0xFFFFFFFF;
    return 0;
}

void print_subnet_info(subnet_info *info) {
    char ip_address[MAX_IP_LEN];
    char subnet_mask[MAX_MASK_LEN];

    sprintf(ip_address, "%lu.%lu.%lu.%lu", (info->address >> 24) & 0xFF, (info->address >> 16) & 0xFF, (info->address >> 8) & 0xFF, info->address & 0xFF);
    sprintf(subnet_mask, "%lu.%lu.%lu.%lu", (info->mask >> 24) & 0xFF, (info->mask >> 16) & 0xFF, (info->mask >> 8) & 0xFF, info->mask & 0xFF);

    printf("IP Address: %s\n", ip_address);
    printf("Subnet Mask: %s\n", subnet_mask);
    printf("Network Address: %lu.%lu.%lu.%lu\n", (info->network_address >> 24) & 0xFF, (info->network_address >> 16) & 0xFF, (info->network_address >> 8) & 0xFF, info->network_address & 0xFF);
    printf("Broadcast Address: %lu.%lu.%lu.%lu\n", (info->broadcast_address >> 24) & 0xFF, (info->broadcast_address >> 16) & 0xFF, (info->broadcast_address >> 8) & 0xFF, info->broadcast_address & 0xFF);
    printf("Usable Hosts: %lu\n", info->usable_hosts);
}

int main() {
    char ip_address[MAX_IP_LEN];
    char subnet_mask[MAX_MASK_LEN];
    subnet_info info;

    printf("Enter the IP address: ");
    scanf("%s", ip_address);

    printf("Enter the subnet mask: ");
    scanf("%s", subnet_mask);

    if (get_ip_address(ip_address, &info.address) != 0) {
        printf("Invalid IP address.\n");
        return -1;
    }

    if (get_subnet_mask(subnet_mask, &info.mask) != 0) {
        printf("Invalid subnet mask.\n");
        return -1;
    }

    if (calculate_subnet_info(&info) != 0) {
        printf("Error calculating subnet information.\n");
        return -1;
    }

    print_subnet_info(&info);

    return 0;
}