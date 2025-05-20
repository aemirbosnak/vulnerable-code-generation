//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to calculate the network address from an IP and subnet mask
void calculateNetworkAddress(unsigned char ip[], unsigned char mask[], unsigned char network[]) {
    for (int i = 0; i < 4; i++) {
        network[i] = ip[i] & mask[i];
    }
}

// Function to calculate the broadcast address from an IP and subnet mask
void calculateBroadcastAddress(unsigned char ip[], unsigned char mask[], unsigned char broadcast[]) {
    for (int i = 0; i < 4; i++) {
        broadcast[i] = ip[i] | (~mask[i] & 0xFF);
    }
}

// Function to print an IP address as a string
void printIP(unsigned char ip[]) {
    printf("%d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
}

// Function to determine the number of usable IP addresses in the subnet
int calculateUsableIPs(unsigned char mask[]) {
    int numZeroBits = 0;
    for (int i = 0; i < 4; i++) {
        unsigned char invertedMask = ~mask[i];
        while (invertedMask) {
            numZeroBits += (invertedMask & 1);
            invertedMask >>= 1;
        }
    }
    return pow(2, numZeroBits) - 2; // -2 for network and broadcast addresses
}

int main() {
    unsigned char ip[4];
    unsigned char mask[4];
    unsigned char network[4];
    unsigned char broadcast[4];

    printf("Welcome to the Subnet Calculator!\n");
    printf("Please enter your IP address (e.g. 192.168.0.1): ");
    scanf("%hhu.%hhu.%hhu.%hhu", &ip[0], &ip[1], &ip[2], &ip[3]);

    printf("Please enter your subnet mask (e.g. 255.255.255.0): ");
    scanf("%hhu.%hhu.%hhu.%hhu", &mask[0], &mask[1], &mask[2], &mask[3]);

    calculateNetworkAddress(ip, mask, network);
    calculateBroadcastAddress(ip, mask, broadcast);
    int usableIPs = calculateUsableIPs(mask);

    printf("\nCalculating the details...\n");
    printf("-------------------------------------------------\n");
    printf("Your IP Address: ");
    printIP(ip);
    printf("Your Subnet Mask: ");
    printIP(mask);
    printf("Network Address: ");
    printIP(network);
    printf("Broadcast Address: ");
    printIP(broadcast);
    printf("Usable IP Addresses: %d\n", usableIPs);
    printf("-------------------------------------------------\n");

    printf("Thank you for using the Subnet Calculator. Hope you find it insightful!\n");

    return 0;
}