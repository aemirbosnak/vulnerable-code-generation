//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: synchronous
#include <stdio.h>
#include <string.h>

// Function to convert decimal to binary
void decimalToBinary(int decimalNumber, char* binaryNumber) {
    int binaryIndex = 0;

    while(decimalNumber) {
        binaryNumber[binaryIndex++] = (decimalNumber % 2) + '0';
        decimalNumber /= 2;
    }

    binaryNumber[binaryIndex] = 0;

    // Reverse the binary number string
    int leftIndex = 0, rightIndex = strlen(binaryNumber) - 1;
    while(leftIndex < rightIndex) {
        char temp = binaryNumber[leftIndex];
        binaryNumber[leftIndex++] = binaryNumber[rightIndex];
        binaryNumber[rightIndex--] = temp;
    }
}

// Function to calculate Subnet Mask Address
void calculateSubnetMask(char* subnetMask, int networkBits) {
    int subnetMaskBits = 32 - networkBits;
    int subnetMaskDecimal = 0;
    for(int i=0; i<subnetMaskBits; i++) {
        subnetMaskDecimal += (1 << i);
    }
    decimalToBinary(subnetMaskDecimal, subnetMask);
}

int main() {
    int ipAddress[4], networkBits;
    char subnetMask[17];

    printf("Please Enter the IP Address (in dotted decimal i.e 192.168.1.1): ");
    scanf("%d.%d.%d.%d", &ipAddress[0], &ipAddress[1], &ipAddress[2], &ipAddress[3]);

    printf("Please Enter the Number of Network Bits: ");
    scanf("%d", &networkBits);

    // Calculate Subnet Mask Address
    calculateSubnetMask(subnetMask, networkBits);

    // Print the Subnet Mask Address
    printf("Subnet Mask Address: %s\n", subnetMask);

    // Calculate Subnet ID Address
    int subnetID[4];
    for(int i=0; i<4; i++) {
        subnetID[i] = ipAddress[i] & (subnetMask[i*8] << 24 | subnetMask[i*8+1] << 16 | subnetMask[i*8+2] << 8 | subnetMask[i*8+3]);
    }

    // Print the Subnet ID Address
    printf("Subnet ID Address: %d.%d.%d.%d\n", subnetID[0], subnetID[1], subnetID[2], subnetID[3]);

    // Calculate the First and Last Valid Host Address
    int firstValidHost[4], lastValidHost[4];
    for(int i=0; i<4; i++) {
        firstValidHost[i] = subnetID[i];
        lastValidHost[i] = subnetID[i];
    }

    firstValidHost[3]++; // Increment the Least Significant Bit of Subnet ID (to get the First Valid Host Address)
    lastValidHost[3] = (lastValidHost[3] | ~((subnetMask[24] << 24) | (subnetMask[25] << 16) | (subnetMask[26] << 8) | subnetMask[27])) & 0xff; // Invert the Remaining Bits of Subnet Mask (to get the Last Valid Host Address)

    // Print the First and Last Valid Host Address
    printf("First Valid Host Address: %d.%d.%d.%d\n", firstValidHost[0], firstValidHost[1], firstValidHost[2], firstValidHost[3]);
    printf("Last Valid Host Address: %d.%d.%d.%d\n", lastValidHost[0], lastValidHost[1], lastValidHost[2], lastValidHost[3]);

    return 0;
}