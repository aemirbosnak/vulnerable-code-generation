//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <arpa/inet.h>

// Function to print a binary representation of an IP address
void printBinary(uint8_t *ip) {
    for (int i = 0; i < 4; i++) {
        for (int j = 7; j >= 0; j--) {
            printf("%d", (ip[i] >> j) & 1);
        }
        if (i < 3) printf(".");
    }
}

// Function to calculate the subnet mask based on the prefix length
void calculateSubnetMask(int prefixLength, uint8_t *subnetMask) {
    for (int i = 0; i < 4; i++) {
        if (prefixLength >= 8) {
            subnetMask[i] = 255;
            prefixLength -= 8;
        } else {
            subnetMask[i] = (uint8_t)(256 - (1 << (8 - prefixLength)));
            prefixLength = 0;
        }
    }
}

// Function to calculate the network address
void calculateNetworkAddress(uint8_t *ip, uint8_t *subnetMask, uint8_t *networkAddress) {
    for (int i = 0; i < 4; i++) {
        networkAddress[i] = ip[i] & subnetMask[i];
    }
}

// Function to calculate broadcast address
void calculateBroadcastAddress(uint8_t *networkAddress, uint8_t *subnetMask, uint8_t *broadcastAddress) {
    for (int i = 0; i < 4; i++) {
        broadcastAddress[i] = networkAddress[i] | (~subnetMask[i] & 0xFF);
    }
}

// Function to calculate the number of usable hosts
int calculateUsableHosts(int prefixLength) {
    return (1 << (32 - prefixLength)) - 2; // Subtract network and broadcast addresses
}

// Function to display the results
void displayResults(uint8_t *ip, uint8_t *subnetMask, uint8_t *networkAddress, uint8_t *broadcastAddress, int usableHosts) {
    printf("\n🎉🎊 Here are your results! 🎊🎉\n");
    printf("IP Address: ");
    printBinary(ip);
    printf("\nSubnet Mask: ");
    printBinary(subnetMask);
    printf("\nNetwork Address: ");
    printBinary(networkAddress);
    printf("\nBroadcast Address: ");
    printBinary(broadcastAddress);
    printf("\nNumber of Usable Hosts: %d\n", usableHosts);
    printf("Happy Networking! 🎈\n");
}

// Main function
int main() {
    char ipString[16];
    int prefixLength;
    uint8_t ip[4], subnetMask[4], networkAddress[4], broadcastAddress[4];

    printf("⭐ Welcome to the Happy Subnet Calculator! ⭐\n");
    printf("Please enter an IP address (e.g. 192.168.1.1): ");
    fgets(ipString, sizeof(ipString), stdin);
    if (inet_pton(AF_INET, ipString, ip) != 1) {
        printf("❌ Invalid IP address format.\n");
        return 1;
    }
    
    printf("Please enter a subnet prefix length (e.g. 24): ");
    scanf("%d", &prefixLength);

    if (prefixLength < 0 || prefixLength > 32) {
        printf("❌ Subnet prefix length must be between 0 and 32.\n");
        return 1;
    }

    calculateSubnetMask(prefixLength, subnetMask);
    calculateNetworkAddress(ip, subnetMask, networkAddress);
    calculateBroadcastAddress(networkAddress, subnetMask, broadcastAddress);
    int usableHosts = calculateUsableHosts(prefixLength);

    displayResults(ip, subnetMask, networkAddress, broadcastAddress, usableHosts);
    printf("🎉 Thanks for using the Happy Subnet Calculator! Goodbye! 🎉\n");

    return 0;
}