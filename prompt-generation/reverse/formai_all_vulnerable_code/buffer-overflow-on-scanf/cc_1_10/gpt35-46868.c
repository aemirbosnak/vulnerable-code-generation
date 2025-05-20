//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: excited
#include<stdio.h>

int main() {
    printf("Welcome to the C Subnet Calculator!\n");
    printf("Enter the IP address and the subnet mask to calculate the network address, broadcast address and number of hosts.\n");
    printf("IP address format: A.B.C.D (each between 0 and 255)\n");
    printf("Subnet mask format: A.B.C.D (each between 0 and 255)\n\n");

    // Declare variables
    int ip[4], mask[4];
    int network[4], broadcast[4];
    int num_hosts, num_bits;

    // Collect user input
    printf("Enter the IP address: ");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
    printf("Enter the subnet mask: ");
    scanf("%d.%d.%d.%d", &mask[0], &mask[1], &mask[2], &mask[3]);

    // Verify input
    for (int i = 0; i < 4; i++) {
        if (ip[i] < 0 || ip[i] > 255 || mask[i] < 0 || mask[i] > 255) {
            printf("Invalid input. Please enter values between 0 and 255.\n");
            return 0;
        }
    }

    // Calculate network and broadcast addresses
    for (int i = 0; i < 4; i++) {
        network[i] = ip[i] & mask[i];
        broadcast[i] = ip[i] | ~mask[i];
    }

    // Determine number of host bits
    num_bits = 0;
    for (int i = 0; i < 4; i++) {
        int quotient = mask[i], rem = 0;
        while (quotient) {
            rem += quotient & 1;
            quotient >>= 1;
        }
        num_bits += rem;
    }

    // Calculate number of hosts
    num_hosts = (1 << (32 - num_bits)) - 2;
    
    // Output results
    printf("\nNetwork address: %d.%d.%d.%d\n", network[0], network[1], network[2], network[3]);
    printf("Broadcast address: %d.%d.%d.%d\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);
    printf("Number of host bits: %d\n", num_bits);
    printf("Number of hosts: %d\n\n", num_hosts);

    printf("Wow! That was fantastic! The C Subnet Calculator is now ready for use.\n");

    return 0;
}