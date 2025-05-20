//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the subnet mask from a given IP address
void calculateSubnetMask(char* ipAddress, char* subnetMask) {
    int i;
    for (i = 0; i < strlen(ipAddress); i++) {
        if (ipAddress[i] == '.') {
            strcat(subnetMask, "255. ");
        } else {
            strcat(subnetMask, &ipAddress[i]);
        }
    }
}

// Function to validate the input IP address
int validateIpAddress(char* ipAddress) {
    int i;
    int numDots = 0;
    for (i = 0; i < strlen(ipAddress); i++) {
        if (ipAddress[i] == '.') {
            numDots++;
        } else if (i == 0 && ipAddress[i] == '0') {
            return 0;
        } else if (i > 0 && ipAddress[i] == '0' && ipAddress[i-1]!= '.') {
            return 0;
        }
    }
    if (numDots!= 3) {
        return 0;
    }
    return 1;
}

// Function to validate the input subnet mask
int validateSubnetMask(char* subnetMask) {
    int i;
    for (i = 0; i < strlen(subnetMask); i++) {
        if (subnetMask[i] < '0' || subnetMask[i] > '9') {
            return 0;
        }
    }
    return 1;
}

int main() {
    char ipAddress[16];
    char subnetMask[16];
    int validIp = 0;
    int validSubnet = 0;

    printf("Enter an IP address: ");
    scanf("%s", ipAddress);

    // Validate the input IP address
    while (!validateIpAddress(ipAddress)) {
        printf("Invalid IP address. Please enter a valid IP address: ");
        scanf("%s", ipAddress);
    }

    // Calculate the subnet mask
    calculateSubnetMask(ipAddress, subnetMask);

    // Validate the input subnet mask
    while (!validateSubnetMask(subnetMask)) {
        printf("Invalid subnet mask. Please enter a valid subnet mask: ");
        scanf("%s", subnetMask);
    }

    printf("\nThe subnet mask for the IP address %s is %s.\n", ipAddress, subnetMask);

    return 0;
}