//Falcon2-11B DATASET v1.0 Category: Subnet Calculator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert binary number to decimal
int binaryToDecimal(char* binary) {
    int decimal = 0;
    int len = strlen(binary);
    int i = 0;
    while (i < len) {
        decimal += (binary[i] - '0') * pow(2, len - i - 1);
        i++;
    }
    return decimal;
}

// Function to find the number of bits set in a binary number
int countBitsSet(char* binary) {
    int len = strlen(binary);
    int i = 0;
    int count = 0;
    while (i < len) {
        if (binary[i] - '0') {
            count++;
        }
        i++;
    }
    return count;
}

// Function to find the total number of subnets in a CIDR network
int getSubnetCount(char* cidr) {
    int cidrValue = atoi(cidr);
    int maskValue = 32 - cidrValue;
    int subnetCount = (1 << maskValue);
    return subnetCount;
}

int main() {
    // Input CIDR network
    char cidr[100];
    printf("Enter the CIDR network: ");
    scanf("%s", cidr);

    // Convert CIDR network to binary
    char binary[100];
    int decimal = binaryToDecimal(cidr);
    sprintf(binary, "%d", decimal);

    // Find the number of bits set in the binary number
    int bitsSet = countBitsSet(binary);

    // Find the total number of subnets in the CIDR network
    int subnetCount = getSubnetCount(binary);

    printf("Number of bits set: %d\n", bitsSet);
    printf("Total number of subnets: %d\n", subnetCount);

    return 0;
}