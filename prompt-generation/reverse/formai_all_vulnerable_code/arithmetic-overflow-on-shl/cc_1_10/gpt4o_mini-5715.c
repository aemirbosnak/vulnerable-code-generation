//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void printBinary(int n) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
        if (i % 8 == 0) printf(" "); // space every 8 bits
    }
    printf("\n");
}

void printSubnetInfo(unsigned int ip, unsigned int subnetMask, int subnetBits) {
    printf("IP Address (Binary): ");
    printBinary(ip);
    printf("Subnet Mask (Binary): ");
    printBinary(subnetMask);
    
    unsigned int networkAddress = ip & subnetMask;
    printf("Network Address (Binary): ");
    printBinary(networkAddress);
    
    unsigned int broadcastAddress = networkAddress | ~subnetMask;
    printf("Broadcast Address (Binary): ");
    printBinary(broadcastAddress);
    
    int numberOfSubnets = pow(2, subnetBits);
    printf("Number of Subnets: %d\n", numberOfSubnets);
    
    unsigned int hostsPerSubnet = pow(2, 32 - subnetBits) - 2; // -2 for network and broadcast address
    printf("Hosts per Subnet: %u\n", hostsPerSubnet);
}

void calculateSubnet(char *ipStr, char *maskStr) {
    unsigned int ip = 0;
    unsigned int subnetMask = 0;
    int subnetBits = 0;
    
    // Parsing IP address
    char *token = strtok(ipStr, ".");
    for (int i = 3; i >= 0; i--) {
        if (token != NULL) {
            ip |= (atoi(token) << (i * 8));
            token = strtok(NULL, ".");
        }
    }
    
    // Parsing subnet mask
    token = strtok(maskStr, ".");
    for (int i = 3; i >= 0; i--) {
        if (token != NULL) {
            subnetMask |= (atoi(token) << (i * 8));
            token = strtok(NULL, ".");
        }
    }
    
    // Calculating number of subnet bits
    for (int i = 0; i < 32; i++) {
        if ((subnetMask >> i) & 1) {
            subnetBits++;
        } else {
            break;
        }
    }
    
    printSubnetInfo(ip, subnetMask, subnetBits);
}

int main() {
    char ipAddress[16];
    char subnetMask[16];
    
    printf("Enter IP Address (e.g. 192.168.1.1): ");
    fgets(ipAddress, sizeof(ipAddress), stdin);
    ipAddress[strcspn(ipAddress, "\n")] = 0; // Remove newline character
    
    printf("Enter Subnet Mask (e.g. 255.255.255.0): ");
    fgets(subnetMask, sizeof(subnetMask), stdin);
    subnetMask[strcspn(subnetMask, "\n")] = 0; // Remove newline character
    
    calculateSubnet(ipAddress, subnetMask);
    
    return 0;
}