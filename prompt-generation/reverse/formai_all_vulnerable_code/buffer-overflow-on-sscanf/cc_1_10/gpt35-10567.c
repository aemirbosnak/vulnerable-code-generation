//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the Subnet Mask for the given IP Address and Subnet Mask Size
void calculateSubnetMask(char *ip_address, int subnet_mask_size) {
    int subnet_bits = 32 - subnet_mask_size; // Calculate the number of Subnet Bits
    int ip[4];
    int subnet_mask[4] = {0}; // Initialize the Subnet Mask to 0

    // Convert the IP Address from String to Integer Array
    sscanf(ip_address, "%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);

    // Calculate the Subnet Mask
    for (int i=0; i<subnet_mask_size; i++) {
        subnet_mask[i/8] |= (1 << (7 - (i % 8))); // Set the corresponding Bit to 1
    }

    // Print the IP Address, Subnet Mask and Network Address
    printf("\nIP Address: %s", ip_address);
    printf("\nSubnet Mask: %d.%d.%d.%d", subnet_mask[0], subnet_mask[1], subnet_mask[2], subnet_mask[3]);

    // Calculate the Network Address
    int network_address[4];
    for (int i=0; i<4; i++) {
        network_address[i] = ip[i] & subnet_mask[i];
    }

    // Print the Network Address
    printf("\nNetwork Address: %d.%d.%d.%d", network_address[0], network_address[1], network_address[2], network_address[3]);

    // Calculate the Broadcast Address
    int broadcast_address[4];
    for (int i=0; i<subnet_bits; i++) {
        broadcast_address[i/8] |= (1 << (7 - (i % 8))); // Set the corresponding Bit to 1
    }
    for (int i=0; i<4; i++) {
        broadcast_address[i] |= (~subnet_mask[i] & 0xFF);
    }

    // Print the Broadcast Address
    printf("\nBroadcast Address: %d.%d.%d.%d\n", broadcast_address[0], broadcast_address[1], broadcast_address[2], broadcast_address[3]);
}

int main() {
    char ip_address[16]; // Maximum length of an IP Address is 15
    int subnet_mask_size;

    // Get the IP Address and Subnet Mask Size from the User
    printf("Enter the IP Address: ");
    scanf("%s", ip_address);
    printf("Enter the Subnet Mask Size: ");
    scanf("%d", &subnet_mask_size);

    calculateSubnetMask(ip_address, subnet_mask_size); // Calculate and Print the Subnet Mask, Network Address and Broadcast Address
    return 0;
}