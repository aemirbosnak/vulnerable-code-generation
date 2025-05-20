//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_INPUT 16

// Function to convert IP address string to the network format.
void stringToIP(const char *str, uint8_t *ip) {
    sscanf(str, "%hhu.%hhu.%hhu.%hhu", &ip[0], &ip[1], &ip[2], &ip[3]);
}

// Function to calculate network address.
void calculateNetworkAddress(uint8_t *ip, uint8_t *mask, uint8_t *network) {
    for (int i = 0; i < 4; i++) {
        network[i] = ip[i] & mask[i];
    }
}

// Function to calculate broadcast address.
void calculateBroadcastAddress(uint8_t *network, uint8_t *mask, uint8_t *broadcast) {
    for (int i = 0; i < 4; i++) {
        broadcast[i] = network[i] | (~mask[i] & 0xFF);
    }
}

// Function to count the number of hosts in the subnet.
unsigned int countHosts(uint8_t *mask) {
    unsigned int hostBits = 0;
    for (int i = 0; i < 4; i++) {
        hostBits += __builtin_popcount(~mask[i]); // Count the number of 0s in the mask
    }
    return (1 << hostBits) - 2; // Subtract 2 for network and broadcast addresses
}

// Function to print IP address in dotted decimal format.
void printIP(uint8_t *ip) {
    printf("%hhu.%hhu.%hhu.%hhu\n", ip[0], ip[1], ip[2], ip[3]);
}

// Main function to run the subnet calculator.
int main() {
    char inputIP[MAX_INPUT], inputMask[MAX_INPUT];
    uint8_t ip[4], mask[4], network[4], broadcast[4];

    // Take the IP address input from the user.
    printf("Enter the IP Address (e.g., 192.168.1.1): ");
    fgets(inputIP, MAX_INPUT, stdin);
    inputIP[strcspn(inputIP, "\n")] = 0; // Remove newline character

    // Take the subnet mask input from the user.
    printf("Enter the Subnet Mask (e.g., 255.255.255.0): ");
    fgets(inputMask, MAX_INPUT, stdin);
    inputMask[strcspn(inputMask, "\n")] = 0;

    // Convert string inputs to IP format.
    stringToIP(inputIP, ip);
    stringToIP(inputMask, mask);

    // Calculate network and broadcast addresses.
    calculateNetworkAddress(ip, mask, network);
    calculateBroadcastAddress(network, mask, broadcast);

    // Calculate the number of hosts in this subnet.
    unsigned int totalHosts = countHosts(mask);

    // Display results.
    printf("\nResults:\n");
    printf("IP Address: ");
    printIP(ip);
    printf("Subnet Mask: ");
    printIP(mask);
    printf("Network Address: ");
    printIP(network);
    printf("Broadcast Address: ");
    printIP(broadcast);
    printf("Total Usable Hosts: %u\n", totalHosts);

    return 0;
}