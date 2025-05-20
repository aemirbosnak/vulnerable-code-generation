//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void subnet_calculator(char *ip_addr, int subnet_mask) {
    // First, let's convert the IP address to binary
    int ip_bin[32];
    char *token = strtok(ip_addr, ".");
    int i = 0;
    while (token != NULL) {
        ip_bin[i++] = atoi(token);
        token = strtok(NULL, ".");
    }
    // Now, let's convert the subnet mask to binary
    int subnet_bin[32];
    memset(subnet_bin, 0, sizeof(subnet_bin)); // Set all bits to 0
    for (i = 0; i < subnet_mask; i++) {
        subnet_bin[i] = 1; // Set subnet bits to 1
    }
    // Calculate the number of hosts in the subnet
    int num_hosts = 1; // Set to 1 to account for the network address
    int num_zeros = 0; // Count the number of trailing zeros in the subnet mask
    for (i = 31; i >= 0; i--) {
        if (subnet_bin[i] == 0) {
            num_zeros++;
        } else {
            break;
        }
    }
    num_hosts = num_hosts << num_zeros; // Shift 1 to the left by num_zeros bits
    num_hosts -= 2; // Subtract 2 to exclude the network and broadcast addresses
    // Calculate the network address
    int network_addr[32];
    for (i = 0; i < 32; i++) {
        network_addr[i] = ip_bin[i] & subnet_bin[i];
    }
    // Calculate the broadcast address
    int broadcast_addr[32];
    memcpy(broadcast_addr, network_addr, sizeof(network_addr)); // Copy network address to broadcast address
    for (i = 31; i >= 32 - num_zeros; i--) {
        broadcast_addr[i] = 1; // Set broadcast bits to 1
    }
    // Print the results
    printf("\nIP Address: %s\n", ip_addr);
    printf("Subnet Mask: %d\n", subnet_mask);
    printf("Number of Hosts: %d\n", num_hosts);
    printf("Network Address: ");
    for (i = 0; i < 32; i += 8) {
        printf("%d.", (network_addr[i] << 7) + (network_addr[i+1] << 6) + (network_addr[i+2] << 5) + (network_addr[i+3] << 4) + (network_addr[i+4] << 3) + (network_addr[i+5] << 2) + (network_addr[i+6] << 1) + network_addr[i+7]);
    }
    printf("\n");
    printf("Broadcast Address: ");
    for (i = 0; i < 32; i += 8) {
        printf("%d.", (broadcast_addr[i] << 7) + (broadcast_addr[i+1] << 6) + (broadcast_addr[i+2] << 5) + (broadcast_addr[i+3] << 4) + (broadcast_addr[i+4] << 3) + (broadcast_addr[i+5] << 2) + (broadcast_addr[i+6] << 1) + broadcast_addr[i+7]);
    }
    printf("\n");
}

int main() {
    char ip_addr[16];
    int subnet_mask;
    printf("Enter IP address (e.g. 192.168.0.1): ");
    scanf("%s", ip_addr);
    printf("Enter subnet mask (e.g. 24): ");
    scanf("%d", &subnet_mask);
    subnet_calculator(ip_addr, subnet_mask);
    return 0;
}