//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

// Function to calculate subnet mask
void calculate_subnet(int ip_address, int subnet_bits) {
    int i, j;
    int subnet_mask = 0;

    // Convert IP address to binary
    int binary_ip[4];
    for (i = 0; i < 4; i++) {
        binary_ip[i] = ip_address & 0xff;
        ip_address >>= 8;
    }

    // Set subnet mask bits
    for (i = 0; i < subnet_bits; i++) {
        subnet_mask |= (1 << i);
    }

    // Convert subnet mask to binary
    char subnet_binary[9];
    for (i = 0; i < 8; i++) {
        if (subnet_mask & 0x80) {
            subnet_binary[i] = '1';
        } else {
            subnet_binary[i] = '0';
        }
        subnet_mask <<= 1;
    }
    subnet_binary[8] = '\0';

    // Print results
    printf("IP address: %d.%d.%d.%d\n", binary_ip[0], binary_ip[1], binary_ip[2], binary_ip[3]);
    printf("Subnet mask: %s\n", subnet_binary);
}

int main() {
    int ip_address, subnet_bits;

    // Get user input
    printf("Enter IP address: ");
    scanf("%d.%d.%d.%d", &ip_address, &ip_address, &ip_address, &ip_address);
    printf("Enter subnet bits: ");
    scanf("%d", &subnet_bits);

    // Calculate subnet mask
    calculate_subnet(ip_address, subnet_bits);

    return 0;
}