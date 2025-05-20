//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Prototypes
void calculateSubnet(const char *ip, const char *mask);
void printBinary(unsigned char octet);
void printDottedDecimal(unsigned int ip);

// Main function
int main() {
    char ip[16];
    char mask[16];

    printf("🎉 Welcome to the Happy Subnet Calculator! 🎉\n");
    printf("Please enter an IP address (A.B.C.D format): ");
    fgets(ip, sizeof(ip), stdin);
    ip[strcspn(ip, "\n")] = 0; // Remove newline character
    
    printf("Please enter a Subnet Mask (A.B.C.D format): ");
    fgets(mask, sizeof(mask), stdin);
    mask[strcspn(mask, "\n")] = 0; // Remove newline character

    // Happy calculation
    calculateSubnet(ip, mask);
    
    return 0;
}

// Function to calculate subnet details
void calculateSubnet(const char *ip, const char *mask) {
    unsigned char ipParts[4], maskParts[4];
    unsigned int network[4], broadcast[4];

    // Parse IP Address
    sscanf(ip, "%hhu.%hhu.%hhu.%hhu", &ipParts[0], &ipParts[1], &ipParts[2], &ipParts[3]);
    // Parse Subnet Mask
    sscanf(mask, "%hhu.%hhu.%hhu.%hhu", &maskParts[0], &maskParts[1], &maskParts[2], &maskParts[3]);

    // Calculate Network Address
    for (int i = 0; i < 4; i++) {
        network[i] = ipParts[i] & maskParts[i];
    }

    // Calculate Broadcast Address
    for (int i = 0; i < 4; i++) {
        broadcast[i] = network[i] | (~maskParts[i] & 0xFF);
    }

    // 🥳 Display Results
    printf("✨ Subnet Calculation Result ✨\n");
    printf("IP Address: ");
    printDottedDecimal(*(unsigned int*) ipParts);
    printf("\nSubnet Mask: ");
    printDottedDecimal(*(unsigned int*) maskParts);
    printf("\nNetwork Address: ");
    printDottedDecimal(*(unsigned int*) network);
    printf("\nBroadcast Address: ");
    printDottedDecimal(*(unsigned int*) broadcast);
    printf("\n\n🎈 Thank you for using the Happy Subnet Calculator! 🎈\n");
}

// Print IP in Dotted Decimal format
void printDottedDecimal(unsigned int ip) {
    printf("%u.%u.%u.%u", (ip >> 24) & 0xFF, (ip >> 16) & 0xFF, (ip >> 8) & 0xFF, ip & 0xFF);
}

// Function to print binary representation of an octet
void printBinary(unsigned char octet) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (octet >> i) & 1);
    }
}

// Fun Extra Code for Debugging in Comments
/* 
   💡 If you ever need to debug, you can uncomment the lines below:
   printf("IP in Binary: ");
   for (int i = 0; i < 4; i++) {
       printBinary(ipParts[i]);
       printf(" ");
   }
   printf("\n");
*/

// End of the Happy Subnet Calculator Program!