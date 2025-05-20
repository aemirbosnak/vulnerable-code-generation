//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LENGTH 15
#define MAX_SUBNET_LENGTH 2

// Function to perform bitwise AND operation on IP and Subnet
void calculateNetworkAddress(unsigned int *networkAddress, unsigned int *ip, unsigned int *subnet) {
    *networkAddress = (*ip) & (*subnet);
}

// Function to count number of set bits in Subnet to calculate number of available hosts
int countHosts(unsigned int *subnet) {
    int count = 0;
    while (*subnet) {
        count += (*subnet & 1);
        *subnet >>=1;
    }
    return (int)pow(2, (float)32 - count) - 2;
}

int main() {
    char ip[MAX_IP_LENGTH], subnet[MAX_SUBNET_LENGTH];
    unsigned int ipOctets[4], subnetOctet, subnetBits, subnetMask = 0;
    unsigned int networkAddress;

    printf("Enter IP Address: ");
    scanf("%s", ip);
    sscanf(ip, "%d.%d.%d.%d", &ipOctets[0], &ipOctets[1], &ipOctets[2], &ipOctets[3]);

    // Validate IP Address
    for (int i = 0; i < 4; i++) {
        if (ipOctets[i] < 0 || ipOctets[i] > 255) {
            printf("Invalid IP Address!\n");
            exit(0);
        }
    }

    printf("Enter Subnet (in CIDR notation): /");
    scanf("%d", &subnetBits);
    if (subnetBits < 0 || subnetBits > 32) {
        printf("Invalid Subnet!\n");
        exit(0);
    }

    // Calculate Subnet Mask
    for (int i = 0; i < 4; i++) {
        if (subnetBits >= 8) {
            subnetOctet = 255;
            subnetBits -= 8;
        } else if (subnetBits > 0) {
            subnetOctet = 255 << (8 - subnetBits);
            subnetBits = 0;
        } else {
            subnetOctet = 0;
        }
        subnetMask |= subnetOctet << ((3 - i) * 8);
    }

    // Calculate Network Address
    calculateNetworkAddress(&networkAddress, (unsigned int*)&ipOctets, &subnetMask);

    // Calculate Number of Available Hosts
    int numHosts = countHosts(&subnetMask);

    printf("\nIP Address: %s\n", ip);
    printf("Subnet Mask: %d.%d.%d.%d\n", (subnetMask & 0xFF000000) >> 24, (subnetMask & 0x00FF0000) >> 16, (subnetMask & 0x0000FF00) >> 8, (subnetMask & 0x000000FF));
    printf("Network Address: %d.%d.%d.%d\n", (networkAddress & 0xFF000000) >> 24, (networkAddress & 0x00FF0000) >> 16, (networkAddress & 0x0000FF00) >> 8, (networkAddress & 0x000000FF));
    printf("Number of Available Hosts: %d\n", numHosts);

    return 0;
}