//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: relaxed
#include <stdio.h>

// Convert decimal to binary
void decimalToBinary(int decimal, int binary[]) {
    int i = 0;
    while (decimal > 0) {
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }
}

// Convert binary to decimal
int binaryToDecimal(int binary[]) {
    int decimal = 0;
    for (int i = 7; i >= 0; i--) {
        if (binary[i] == 1) {
            decimal += 1 << (7-i);
        }
    }
    return decimal;
}

// Print the binary array
void printBinary(int binary[]) {
    for (int i = 0; i < 8; i++) {
        printf("%d", binary[i]);
    }
}

int main() {
    
    int ipAddress[4];
    printf("Enter IP address (x.x.x.x format): ");
    scanf("%d.%d.%d.%d", &ipAddress[0], &ipAddress[1], &ipAddress[2], &ipAddress[3]);
    
    int subnetMask;
    int fullSubnetMask[4] = {255, 255, 255, 255};
    printf("Enter subnet mask (x.x.x.x format): ");
    scanf("%d.%d.%d.%d", &subnetMask, &fullSubnetMask[1], &fullSubnetMask[2], &fullSubnetMask[3]);
    
    // Calculate network address
    int networkAddress[4];
    for (int i = 0; i < 4; i++) {
        networkAddress[i] = ipAddress[i] & fullSubnetMask[i];
    }
    
    // Calculate broadcast address
    int broadcastAddress[4];
    int complementMask[4];
    for (int i = 0; i < 4; i++) {
        complementMask[i] = 255 - fullSubnetMask[i];
        broadcastAddress[i] = networkAddress[i] | complementMask[i];
    }
    
    // Calculate number of hosts
    int numHosts = binaryToDecimal(complementMask) - 1;
    
    printf("\nNetwork Address: %d.%d.%d.%d\n", networkAddress[0], networkAddress[1], networkAddress[2], networkAddress[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcastAddress[0], broadcastAddress[1], broadcastAddress[2], broadcastAddress[3]);
    printf("Number of Hosts: %d\n", numHosts);
  
    return 0;
}