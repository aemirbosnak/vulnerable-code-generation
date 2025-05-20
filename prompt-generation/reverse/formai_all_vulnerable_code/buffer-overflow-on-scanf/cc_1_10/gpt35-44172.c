//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IP_LEN 15     // Maximum length of IP Address
#define MAX_CIDR_LEN 2    // Maximum length of CIDR Notation

// Function for Decimal to Binary Conversion
void decimalToBinary(int decimal, int* binaryArr, int size) {
    int i;
    for (i = size - 1; i >= 0; i--) {
        binaryArr[i] = decimal % 2;
        decimal = decimal / 2;
    }
}

// Function for Binary to Decimal Conversion
int binaryToDecimal(int* binaryArr, int size) {
    int i, decimal = 0, power = 0;
    for (i = size - 1; i >= 0; i--) {
        if (binaryArr[i] == 1) {
            decimal += pow(2, power);
        }
        power++;
    }
    return decimal;
}

// Function to Calculate Network Address
void calculateNetworkAddr(int* splitIpAddress, int* binarySubnetMask, int* networkAddr, int size) {
    int i;
    for (i = 0; i < size; i++) {
        networkAddr[i] = splitIpAddress[i] & binarySubnetMask[i];
    }
}

// Function to Calculate Broadcast Address
void calculateBroadcastAddr(int* splitIpAddress, int* binarySubnetMask, int* broadcastAddr, int size) {
    int i;
    for (i = 0; i < size; i++) {
        broadcastAddr[i] = splitIpAddress[i] | (binarySubnetMask[i] ^ 255);
    }
}

// Function to Print Results
void printResults(int* networkAddr, int* broadcastAddr) {
    printf("\nNetwork Address : %d.%d.%d.%d", networkAddr[0], networkAddr[1], networkAddr[2], networkAddr[3]);
    printf("\nBroadcast Address : %d.%d.%d.%d", broadcastAddr[0], broadcastAddr[1], broadcastAddr[2], broadcastAddr[3]);
    printf("\n");
}

// Function to Calculate Subnet Mask
void calculateSubnetMask(int cidr, int* binarySubnetMask) {
    int i, binaryArr[8];
    memset(binarySubnetMask, 0, sizeof(int) * 4);
    for (i = 0; i < cidr; i++) {
        binarySubnetMask[i / 8] += pow(2, 7 - (i % 8));
    }
}

// Main Function
int main() {
    char ipAddress[MAX_IP_LEN + 1], cidrNotation[MAX_CIDR_LEN + 1];
    int i, j, splitIpAddress[4], cidr, binarySubnetMask[4], networkAddr[4], broadcastAddr[4];
    
    // Getting Input from User
    printf("Enter IP Address (eg: 192.168.1.1) : ");
    scanf("%s", ipAddress);
    printf("Enter CIDR Notation (eg: /24) : ");
    scanf("%s", cidrNotation);
    
    // Splitting IP Address
    char* token = strtok(ipAddress, ".");
    for (i = 0; token != NULL && i < 4; i++) {
        splitIpAddress[i] = atoi(token);
        token = strtok(NULL, ".");
    }
    
    // Extracting CIDR Value
    cidr = atoi(cidrNotation + 1);
    
    // Calculating Subnet Mask
    calculateSubnetMask(cidr, binarySubnetMask);
    
    // Calculating Network Address
    calculateNetworkAddr(splitIpAddress, binarySubnetMask, networkAddr, 4);
    
    // Calculating Broadcast Address
    calculateBroadcastAddr(splitIpAddress, binarySubnetMask, broadcastAddr, 4);
    
    // Printing Results
    printResults(networkAddr, broadcastAddr);
    
    return 0;
}