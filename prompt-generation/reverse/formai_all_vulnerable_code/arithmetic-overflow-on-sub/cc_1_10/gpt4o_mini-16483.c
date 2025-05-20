//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_SUBNETS 100

typedef struct {
    char ip_address[16];
    char subnet_mask[16];
    char network_address[16];
    char broadcast_address[16];
    int total_hosts;
} SubnetInfo;

void calculate_subnet_info(SubnetInfo *subnet_info) {
    struct in_addr ip, mask, network, broadcast;
    int total_hosts;

    // Convert IP and subnet mask to binary form
    inet_pton(AF_INET, subnet_info->ip_address, &ip);
    inet_pton(AF_INET, subnet_info->subnet_mask, &mask);

    // Calculate network address (IP & Mask)
    network.s_addr = ip.s_addr & mask.s_addr;
    // Calculate broadcast address (Network | ~Mask)
    broadcast.s_addr = network.s_addr | ~mask.s_addr;

    // Store the calculated addresses
    inet_ntop(AF_INET, &network, subnet_info->network_address, sizeof(subnet_info->network_address));
    inet_ntop(AF_INET, &broadcast, subnet_info->broadcast_address, sizeof(subnet_info->broadcast_address));

    // Calculate total hosts (2^n - 2 where n is the number of bits for hosts)
    total_hosts = (1 << (32 - __builtin_popcount(mask.s_addr))) - 2;
    subnet_info->total_hosts = total_hosts > 0 ? total_hosts : 0;
}

void print_subnet_info(const SubnetInfo *subnet_info) {
    printf("IP Address: %s\n", subnet_info->ip_address);
    printf("Subnet Mask: %s\n", subnet_info->subnet_mask);
    printf("Network Address: %s\n", subnet_info->network_address);
    printf("Broadcast Address: %s\n", subnet_info->broadcast_address);
    printf("Total Usable Hosts: %d\n", subnet_info->total_hosts);
}

int main() {
    SubnetInfo subnets[MAX_SUBNETS];
    int subnet_count = 0;
    char continue_input;

    printf("Welcome to the C Subnet Calculator!\n");
    printf("Enter subnets in the format: <IP Address> <Subnet Mask>\n");

    while (1) {
        if (subnet_count >= MAX_SUBNETS) {
            printf("Maximum subnet limit reached. Exiting...\n");
            break;
        }

        printf("Enter subnet (or type 'exit' to finish): ");
        char input[64];
        fgets(input, sizeof(input), stdin);
        
        if (strncmp(input, "exit", 4) == 0) {
            break;
        }

        sscanf(input, "%s %s", subnets[subnet_count].ip_address, subnets[subnet_count].subnet_mask);
        calculate_subnet_info(&subnets[subnet_count]);
        print_subnet_info(&subnets[subnet_count]);
        subnet_count++;

        printf("Would you like to enter another subnet? (y/n): ");
        continue_input = getchar();
        getchar(); // Consume the newline character
        if (continue_input != 'y' && continue_input != 'Y') {
            break;
        }
    }

    printf("Thank you for using the C Subnet Calculator. Goodbye!\n");
    return 0;
}