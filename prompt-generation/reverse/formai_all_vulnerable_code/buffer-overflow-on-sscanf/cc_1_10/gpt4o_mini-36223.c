//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printBinaryRepresentation(unsigned char octet) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (octet >> i) & 1);
    }
}

unsigned int calculateSubnetMask(int prefixLength) {
    return (0xFFFFFFFF << (32 - prefixLength)) & 0xFFFFFFFF;
}

void printSubnetInfo(unsigned int ip, unsigned int subnetMask) {
    unsigned int networkAddress = ip & subnetMask;
    unsigned int broadcastAddress = networkAddress | ~subnetMask;

    printf("Network Address: ");
    for (int i = 3; i >= 0; i--) {
        printf("%d", (networkAddress >> (i * 8)) & 0xFF);
        if (i != 0) {
            printf(".");
        }
    }
    printf("\n");

    printf("Broadcast Address: ");
    for (int i = 3; i >= 0; i--) {
        printf("%d", (broadcastAddress >> (i * 8)) & 0xFF);
        if (i != 0) {
            printf(".");
        }
    }
    printf("\n");
}

void calculateSubnet(int ip[4], int prefixLength) {
    unsigned int ipAddress = (ip[0] << 24) | (ip[1] << 16) | (ip[2] << 8) | ip[3];
    unsigned int subnetMask = calculateSubnetMask(prefixLength);

    printf("IP Address: ");
    for (int i = 3; i >= 0; i--) {
        printf("%d", ip[i]);
        if (i != 0) {
            printf(".");
        }
    }
    printf("\n");

    printf("Subnet Mask: ");
    for (int i = 3; i >= 0; i--) {
        printf("%d", (subnetMask >> (i * 8)) & 0xFF);
        if (i != 0) {
            printf(".");
        }
    }
    printf("\n");

    printSubnetInfo(ipAddress, subnetMask);
}

int main() {
    char input[30];
    int ip[4], prefixLength;

    printf("Welcome to the C Subnet Calculator!\n");
    printf("Please enter an IP address (format: x.x.x.x) followed by a subnet prefix length (e.g., /24):\n");

    fgets(input, sizeof(input), stdin);
    
    // Parse the input and separate IP and prefix length
    char *slashPosition = strchr(input, '/');
    if (slashPosition != NULL) {
        *slashPosition = '\0';
        prefixLength = atoi(slashPosition + 1);
    } else {
        printf("Invalid format. Please use x.x.x.x/prefixLength.\n");
        return 1;
    }

    if (sscanf(input, "%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]) != 4) {
        printf("Error parsing the IP address. Ensure it follows the x.x.x.x format.\n");
        return 1;
    }

    // Validate each octet of the IP address
    for (int i = 0; i < 4; i++) {
        if (ip[i] < 0 || ip[i] > 255) {
            printf("Each octet must be between 0 and 255.\n");
            return 1;
        }
    }

    // Validate prefix length
    if (prefixLength < 0 || prefixLength > 32) {
        printf("Invalid prefix length. It must be between 0 and 32.\n");
        return 1;
    }

    // Calculate subnet details
    calculateSubnet(ip, prefixLength);

    return 0;
}