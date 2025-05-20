//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char ip_address[16]; // Stores the input IP address
    int subnet_mask; // Stores the input subnet mask
    int subnet_bits = 0; // Total number of subnet bits
    int host_bits = 0; // Total number of host bits
    int num_subnets = 0; // Total number of subnets
    int num_hosts = 0; // Total number of hosts

    printf("Enter IP Address: ");
    scanf("%s", ip_address);

    printf("Enter Subnet Mask: ");
    scanf("%d", &subnet_mask);

    // Validate subnet mask
    if(subnet_mask < 0 || subnet_mask > 32) {
        printf("\nInvalid Subnet Mask\n");
        exit(0);
    }

    // Calculate subnet bits
    for(int i = 0; i < subnet_mask; i++) {
        subnet_bits += 1 << (31 - i);
    }

    // Calculate host bits
    host_bits = 32 - subnet_mask;

    // Calculate number of subnets
    num_subnets = 1 << subnet_bits;

    // Calculate number of hosts
    num_hosts = 1 << host_bits;

    printf("\nIP Address: %s", ip_address);
    printf("\nSubnet Mask: %d", subnet_mask);
    printf("\nSubnet Bits: %d", subnet_bits);
    printf("\nHost Bits: %d", host_bits);
    printf("\nNumber of Subnets: %d", num_subnets);
    printf("\nNumber of Hosts per Subnet: %d", num_hosts);

    return 0;
}

/*
Sample Output:

Enter IP Address: 192.168.1.1
Enter Subnet Mask: 24

IP Address: 192.168.1.1
Subnet Mask: 24
Subnet Bits: 11111111111111111111111100000000
Host Bits: 8
Number of Subnets: 256
Number of Hosts per Subnet: 256
*/