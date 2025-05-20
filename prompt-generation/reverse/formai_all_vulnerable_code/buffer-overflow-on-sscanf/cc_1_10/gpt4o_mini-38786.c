//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

// Function to convert an IP address from string to binary
void convertToBinary(const char *ip, unsigned char *binary) {
    sscanf(ip, "%hhu.%hhu.%hhu.%hhu", &binary[0], &binary[1], &binary[2], &binary[3]);
}

// Function to find network address
void calculateNetworkAddress(unsigned char *ip, unsigned char *mask, unsigned char *network) {
    for (int i = 0; i < 4; i++) {
        network[i] = ip[i] & mask[i];
    }
}

// Function to find broadcast address
void calculateBroadcastAddress(unsigned char *network, unsigned char *mask, unsigned char *broadcast) {
    for (int i = 0; i < 4; i++) {
        broadcast[i] = network[i] | ~mask[i];
    }
}

// Function to find number of usable hosts
int calculateUsableHosts(unsigned char *mask) {
    int zeroBits = 0;
    for (int i = 0; i < 4; i++) {
        zeroBits += __builtin_popcount(~mask[i]);
    }
    return (1 << zeroBits) - 2; // Subtracting the network and broadcast addresses
}

// Function to print the IP in standard dot-decimal notation
void printIPAddress(unsigned char *ip) {
    printf("%hhu.%hhu.%hhu.%hhu\n", ip[0], ip[1], ip[2], ip[3]);
}

int main() {
    char ipStr[16];
    char maskStr[16];
    unsigned char ip[4], mask[4], network[4], broadcast[4];

    printf("Enter an IP address (e.g. 192.168.1.1): ");
    fgets(ipStr, sizeof(ipStr), stdin);
    ipStr[strcspn(ipStr, "\n")] = '\0'; // Remove the newline character

    printf("Enter a subnet mask (e.g. 255.255.255.0): ");
    fgets(maskStr, sizeof(maskStr), stdin);
    maskStr[strcspn(maskStr, "\n")] = '\0'; // Remove the newline character

    convertToBinary(ipStr, ip);
    convertToBinary(maskStr, mask);
    
    calculateNetworkAddress(ip, mask, network);
    calculateBroadcastAddress(network, mask, broadcast);
    int usableHosts = calculateUsableHosts(mask);

    printf("\nSubnet Calculation Results:\n");
    printf("IP Address: ");
    printIPAddress(ip);
    printf("Subnet Mask: ");
    printIPAddress(mask);
    printf("Network Address: ");
    printIPAddress(network);
    printf("Broadcast Address: ");
    printIPAddress(broadcast);
    printf("Number of Usable Hosts: %d\n", usableHosts);

    return 0;
}