//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to convert binary to decimal */
int binaryToDecimal(char *binary) {
    int decimal = 0, base = 1;
    int len = strlen(binary);
    for (int i = len - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }
    return decimal;
}

/* Function to get the network address */
void getNetworkAddress(char *ipAddress, int subnetMask, char *networkAddress) {
    char binaryIpAddress[32] = "", binarySubnetMask[32] = "", binaryNetworkAddress[32] = "";
    
    // First, convert IP address to binary
    char *token = strtok(ipAddress, ".");
    while (token != NULL) {
        int group = atoi(token);
        char binaryGroup[8] = "";
        for (int i = 0; i < 8; i++) {
            binaryGroup[i] = (group % 2) + '0';
            group /= 2;
        }
        strncat(binaryIpAddress, binaryGroup, 8);
        token = strtok(NULL, ".");
    }
    
    // Next, convert subnet mask to binary
    for (int i = 0; i < subnetMask; i++) {
        binarySubnetMask[i] = '1';
    }
    
    // Convert binary subnet mask to decimal
    int decimalSubnetMask = binaryToDecimal(binarySubnetMask);
    
    // Calculate network address using bitwise AND operation
    int decimalNetworkAddress = binaryToDecimal(binaryIpAddress) & decimalSubnetMask;
    
    // Convert network address from decimal to binary
    for (int i = 31; i >= 0; i--) {
        int bit = decimalNetworkAddress % 2;
        binaryNetworkAddress[i] = bit + '0';
        decimalNetworkAddress /= 2;
    }
    
    // Convert binary network address to dotted decimal format
    strcpy(networkAddress, "");
    for (int i = 0; i < 32; i += 8) {
        char byte[9] = "";
        strncpy(byte, binaryNetworkAddress + i, 8);
        byte[8] = '\0';
        int group = binaryToDecimal(byte);
        char groupString[4];
        sprintf(groupString, "%d", group);
        strcat(networkAddress, groupString);
        if (i != 24) {
            strcat(networkAddress, ".");
        }
    }
}

/* Main function */
int main() {
    char ipAddress[16];
    int subnetMask;
    
    printf("Enter IP address: ");
    scanf("%s", ipAddress);
    printf("Enter subnet mask: ");
    scanf("%d", &subnetMask);
    
    char networkAddress[16];
    getNetworkAddress(ipAddress, subnetMask, networkAddress);
    
    printf("Network address: %s/%d", networkAddress, subnetMask);
    
    return 0;
}