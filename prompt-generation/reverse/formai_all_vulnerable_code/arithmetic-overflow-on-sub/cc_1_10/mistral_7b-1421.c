//MISTRAL-7B DATASET v1.0 Category: Subnet Calculator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORKS 100
#define MAX_IPS 256

typedef struct {
    unsigned int network_address;
    unsigned int subnet_mask;
    unsigned int broadcast_address;
    unsigned int first_usable_ip;
    unsigned int last_usable_ip;
} SubnetInfo;

void calculate_subnet_info(unsigned int ip_address, unsigned int subnet_mask, SubnetInfo *subnet_info) {
    unsigned int network_address, broadcast_address;

    network_address = ip_address & subnet_mask;
    broadcast_address = network_address | ~(~0 << (32 - (int)log2(subnet_mask & 0xFFFF)));

    subnet_info->network_address = network_address;
    subnet_info->subnet_mask = subnet_mask;
    subnet_info->broadcast_address = broadcast_address;

    subnet_info->first_usable_ip = network_address + 1;
    subnet_info->last_usable_ip = broadcast_address - 1;
}

int main(int argc, char *argv[]) {
    unsigned int ip_address, subnet_mask;
    int i, j;
    char network_name[20], subnet_name[20];
    SubnetInfo subnet_infos[MAX_NETWORKS][MAX_IPS];

    if (argc != 3) {
        printf("Usage: %s <IP_ADDRESS> <SUBNET_MASK>\n", argv[0]);
        return 1;
    }

    sscanf(argv[1], "%u.%u.%u.%u", &ip_address, &ip_address, &ip_address, &ip_address);
    sscanf(argv[2], "%u.%u.%u.%u", &subnet_mask, &subnet_mask, &subnet_mask, &subnet_mask);

    for (i = 0; i < 256; i++) {
        calculate_subnet_info(ip_address | (i << 8), subnet_mask, &subnet_infos[0][i]);
        sprintf(network_name, "Subnet %d.%d.%d.%d", ip_address >> 24, (ip_address >> 16) & 0xFF, (ip_address >> 8) & 0xFF, ip_address & 0xFF);
        printf("\n%s:\n", network_name);
        for (j = 0; j < 256; j++) {
            printf("%d.%d.%d.%d -> Network Address: %d, Subnet Mask: %d, Broadcast Address: %d, First Usable IP: %d, Last Usable IP: %d\n",
                (ip_address >> 24) + i, (ip_address >> 16) + (j >> 3), (ip_address >> 8) + (j >> 1), i + 1,
                subnet_infos[0][j].network_address, subnet_infos[0][j].subnet_mask, subnet_infos[0][j].broadcast_address,
                subnet_infos[0][j].first_usable_ip, subnet_infos[0][j].last_usable_ip);
        }
    }

    return 0;
}