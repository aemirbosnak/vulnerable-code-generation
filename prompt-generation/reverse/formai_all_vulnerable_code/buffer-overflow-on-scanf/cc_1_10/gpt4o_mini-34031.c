//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <arpa/inet.h>

#define MAX_SUBNETS 10
#define BUFFER_SIZE 256

typedef struct {
    char ip_address[16];
    char subnet_mask[16];
    char network_address[16];
    char broadcast_address[16];
    int total_hosts;
} SubnetInfo;

void *calculate_subnet(void *arg) {
    SubnetInfo *subnet_info = (SubnetInfo *)arg;
    struct in_addr ip_addr, mask_addr, network_addr, broadcast_addr;

    // Convert IP and mask to binary format
    inet_pton(AF_INET, subnet_info->ip_address, &ip_addr);
    inet_pton(AF_INET, subnet_info->subnet_mask, &mask_addr);
    
    // Calculate network address
    network_addr.s_addr = ip_addr.s_addr & mask_addr.s_addr;
    inet_ntop(AF_INET, &network_addr, subnet_info->network_address, sizeof(subnet_info->network_address));
    
    // Calculate broadcast address
    broadcast_addr.s_addr = network_addr.s_addr | ~mask_addr.s_addr;
    inet_ntop(AF_INET, &broadcast_addr, subnet_info->broadcast_address, sizeof(subnet_info->broadcast_address));

    // Calculate total hosts
    int mask_bits = 0;
    for (int i = 0; i < 32; i++) {
        if ((mask_addr.s_addr >> i) & 1) {
            mask_bits++;
        }
    }
    subnet_info->total_hosts = (1 << (32 - mask_bits)) - 2; // subtracting network and broadcast addresses

    return NULL;
}

int main() {
    pthread_t threads[MAX_SUBNETS];
    SubnetInfo subnets[MAX_SUBNETS];
    int i;

    for (i = 0; i < MAX_SUBNETS; i++) {
        printf("Enter IP address (xxxx.xxxx.xxxx.xxxx) for subnet %d: ", i + 1);
        scanf("%s", subnets[i].ip_address);
        printf("Enter Subnet Mask (xxxx.xxxx.xxxx.xxxx): ");
        scanf("%s", subnets[i].subnet_mask);

        // Initialize network and broadcast addresses
        memset(subnets[i].network_address, 0, sizeof(subnets[i].network_address));
        memset(subnets[i].broadcast_address, 0, sizeof(subnets[i].broadcast_address));

        // Create and launch thread for subnet calculation
        pthread_create(&threads[i], NULL, calculate_subnet, &subnets[i]);
    }

    // Waiting for all threads to finish
    for (i = 0; i < MAX_SUBNETS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Display the results
    printf("\nSubnet Calculations:\n");
    for (i = 0; i < MAX_SUBNETS; i++) {
        printf("Subnet %d:\n", i + 1);
        printf("  IP Address: %s\n", subnets[i].ip_address);
        printf("  Subnet Mask: %s\n", subnets[i].subnet_mask);
        printf("  Network Address: %s\n", subnets[i].network_address);
        printf("  Broadcast Address: %s\n", subnets[i].broadcast_address);
        printf("  Total Hosts: %d\n\n", subnets[i].total_hosts);
    }

    return 0;
}