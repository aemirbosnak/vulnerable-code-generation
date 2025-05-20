//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LENGTH 16
#define MAX_SUBNET_MASK_LENGTH 3

int main(void) {
    char ip_address[MAX_IP_LENGTH];
    char subnet_mask[MAX_SUBNET_MASK_LENGTH];
    int subnet_bits = 0;
    char *ip_token;
    char *subnet_token;
    int octets[4];
    int subnet_octets[4];
    int subnet_mask_value = 0;

    printf("Welcome to the Brave Subnet Calculator!\n");

    // Get the IP address from the user
    printf("Please enter the IP address: ");
    scanf("%s", ip_address);

    // Get the subnet mask from the user
    printf("Please enter the subnet mask (in CIDR notation): ");
    scanf("%s", subnet_mask);

    // Convert the subnet mask to its octet form
    subnet_bits = atoi(subnet_mask);
    memset(subnet_octets, 0, sizeof(subnet_octets));
    for (int i = 0; i < subnet_bits; i++) {
        if (i < 8) {
            subnet_octets[0] |= (1 << (7 - i));
        } else if (i < 16) {
            subnet_octets[1] |= (1 << (15 - i));
        } else if (i < 24) {
            subnet_octets[2] |= (1 << (23 - i));
        } else {
            subnet_octets[3] |= (1 << (31 - i));
        }
    }

    // Calculate the subnet mask value
    subnet_mask_value = (subnet_octets[0] << 24) | (subnet_octets[1] << 16) | (subnet_octets[2] << 8) | subnet_octets[3];

    // Tokenize the IP address string and convert each octet to an integer
    ip_token = strtok(ip_address, ".");
    int i = 0;
    while (ip_token != NULL && i < 4) {
        octets[i] = atoi(ip_token);
        i++;
        ip_token = strtok(NULL, ".");
    }

    // Calculate the network address
    int network_address = (octets[0] << 24) | (octets[1] << 16) | (octets[2] << 8) | octets[3];
    network_address &= subnet_mask_value;

    // Calculate the broadcast address
    int broadcast_address = network_address | ~subnet_mask_value;

    // Print out the results
    printf("\n");
    printf("IP Address:     %s\n", ip_address);
    printf("Subnet Mask:    %s\n", subnet_mask);
    printf("Network Address:%d.%d.%d.%d\n", (network_address >> 24) & 0xFF, (network_address >> 16) & 0xFF, (network_address >> 8) & 0xFF, network_address & 0xFF);
    printf("Broadcast Address:%d.%d.%d.%d\n", (broadcast_address >> 24) & 0xFF, (broadcast_address >> 16) & 0xFF, (broadcast_address >> 8) & 0xFF, broadcast_address & 0xFF);

    return 0;
}