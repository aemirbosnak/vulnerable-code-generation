//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function prototypes
void calculateSubnet(char *ipAddr, char *subnetMask);
void printBinary(char *ip);
int binaryToDecimal(char *binary);

int main() {
    char ipAddr[16];
    char subnetMask[16];

    printf("🎉 Welcome to the C Subnet Calculator! 🎉\n");
    printf("Let's dive into the world of IP addressing and subnetting! 🌐\n\n");

    // User input for IP address and subnet mask
    printf("Please enter an IP address (e.g., 192.168.1.1): ");
    scanf("%15s", ipAddr);
    
    printf("Now enter the subnet mask (e.g., 255.255.255.0): ");
    scanf("%15s", subnetMask);

    calculateSubnet(ipAddr, subnetMask);

    return 0;
}

void calculateSubnet(char *ipAddr, char *subnetMask) {
    printf("\n🚀 Calculating subnet information...\n");

    // Split IP address and subnet mask into tokens
    int ip[4], mask[4], network[4], broadcast[4];
    sscanf(ipAddr, "%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
    sscanf(subnetMask, "%d.%d.%d.%d", &mask[0], &mask[1], &mask[2], &mask[3]);

    // Calculate the network and broadcast addresses
    for(int i = 0; i < 4; i++) {
        network[i] = ip[i] & mask[i];
        broadcast[i] = network[i] | (~mask[i] & 255);
    }

    // Output results
    printf("🌟 Your IP Address: %s\n", ipAddr);
    printf("🏴‍☠️ Your Subnet Mask: %s\n", subnetMask);
    printf("🌍 Network Address: %d.%d.%d.%d\n", network[0], network[1], network[2], network[3]);
    printf("🚩 Broadcast Address: %d.%d.%d.%d\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);

    // Calculate number of hosts
    int hostBits = 32 - (int)log2((mask[0] * 256 + mask[1] * 256 + mask[2] * 256 + mask[3]) + 1);
    int maxHosts = pow(2, hostBits) - 2; // Subtracting network and broadcast address
    printf("🔢 Maximum Hosts: %d\n", maxHosts);

    printf("\n✨ Thank you for using the C Subnet Calculator! ✨\n");
}

void printBinary(char *ip) {
    char binary[35] = "";
    int num;
    char *token = strtok(ip, ".");

    while(token) {
        num = atoi(token);
        char bin[9];
        for(int i = 7; i >= 0; i--) {
            bin[i] = (num % 2) + '0';
            num /= 2;
        }
        bin[8] = '\0';
        strcat(binary, bin);
        strcat(binary, ".");
        token = strtok(NULL, ".");
    }
    binary[strlen(binary)-1] = '\0'; // Remove last dot

    printf("Binary Representation: %s\n", binary);
}

int binaryToDecimal(char *binary) {
    int decimal = 0;
    for (int i = 0; i < 8; ++i) {
        decimal = decimal * 2 + (binary[i] - '0');
    }
    return decimal;
}