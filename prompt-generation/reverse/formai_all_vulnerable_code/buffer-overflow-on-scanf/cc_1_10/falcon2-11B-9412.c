//Falcon2-11B DATASET v1.0 Category: Subnet Calculator ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to convert a decimal number to binary
void decimalToBinary(int decimal, char* binary) {
    int i;
    int len = strlen(binary);

    // Initialize binary string
    strncpy(binary, "00000000", 8);

    // Convert decimal to binary
    for (i = 0; i < len; i++) {
        if (decimal >= 2) {
            binary[i] = '1';
            decimal = decimal - 2;
        }
        else {
            binary[i] = '0';
        }
    }

    // Reverse binary string
    int len2 = strlen(binary);
    for (i = 0; i < len2/2; i++) {
        char temp = binary[i];
        binary[i] = binary[len2-i-1];
        binary[len2-i-1] = temp;
    }
}

// Function to calculate subnet mask
void subnetMask(int network, char* mask, char* result) {
    char binary[10];
    int i;
    int len = strlen(mask);

    // Convert decimal to binary
    decimalToBinary(network, binary);

    // Find first 1 bit position
    int firstBitPos = 0;
    for (i = 0; i < len; i++) {
        if (binary[i] == '1') {
            firstBitPos = i;
            break;
        }
    }

    // Calculate subnet mask
    int subnetMaskLen = len - firstBitPos;
    int subnetMask = 0;
    for (i = 0; i < subnetMaskLen; i++) {
        if (binary[firstBitPos+i] == '1') {
            subnetMask = subnetMask + (1 << (8 - (i+1)));
        }
    }

    // Calculate subnet address
    int subnetAddress = network & subnetMask;

    // Convert subnet mask to binary
    decimalToBinary(subnetAddress, result);
}

// Function to calculate host address range
void hostAddressRange(int network, char* mask, char* result) {
    char binary[10];
    int i;
    int len = strlen(mask);

    // Convert decimal to binary
    decimalToBinary(network, binary);

    // Find first 1 bit position
    int firstBitPos = 0;
    for (i = 0; i < len; i++) {
        if (binary[i] == '1') {
            firstBitPos = i;
            break;
        }
    }

    // Calculate host address range
    int hostAddressRangeLen = len - firstBitPos;
    int hostAddressRange = 0;
    for (i = 0; i < hostAddressRangeLen; i++) {
        if (binary[firstBitPos+i] == '1') {
            hostAddressRange = hostAddressRange + (1 << (8 - (i+1)));
        }
    }

    // Convert host address range to binary
    decimalToBinary(hostAddressRange, result);
}

int main() {
    int network;
    char mask[10];
    char result[10];

    // Get network address
    printf("Enter network address: ");
    scanf("%d", &network);

    // Get subnet mask
    printf("Enter subnet mask: ");
    scanf("%s", mask);

    // Calculate subnet mask
    subnetMask(network, mask, result);

    // Calculate host address range
    hostAddressRange(network, mask, result);

    printf("Subnet mask: %s\n", result);
    printf("Host address range: %s\n", result);

    return 0;
}