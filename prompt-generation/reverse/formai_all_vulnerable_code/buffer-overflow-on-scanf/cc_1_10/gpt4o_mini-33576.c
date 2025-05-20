//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void printBinary(int num, char *buffer) {
    for (int i = 31; i >= 0; i--) {
        buffer[i] = (num & 1) ? '1' : '0';
        num >>= 1;
    }
    buffer[32] = '\0';
}

void decimalToBinary(int decimal, char *binary) {
    for (int i = 31; i >= 0; i--) {
        binary[i] = (decimal & 1) ? '1' : '0';
        decimal >>= 1;
    }
    binary[32] = '\0';
}

void parseIP(char *ip, int *octets) {
    char *token = strtok(ip, ".");
    for (int i = 0; i < 4 && token != NULL; i++) {
        octets[i] = atoi(token);
        token = strtok(NULL, ".");
    }
}

void calculateSubnet(int *octets, int subnetMask) {
    int mask = 0xFFFFFFFF << (32 - subnetMask);
    int subnet[4];
    int wildcard[4];

    // Calculate subnet address
    int ipAsInt = (octets[0] << 24) | (octets[1] << 16) | (octets[2] << 8) | octets[3];
    int subnetAsInt = ipAsInt & mask;

    subnet[0] = (subnetAsInt >> 24) & 0xFF;
    subnet[1] = (subnetAsInt >> 16) & 0xFF;
    subnet[2] = (subnetAsInt >> 8) & 0xFF;
    subnet[3] = subnetAsInt & 0xFF;

    // Calculate wildcard mask
    for (int i = 0; i < 4; i++) {
        wildcard[i] = (mask >> (24 - (i * 8))) & 0xFF;
        wildcard[i] = 255 - wildcard[i];
    }

    printf("Subnet Address: %d.%d.%d.%d\n", subnet[0], subnet[1], subnet[2], subnet[3]);
    printf("Wildcard Mask: %d.%d.%d.%d\n", wildcard[0], wildcard[1], wildcard[2], wildcard[3]);
}

int main() {
    char ip[16];
    int subnetMask;
    int octets[4];

    // User input section
    printf("Enter IP address (a.b.c.d): ");
    fgets(ip, sizeof(ip), stdin);
    ip[strcspn(ip, "\n")] = '\0';  // Remove newline character

    printf("Enter Subnet Mask (CIDR notation e.g., 24): ");
    scanf("%d", &subnetMask);

    // Validate IP address
    parseIP(ip, octets);
    for (int i = 0; i < 4; i++) {
        if (octets[i] < 0 || octets[i] > 255) {
            fprintf(stderr, "Invalid IP address!\n");
            return EXIT_FAILURE;
        }
    }

    // Validate subnet mask
    if (subnetMask < 0 || subnetMask > 32) {
        fprintf(stderr, "Invalid Subnet Mask! Must be between 0 and 32.\n");
        return EXIT_FAILURE;
    }

    // Calculate subnet
    calculateSubnet(octets, subnetMask);

    // Display binary representations
    char binaryIP[33];
    char binarySubnetMask[33];
    
    decimalToBinary((octets[0] << 24) | (octets[1] << 16) | (octets[2] << 8) | octets[3], binaryIP);
    decimalToBinary(0xFFFFFFFF << (32 - subnetMask), binarySubnetMask);
    
    printf("Binary Representation of IP Address: %s\n", binaryIP);
    printf("Binary Representation of Subnet Mask: %s\n", binarySubnetMask);
    
    return EXIT_SUCCESS;
}