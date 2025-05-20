//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 16

void printWelcomeMessage() {
    printf("🎉 Welcome to the Happy Subnet Calculator! 🎉\n");
    printf("Let's calculate some subnets and have fun! 😊\n\n");
}

void printGoodbyeMessage() {
    printf("\nThanks for using the Happy Subnet Calculator! 😄\n");
    printf("Happy coding and networking! 🌍✨\n");
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

unsigned int getIPv4Mask(int prefixLength) {
    if (prefixLength < 0 || prefixLength > 32) {
        return 0;
    }
    
    unsigned int mask = 0xFFFFFFFF << (32 - prefixLength);
    return mask;
}

void convertToBinary(unsigned int num, char *binaryStr) {
    for (int i = 0; i < 32; ++i) {
        binaryStr[31 - i] = (num & (1U << i)) ? '1' : '0';
    }
    binaryStr[32] = '\0';
}

void printSubnetDetails(const char *ip, int prefix) {
    printf("\n🌟 Calculating Subnet Details for IP: %s/%d 🌟\n", ip, prefix);
    
    unsigned int mask = getIPv4Mask(prefix);
    
    unsigned int ipParts[4];
    sscanf(ip, "%u.%u.%u.%u", &ipParts[0], &ipParts[1], &ipParts[2], &ipParts[3]);
    
    unsigned int ipDecimal = (ipParts[0] << 24) | (ipParts[1] << 16) | (ipParts[2] << 8) | ipParts[3];
    
    unsigned int subnet = ipDecimal & mask;

    char binaryMask[33], binarySubnet[33];
    convertToBinary(mask, binaryMask);
    convertToBinary(subnet, binarySubnet);
    
    printf("📌 Subnet Mask: %u.%u.%u.%u\n", (mask >> 24) & 0xFF, (mask >> 16) & 0xFF, (mask >> 8) & 0xFF, mask & 0xFF);
    printf("🔍 Binary Subnet Mask: %s\n", binaryMask);
    printf("🌈 Subnet Address: %u.%u.%u.%u\n", (subnet >> 24) & 0xFF, (subnet >> 16) & 0xFF, (subnet >> 8) & 0xFF, subnet & 0xFF);
    printf("🔢 Binary Subnet Address: %s\n", binarySubnet);
}

int main() {
    char ip[MAX_INPUT_LENGTH];
    int prefix;
    
    printWelcomeMessage();
    
    while (1) {
        printf("🔮 Please enter an IPv4 address (or type 'exit' to quit): ");
        fgets(ip, MAX_INPUT_LENGTH, stdin);
        ip[strcspn(ip, "\n")] = 0; // Remove trailing newline character

        if (strcmp(ip, "exit") == 0) {
            break;
        }

        printf("🌟 Enter prefix length (1-32): ");
        while (1) {
            if (scanf("%d", &prefix) == 1) {
                if (prefix >= 1 && prefix <= 32) {
                    clearInputBuffer(); // Clear any leftover input
                    break;
                } else {
                    printf("🚫 Invalid prefix length. Please try again (1-32): ");
                }
            } else {
                printf("🚫 Invalid input. Please enter a number (1-32): ");
                clearInputBuffer();
            }
        }

        printSubnetDetails(ip, prefix);
    }

    printGoodbyeMessage();
    return 0;
}