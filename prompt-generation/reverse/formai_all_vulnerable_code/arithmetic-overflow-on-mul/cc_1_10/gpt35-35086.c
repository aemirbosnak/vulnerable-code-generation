//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: scientific
/* This C program calculates subnet information for a given IP address and subnet mask.
   The subnet information includes the network address, first usable host address, last usable host address and broadcast address */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printBinary(int num, char *bin); // Function to convert decimal to binary
void calculateSubnetInfo(int octet[], int subnetMask); // Function to calculate subnet information 

int main() {
    char ipAddress[16], subnetMask[16];
    int octet[4], subnetOctet[4], subnetMaskDec;

    // Get input from user
    printf("Enter IP Address: ");
    scanf("%s", ipAddress);
    printf("Enter Subnet Mask: ");
    scanf("%s", subnetMask);

    // Convert IP Address from string to octet
    char *token = strtok(ipAddress, ".");
    int index = 0;
    while (token != NULL) {
        octet[index++] = atoi(token);
        token = strtok(NULL, ".");
    }

    // Convert Subnet Mask from string to octet and decimal
    token = strtok(subnetMask, ".");
    index = 0;
    while (token != NULL) {
        subnetOctet[index++] = atoi(token);
        token = strtok(NULL, ".");
    }
    subnetMaskDec = subnetOctet[0] * 256 * 256 * 256 + subnetOctet[1] * 256 * 256 + subnetOctet[2] * 256 + subnetOctet[3];

    // Calculate Subnet Information
    calculateSubnetInfo(octet, subnetMaskDec);

    return 0;
}

void printBinary(int num, char *bin) {
    for (int i = 31; i >= 0; i--) {
        if (num & (1 << i)) {
            strcat(bin, "1");
        } else {
            strcat(bin, "0");
        }
    }
}

void calculateSubnetInfo(int octet[], int subnetMask) {
    // Calculate Network Address
    int networkAddress = subnetMask & (octet[0] * 256 * 256 * 256 + octet[1] * 256 * 256 + octet[2] * 256 + octet[3]);
    printf("Network Address: %d.%d.%d.%d\n", networkAddress / 256 / 256 / 256,
                                            (networkAddress / 256 / 256) % 256,
                                            (networkAddress / 256) % 256,
                                            networkAddress % 256);

    // Calculate First Usable Host Address
    int firstUsableHostAddress = networkAddress + 1;
    printf("First Usable Host Address: %d.%d.%d.%d\n", firstUsableHostAddress / 256 / 256 / 256,
                                                      (firstUsableHostAddress / 256 / 256) % 256,
                                                      (firstUsableHostAddress / 256) % 256,
                                                      firstUsableHostAddress % 256);

    // Calculate Last Usable Host Address
    int lastUsableHostAddress = (subnetMask ^ 0xFFFFFFFF) & (networkAddress + 1) - 1;
    printf("Last Usable Host Address: %d.%d.%d.%d\n", lastUsableHostAddress / 256 / 256 / 256,
                                                     (lastUsableHostAddress / 256 / 256) % 256,
                                                     (lastUsableHostAddress / 256) % 256,
                                                     lastUsableHostAddress % 256);

    // Calculate Broadcast Address
    int broadcastAddress = (subnetMask ^ 0xFFFFFFFF) | networkAddress;
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcastAddress / 256 / 256 / 256,
                                               (broadcastAddress / 256 / 256) % 256,
                                               (broadcastAddress / 256) % 256,
                                               broadcastAddress % 256);

    // Convert Subnet Mask from decimal to binary
    char bin[33] = "";
    printBinary(subnetMask, bin);
    printf("Subnet Mask: %s\n", bin);
}