//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 20

// Function to convert CIDR to subnet mask
void cidrToSubnetMask(int cidr, char *subnetMask) {
    int mask[4] = {0, 0, 0, 0};
    for (int i = 0; i < cidr; i++) {
        mask[i / 8] += (1 << (7 - (i % 8)));
    }
    sprintf(subnetMask, "%d.%d.%d.%d", mask[0], mask[1], mask[2], mask[3]);
}

// Function to calculate total and usable hosts
void calculateHosts(int cidr, int *totalHosts, int *usableHosts) {
    *totalHosts = pow(2, (32 - cidr));
    *usableHosts = *totalHosts - 2; // excluding network and broadcast addresses
}

// Function to print subnet information
void printSubnetInfo(int cidr) {
    char subnetMask[MAX_LENGTH];
    int totalHosts, usableHosts;

    cidrToSubnetMask(cidr, subnetMask);
    calculateHosts(cidr, &totalHosts, &usableHosts);

    printf("\nSubnet Information:\n");
    printf("-----------------------------------\n");
    printf("CIDR Notation: /%d\n", cidr);
    printf("Subnet Mask: %s\n", subnetMask);
    printf("Total Hosts: %d\n", totalHosts);
    printf("Usable Hosts: %d\n", usableHosts);
    printf("-----------------------------------\n");
}

int main() {
    int cidr;

    printf("Welcome to the C Subnet Calculator!\n");
    printf("This program will help you calculate subnet properties based on CIDR notation.\n\n");

    while (1) {
        printf("Enter CIDR notation (0-32) for subnet calculation (or -1 to exit): ");
        scanf("%d", &cidr);

        if (cidr == -1) {
            printf("Exiting the Subnet Calculator. Goodbye!\n");
            break;
        }

        if (cidr < 0 || cidr > 32) {
            printf("Invalid CIDR value. Please enter a value between 0 and 32.\n");
            continue;
        }

        // Call the function to print subnet info
        printSubnetInfo(cidr);
    }

    return 0;
}