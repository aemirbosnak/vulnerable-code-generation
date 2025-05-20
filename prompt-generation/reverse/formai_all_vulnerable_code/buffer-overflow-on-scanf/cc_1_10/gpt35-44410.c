//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: optimized
#include <stdio.h>

// Function to convert decimal to binary
void decimalToBinary(int decimalValue, char *binaryValue) {
    for(int i = 7; i >= 0; i--) {
        binaryValue[i] = decimalValue % 2 + '0';
        decimalValue /= 2;
    }
}

// Function to calculate subnet mask
void calculateSubnetMask(int subnetBits, char *subnetMask) {
    for(int i = 0; i < 4; i++) {
        if(subnetBits >= 8) {
            subnetMask[i] = '255';
            subnetBits -= 8;
        }
        else if(subnetBits > 0) {
            int temp = 0;
            for(int j = 0; j < subnetBits; j++) {
                temp += 1 << (7 - j);
            }
            subnetMask[i] = temp;
            subnetBits = 0;
        }
        else {
            subnetMask[i] = '0';
        }
    }
}

int main() {
    int ipAddress[4]; // To store the IP address
    int subnetBits; // To store the number of subnet bits
    char subnetMask[4]; // To store the subnet mask
    
    // Getting the input from the user
    printf("Enter the IP address in dotted decimal notation: ");
    scanf("%d.%d.%d.%d", &ipAddress[0], &ipAddress[1], &ipAddress[2], &ipAddress[3]);
    
    printf("Enter the number of subnet bits: ");
    scanf("%d", &subnetBits);
    
    // Calculate the subnet mask
    calculateSubnetMask(subnetBits, subnetMask);
    
    // Displaying the results
    printf("\nThe subnet mask is: %d.%d.%d.%d\n", subnetMask[0], subnetMask[1], subnetMask[2], subnetMask[3]);
    
    // Finding the network address and broadcast address
    for(int i = 0; i < 4; i++) {
        ipAddress[i] &= subnetMask[i];
    }
    
    char networkAddress[10]; // To store the network address
    decimalToBinary(ipAddress[0], &networkAddress[0]);
    decimalToBinary(ipAddress[1], &networkAddress[8]);
    decimalToBinary(ipAddress[2], &networkAddress[16]);
    decimalToBinary(ipAddress[3], &networkAddress[24]);
    networkAddress[32] = '\0';
    printf("The network address is: %d.%d.%d.%d/%d (%s)\n", ipAddress[0], ipAddress[1], ipAddress[2], ipAddress[3], subnetBits, networkAddress);
    
    char broadcastAddress[10]; // To store the broadcast address
    for(int i = 0; i < 4; i++) {
        ipAddress[i] |= ~(subnetMask[i]) & 255;
    }
    decimalToBinary(ipAddress[0], &broadcastAddress[0]);
    decimalToBinary(ipAddress[1], &broadcastAddress[8]);
    decimalToBinary(ipAddress[2], &broadcastAddress[16]);
    decimalToBinary(ipAddress[3], &broadcastAddress[24]);
    broadcastAddress[32] = '\0';
    printf("The broadcast address is: %d.%d.%d.%d/%d (%s)\n", ipAddress[0], ipAddress[1], ipAddress[2], ipAddress[3], subnetBits, broadcastAddress);

    return 0;
}