//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Claude Shannon
/*
 * Claude Shannon-style Subnet Calculator
 *
 * This program takes a given IP address and subnet mask, and calculates the
 * resulting network address, broadcast address, and subnet range in CIDR
 * notation. It also checks for incorrect input format and displays error
 * messages accordingly.
 *
 * Author: Claude Shannon
 * Date: 1951 (updated 2021)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IP_ADDRESS_LENGTH 15
#define SUBNET_MASK_LENGTH 2

void calculateSubnet(char *ipAddress, char *subnetMask);

int main() {
    char ipAddress[IP_ADDRESS_LENGTH+1], subnetMask[SUBNET_MASK_LENGTH+1];

    printf("Enter IP address: ");
    scanf("%15s", ipAddress);

    printf("Enter subnet mask: ");
    scanf("%2s", subnetMask);

    calculateSubnet(ipAddress, subnetMask);

    return 0;
}

void calculateSubnet(char *ipAddress, char *subnetMask) {
    int octet1, octet2, octet3, octet4, maskBits;
    int subnetOctet, subnetMaskBits, subnetSize;
    int networkOctet1, networkOctet2, networkOctet3, networkOctet4;
    int broadcastOctet1, broadcastOctet2, broadcastOctet3, broadcastOctet4;
    char *endPtr;

    octet1 = strtol(ipAddress, &endPtr, 10);
    if (*endPtr != '.') {
        printf("Invalid IP address format\n");
        return;
    }

    octet2 = strtol(endPtr+1, &endPtr, 10);
    if (*endPtr != '.') {
        printf("Invalid IP address format\n");
        return;
    }

    octet3 = strtol(endPtr+1, &endPtr, 10);
    if (*endPtr != '.') {
        printf("Invalid IP address format\n");
        return;
    }

    octet4 = strtol(endPtr+1, &endPtr, 10);
    if (*endPtr != '\0') {
        printf("Invalid IP address format\n");
        return;
    }

    maskBits = strtol(subnetMask, &endPtr, 10);
    if (*endPtr != '\0') {
        printf("Invalid subnet mask format\n");
        return;
    }

    if (maskBits < 1 || maskBits > 30) {
        printf("Invalid subnet mask length\n");
        return;
    }

    subnetOctet = (maskBits <= 8) ? octet1 : ((maskBits <= 16) ? octet2 : ((maskBits <= 24) ? octet3 : octet4));
    subnetMaskBits = 8 * SUBNET_MASK_LENGTH - (8 - (maskBits % 8));
    subnetSize = 1 << (8 - (maskBits % 8));

    networkOctet1 = octet1 & ((maskBits >= 8) ? 255 : 0);
    networkOctet2 = octet2 & ((maskBits >= 16) ? 255 : 0);
    networkOctet3 = octet3 & ((maskBits >= 24) ? 255 : 0);
    networkOctet4 = octet4 & ((maskBits >= 32) ? 255 : 0);

    broadcastOctet1 = octet1 | ((maskBits < 8) ? 255 : (~255 & (subnetSize-1)));
    broadcastOctet2 = octet2 | ((maskBits < 16) ? 255 : ((maskBits % 8 == 0) ? (~255 & (subnetSize-1)) : 0));
    broadcastOctet3 = octet3 | ((maskBits < 24) ? 255 : ((maskBits % 8 == 0 || maskBits % 8 >= 4) ? (~255 & (subnetSize-1)) : 0));
    broadcastOctet4 = octet4 | ((maskBits < 32) ? 255 : ((maskBits % 8 == 0 || maskBits % 8 >= 2) ? (~255 & (subnetSize-1)) : 0));

    printf("Network address: %d.%d.%d.%d/%d\n", networkOctet1, networkOctet2, networkOctet3, networkOctet4, maskBits);
    printf("Broadcast address: %d.%d.%d.%d/%d\n", broadcastOctet1, broadcastOctet2, broadcastOctet3, broadcastOctet4, maskBits);
    printf("Subnet range: %d.%d.%d.%d - %d.%d.%d.%d\n", networkOctet1, networkOctet2, networkOctet3, subnetOctet,
                                                       broadcastOctet1, broadcastOctet2, broadcastOctet3, subnetOctet+subnetSize-1);
}