//Falcon2-11B DATASET v1.0 Category: Subnet Calculator ; Style: satisfied
#include <stdio.h>

int main() {
    int ip[4], mask[4], octets[3], ip_octets[3], ip_octets_mask[3], subnet[3], subnet_mask[3];

    // Read the IP address and mask from the user
    printf("Enter the IP address: ");
    for (int i = 0; i < 4; i++) {
        scanf("%d", &ip[i]);
    }

    printf("Enter the mask bits: ");
    for (int i = 0; i < 4; i++) {
        scanf("%d", &mask[i]);
    }

    // Calculate the number of octets in the IP address and mask
    for (int i = 0; i < 4; i++) {
        octets[i] = ip[i] & mask[i];
    }

    // Convert the IP address to binary and calculate the subnet mask
    for (int i = 0; i < 4; i++) {
        ip_octets[i] = octets[i] * 8;
        ip_octets_mask[i] = mask[i] * 8;
    }

    // Calculate the subnet mask
    for (int i = 0; i < 3; i++) {
        subnet[i] = ip_octets[i] + ip_octets_mask[i];
    }

    // Print the results
    printf("IP Address: ");
    for (int i = 0; i < 4; i++) {
        printf("%d.", ip[i]);
    }
    printf("\n");

    printf("Mask Bits: ");
    for (int i = 0; i < 4; i++) {
        printf("%d.", mask[i]);
    }
    printf("\n");

    printf("Number of Octets: ");
    for (int i = 0; i < 3; i++) {
        printf("%d.", octets[i]);
    }
    printf("\n");

    printf("IP Octets: ");
    for (int i = 0; i < 3; i++) {
        printf("%d.", ip_octets[i]);
    }
    printf("\n");

    printf("IP Octets Mask: ");
    for (int i = 0; i < 3; i++) {
        printf("%d.", ip_octets_mask[i]);
    }
    printf("\n");

    printf("Subnet Mask: ");
    for (int i = 0; i < 3; i++) {
        printf("%d.", subnet[i]);
    }
    printf("\n");

    return 0;
}