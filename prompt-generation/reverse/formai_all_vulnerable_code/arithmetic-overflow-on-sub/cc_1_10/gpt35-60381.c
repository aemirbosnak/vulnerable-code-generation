//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char ip[20], subnet[20];
    int cidr, octet[4], mask[4];

    printf("Welcome to the Subnet Calculator Fun House!\n");
    printf("Our clowns will assist you in calculating subnet masks and host addresses.\n");

    // Get IP Address from user
    printf("\nFirst, please enter the IP Address: ");
    fgets(ip, 20, stdin);

    // Remove trailing newline character from user input
    strtok(ip, "\n");

    // Get Subnet Mask CIDR from user
    printf("\nNow, please enter the Subnet Mask CIDR: ");
    scanf("%d", &cidr);

    // Calculate subnet mask octets using CIDR notation
    int i;
    for(i = 0; i < 4; i++) {
        if(cidr >= 8) {
            mask[i] = 255;
            cidr -= 8;
        } else {
            mask[i] = 256 - (1 << (8 - cidr));
            cidr = 0;
        }
    }

    // Print subnet mask
    printf("\nThe Subnet Mask is: %d.%d.%d.%d\n", mask[0], mask[1], mask[2], mask[3]);

    // Convert IP Address string to array of integers
    sscanf(ip, "%d.%d.%d.%d", &octet[0], &octet[1], &octet[2], &octet[3]);

    // Calculate network address by ANDing IP Address and Subnet Mask
    int network[4];
    for(i = 0; i < 4; i++) {
        network[i] = octet[i] & mask[i];
    }

    // Print network address
    printf("\nThe Network Address is: %d.%d.%d.%d\n", network[0], network[1], network[2], network[3]);

    // Calculate broadcast address by ORing IP Address and inverted Subnet Mask
    int broadcast[4];
    for(i = 0; i < 4; i++) {
        broadcast[i] = octet[i] | (~mask[i] & 0xff);
    }

    // Print broadcast address
    printf("\nThe Broadcast Address is: %d.%d.%d.%d\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);

    // Calculate number of usable hosts by subtracting network and broadcast addresses
    int hosts = 1;
    for(i = 0; i < 4; i++) {
        hosts *= ((i == 3) ? 256 - mask[i] : mask[i] + 1);
    }
    hosts -= 2;

    // Print number of usable hosts
    printf("\nThe Number of Usable Hosts is: %d\n", hosts);

    printf("\nWe hope you enjoyed the Subnet Calculator Fun House!\n");
    printf("Come back soon for more subnetting fun!\n");

    return 0;
}