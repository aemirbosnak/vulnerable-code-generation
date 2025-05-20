//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertToBinary(int num, char *binary) {
    for (int i = 0; i < 8; i++) {
        binary[7 - i] = (num % 2) + '0';
        num /= 2;
    }
    binary[8] = '\0';
}

void calculateSubnet(char *ip, char *mask) {
    int ipParts[4], maskParts[4];
    int networkParts[4], broadcastParts[4];
    char ipBinary[4][9], maskBinary[4][9], networkBinary[4][9];

    // Splitting IP address and mask into parts
    sscanf(ip, "%d.%d.%d.%d", &ipParts[0], &ipParts[1], &ipParts[2], &ipParts[3]);
    sscanf(mask, "%d.%d.%d.%d", &maskParts[0], &maskParts[1], &maskParts[2], &maskParts[3]);

    // Calculating the network address and broadcast address
    for (int i = 0; i < 4; i++) {
        networkParts[i] = ipParts[i] & maskParts[i];
        broadcastParts[i] = networkParts[i] | (~maskParts[i] & 0xFF);
        
        // Convert to binary
        convertToBinary(ipParts[i], ipBinary[i]);
        convertToBinary(maskParts[i], maskBinary[i]);
        convertToBinary(networkParts[i], networkBinary[i]);
    }

    // Output results
    printf("\nInput IP Address: %s\n", ip);
    printf("Input Subnet Mask: %s\n", mask);
    printf("\nBinary Representation:\n");
    printf("IP:       %s.%s.%s.%s\n", ipBinary[0], ipBinary[1], ipBinary[2], ipBinary[3]);
    printf("Mask:     %s.%s.%s.%s\n", maskBinary[0], maskBinary[1], maskBinary[2], maskBinary[3]);
    printf("Network:  %d.%d.%d.%d\n", networkParts[0], networkParts[1], networkParts[2], networkParts[3]);
    printf("Broadcast: %d.%d.%d.%d\n", broadcastParts[0], broadcastParts[1], broadcastParts[2], broadcastParts[3]);

    // Calculating range of valid IP addresses
    printf("Valid IP Address Range: %d.%d.%d.%d - %d.%d.%d.%d\n",
           networkParts[0], networkParts[1], networkParts[2], networkParts[3] + 1,
           broadcastParts[0], broadcastParts[1], broadcastParts[2], broadcastParts[3] - 1);
}

int main() {
    char ip[16];
    char mask[16];

    printf("Welcome to the C Subnet Calculator!\n");
    printf("Please enter an IP Address (format: xxx.xxx.xxx.xxx): ");
    scanf("%15s", ip);
    printf("Please enter a Subnet Mask (format: xxx.xxx.xxx.xxx): ");
    scanf("%15s", mask);

    // Validate IP address and subnet mask
    if (strchr(ip, '.') == NULL || strchr(mask, '.') == NULL) {
        printf("Invalid input format. Please enter valid IP address and subnet mask.\n");
        return 1;
    }

    // Calculate subnet details
    calculateSubnet(ip, mask);

    return 0;
}