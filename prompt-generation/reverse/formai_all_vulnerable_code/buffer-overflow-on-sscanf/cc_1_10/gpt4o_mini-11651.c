//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertToBinary(int n, char *binary) {
    for (int i = 0; i < 8; i++) {
        binary[7 - i] = (n % 2) ? '1' : '0';
        n /= 2;
    }
    binary[8] = '\0'; // Null-terminate the string
}

void calculateSubnet(char *ip, char *mask) {
    int ipParts[4], maskParts[4];
    char binaryIP[4][9], binaryMask[4][9], network[4], broadcast[4];
    
    sscanf(ip, "%d.%d.%d.%d", &ipParts[0], &ipParts[1], &ipParts[2], &ipParts[3]);
    sscanf(mask, "%d.%d.%d.%d", &maskParts[0], &maskParts[1], &maskParts[2], &maskParts[3]);

    // Convert to binary
    for (int i = 0; i < 4; i++) {
        convertToBinary(ipParts[i], binaryIP[i]);
        convertToBinary(maskParts[i], binaryMask[i]);
    }

    // Calculate network address and broadcast address
    for (int i = 0; i < 4; i++) {
        // Network: IP AND Mask
        network[i] = ipParts[i] & maskParts[i];
        // Broadcast: Network OR Inverted Mask
        broadcast[i] = network[i] | (~maskParts[i] & 0xFF);
    }

    printf("\nNetwork Address: %d.%d.%d.%d\n", network[0], network[1], network[2], network[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);
    printf("Usable IP Range: %d.%d.%d.%d to %d.%d.%d.%d\n", 
        network[0], network[1], network[2], network[3] + 1, 
        broadcast[0], broadcast[1], broadcast[2], broadcast[3] - 1);
}

int main() {
    char ip[16], mask[16];

    printf("🎉 Welcome to the C Subnet Calculator! 🎉\n");
    
    // Read IP Address
    printf("Please enter an IP address (format: xxx.xxx.xxx.xxx): ");
    scanf("%15s", ip);
    
    // Read Subnet Mask
    printf("Please enter a subnet mask (format: xxx.xxx.xxx.xxx): ");
    scanf("%15s", mask);
    
    printf("\n✏️ Calculating the Subnet... Please wait...\n");
    
    calculateSubnet(ip, mask);

    printf("\n🛑 Thank you for using the C Subnet Calculator. Have a great day! 🛑\n");

    return 0;
}