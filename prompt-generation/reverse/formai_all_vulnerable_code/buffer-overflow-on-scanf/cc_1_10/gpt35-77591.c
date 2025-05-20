//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// This function returns the number of bits needed to represent a given decimal number
int getBits(int num) {
    int bits = 0;
    while (pow(2, bits) < num) {
        bits++;
    }
    return bits;
}

// This function checks if an IP address is valid
int isValidIpAddress(char* ipAddress) {
    int i, num, dots = 0;
    char* token;
    char* delimiter = ".";
    token = strtok(ipAddress, delimiter);
    while (token != NULL) {
        num = atoi(token);
        if (num < 0 || num > 255) {
            return 0;
        }
        dots++;
        token = strtok(NULL, delimiter);
    }
    if (dots != 4) {
        return 0;
    }
    return 1;
}

int main() {
    char ipAddress[16], subnetMask[16];
    int subnetBits, subnetMaskDecimal, hostBits, hostMaskDecimal, networkAddressDecimal, broadcastAddressDecimal;
    printf("Enter the IP address: ");
    scanf("%s", ipAddress);
    if (!isValidIpAddress(ipAddress)) {
        printf("Invalid IP address\n");
        return 0;
    }
    printf("Enter the number of bits for the subnet: ");
    scanf("%d", &subnetBits);
    hostBits = 32 - subnetBits;
    subnetMaskDecimal = pow(2, subnetBits) - 1;
    hostMaskDecimal = pow(2, hostBits) - 1;
    networkAddressDecimal = (atoi(ipAddress) & subnetMaskDecimal) << 24 | (atoi(strtok(NULL, ".")) & subnetMaskDecimal) << 16 | (atoi(strtok(NULL, ".")) & subnetMaskDecimal) << 8 | (atoi(strtok(NULL, ".")) & subnetMaskDecimal);
    broadcastAddressDecimal = networkAddressDecimal | hostMaskDecimal;
    printf("IP Address\t: %s\n", ipAddress);
    printf("Subnet Mask\t: ");
    for (int i = 0; i < subnetBits / 8; i++) {
        printf("255.");
    }
    printf("%d", subnetMaskDecimal & 255);
    if (subnetBits % 8 != 0) {
        printf(".");
        int remainingBits = subnetBits % 8;
        for (int i = 0; i < 8 - remainingBits; i++) {
            printf("0");
        }
        printf("%d", subnetMaskDecimal << (8 - remainingBits) & 255);
    }
    printf("\n");
    printf("Network Address\t: %d.%d.%d.%d\n", (networkAddressDecimal >> 24) & 255, (networkAddressDecimal >> 16) & 255, (networkAddressDecimal >> 8) & 255, networkAddressDecimal & 255);
    printf("Broadcast Address: %d.%d.%d.%d\n", (broadcastAddressDecimal >> 24) & 255, (broadcastAddressDecimal >> 16) & 255, (broadcastAddressDecimal >> 8) & 255, broadcastAddressDecimal & 255);
    printf("Number of Hosts\t: %d\n", hostMaskDecimal - 1);
    return 0;
}