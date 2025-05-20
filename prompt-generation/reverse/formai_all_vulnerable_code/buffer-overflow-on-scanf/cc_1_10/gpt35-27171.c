//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the subnet mask based on prefix length
void calculateSubnetMask(int prefixLength, int* subnetMask) {
    int i;
    for(i=0; i<prefixLength; i++) {
        subnetMask[i/8] |= (1 << (7 - (i%8)));
    }
}

// Function to convert IP address from string to integer array
void convertIPtoIntArray(char* ipAddress, int* intArray) {
    char* token = strtok(ipAddress, ".");
    int i=0;
    while(token != NULL) {
        intArray[i++] = atoi(token);
        token = strtok(NULL, ".");
    }
}

// Function to calculate the subnet address
void calculateSubnetAddress(int* ipAddress, int* subnetMask, int* subnetAddress) {
    int i;
    for(i=0; i<4; i++) {
        subnetAddress[i] = ipAddress[i] & subnetMask[i];
    }
}

int main() {
    char ipAddress[20];
    int prefixLength;
    int subnetMask[4] = {0, 0, 0, 0};
    int ipAddressIntArray[4];
    int subnetAddress[4];
    
    // Get user input
    printf("Enter the IP address: ");
    scanf("%s", ipAddress);
    printf("Enter the prefix length: ");
    scanf("%d", &prefixLength);
    
    // Calculate subnet mask and subnet address
    calculateSubnetMask(prefixLength, subnetMask);
    convertIPtoIntArray(ipAddress, ipAddressIntArray);
    calculateSubnetAddress(ipAddressIntArray, subnetMask, subnetAddress);
    
    // Print the results
    printf("\nSubnet Mask: %d.%d.%d.%d\n", subnetMask[0], subnetMask[1], subnetMask[2], subnetMask[3]);
    printf("Subnet Address: %d.%d.%d.%d\n", subnetAddress[0], subnetAddress[1], subnetAddress[2], subnetAddress[3]);
    
    return 0;
}