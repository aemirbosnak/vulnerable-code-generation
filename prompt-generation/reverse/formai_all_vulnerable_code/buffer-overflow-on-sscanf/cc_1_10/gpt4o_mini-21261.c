//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a binary string to a decimal integer
int binaryToDecimal(char *binary) {
    int decimal = 0;
    for (int i = 0; i < 8; i++) {
        decimal = decimal * 2 + (binary[i] - '0');
    }
    return decimal;
}

// Function to calculate and print network and broadcast addresses
void calculateSubnet(char *ip, char *mask) {
    int ipParts[4];
    int maskParts[4];
    int networkParts[4];
    int broadcastParts[4];

    // Split IP and mask into parts
    sscanf(ip, "%d.%d.%d.%d", &ipParts[0], &ipParts[1], &ipParts[2], &ipParts[3]);
    sscanf(mask, "%d.%d.%d.%d", &maskParts[0], &maskParts[1], &maskParts[2], &maskParts[3]);

    // Calculate network address
    for (int i = 0; i < 4; i++) {
        networkParts[i] = ipParts[i] & maskParts[i];
    }

    // Calculate broadcast address
    for (int i = 0; i < 4; i++) {
        broadcastParts[i] = networkParts[i] | (~maskParts[i] & 255);
    }

    // Calculate the number of usable hosts
    int totalHosts = (1 << (32 - (maskParts[0] + maskParts[1] + maskParts[2] + maskParts[3]))) - 2;
    
    // Display results
    printf("\n---- Subnet Calculation Results ----\n");
    printf("IP Address: %s\n", ip);
    printf("Subnet Mask: %s\n", mask);
    printf("Network Address: %d.%d.%d.%d\n", networkParts[0], networkParts[1], networkParts[2], networkParts[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcastParts[0], broadcastParts[1], broadcastParts[2], broadcastParts[3]);
    printf("Usable Host IPs: %d\n", totalHosts);
    printf("-------------------------------------\n");
}

int main() {
    char ip[16];  
    char mask[16]; 

    printf("Welcome to the Ultimate C Subnet Calculator!\n");
    printf("Let's figure out your network settings!\n");

    printf("Please enter your IP address (format: xxx.xxx.xxx.xxx): ");
    fgets(ip, sizeof(ip), stdin);
    ip[strcspn(ip, "\n")] = 0;  // Remove newline character

    printf("Please enter your Subnet Mask (format: xxx.xxx.xxx.xxx): ");
    fgets(mask, sizeof(mask), stdin);
    mask[strcspn(mask, "\n")] = 0;  // Remove newline character

    if (strstr(ip, ".") == NULL || strstr(mask, ".") == NULL) {
        printf("Invalid input! Make sure you're using the correct format.\n");
        return 1;
    }

    calculateSubnet(ip, mask);

    printf("Thanks for using the C Subnet Calculator! 🌐\n");
    return 0;
}