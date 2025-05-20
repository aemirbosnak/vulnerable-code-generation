//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>

void clearScreen() {
    printf("\033[H\033[J");
}

void printBanner() {
    printf("=======================================\n");
    printf("         Subnet Calculator             \n");
    printf("=======================================\n");
}

void printSubnetInfo(const char *ip, const char *subnet_mask, const char *network, const char *broadcast, int hosts) {
    printf("IP Address:       %s\n", ip);
    printf("Subnet Mask:      %s\n", subnet_mask);
    printf("Network Address:  %s\n", network);
    printf("Broadcast Address: %s\n", broadcast);
    printf("Usable Hosts:     %d\n", hosts);
    printf("=======================================\n");
}

int calculateSubnet(const char *ip, const char *subnet_mask) {
    struct sockaddr_in ip_addr, mask_addr, network_addr, broadcast_addr;

    // Convert IP Address and Subnet Mask to binary form
    inet_pton(AF_INET, ip, &(ip_addr.sin_addr));
    inet_pton(AF_INET, subnet_mask, &(mask_addr.sin_addr));

    // Calculate network address
    network_addr.sin_addr.s_addr = ip_addr.sin_addr.s_addr & mask_addr.sin_addr.s_addr;

    // Calculate broadcast address
    broadcast_addr.sin_addr.s_addr = network_addr.sin_addr.s_addr | ~mask_addr.sin_addr.s_addr;

    // Calculate number of usable hosts
    int subnet_bits = 0;
    for (int i = 0; i < 32; i++) {
        if (!(mask_addr.sin_addr.s_addr & (1 << (31 - i)))) {
            subnet_bits++;
        }
    }
    int hosts = (1 << subnet_bits) - 2; // 2 addresses are reserved (network and broadcast)

    char network_str[INET_ADDRSTRLEN];
    char broadcast_str[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(network_addr.sin_addr), network_str, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &(broadcast_addr.sin_addr), broadcast_str, INET_ADDRSTRLEN);

    printSubnetInfo(ip, subnet_mask, network_str, broadcast_str, hosts);
    
    return 0;
}

int main() {
    char ip[INET_ADDRSTRLEN];
    char subnet_mask[INET_ADDRSTRLEN];

    clearScreen();
    printBanner();

    while (1) {
        printf("Enter IP Address (or 'exit' to quit): ");
        scanf("%s", ip);
        if (strcmp(ip, "exit") == 0) {
            printf("Exiting the Subnet Calculator. Peaceful coding!\n");
            break;
        }
        printf("Enter Subnet Mask: ");
        scanf("%s", subnet_mask);

        // Calculate and display the subnet information
        if (calculateSubnet(ip, subnet_mask) == -1) {
            printf("Error in calculating subnet. Please check your inputs.\n");
        }
    }

    return 0;
}