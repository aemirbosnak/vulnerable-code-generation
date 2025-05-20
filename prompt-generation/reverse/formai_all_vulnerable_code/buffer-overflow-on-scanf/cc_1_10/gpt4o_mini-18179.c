//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

// Function prototypes
void calculateSubnet(char *ipAddress, char *subnetMask);
void convertToBinary(unsigned int num, char *binary);
void printSubnetDetails(char *networkAddress, char *broadcastAddress, int totalHosts);

int main() {
    char ipAddress[16];
    char subnetMask[16];

    printf("Welcome to the C Subnet Calculator!\n");
    printf("Enter an IP Address (e.g., 192.168.1.1): ");
    scanf("%s", ipAddress);
    printf("Enter Subnet Mask (e.g., 255.255.255.0): ");
    scanf("%s", subnetMask);

    calculateSubnet(ipAddress, subnetMask);
    
    return 0;
}

void calculateSubnet(char *ipAddress, char *subnetMask) {
    struct in_addr ipAddr;
    struct in_addr netMask;
    struct in_addr netAddress;
    struct in_addr broadcastAddress;

    // Convert string IP and Subnet mask to binary
    inet_pton(AF_INET, ipAddress, &ipAddr);
    inet_pton(AF_INET, subnetMask, &netMask);

    // Calculate network address
    netAddress.s_addr = ipAddr.s_addr & netMask.s_addr;

    // Calculate broadcast address
    broadcastAddress.s_addr = netAddress.s_addr | ~netMask.s_addr;

    // Calculate total hosts using subnet mask
    int numberOfOnes = 0;
    for (int i = 0; i < 32; i++) {
        if ((ntohl(netMask.s_addr) >> i) & 1) {
            numberOfOnes++;
        }
    }
    int totalHosts = (1 << (32 - numberOfOnes)) - 2; // -2 for network and broadcast addresses

    // Print results
    char networkStr[16];
    char broadcastStr[16];
    inet_ntop(AF_INET, &netAddress, networkStr, sizeof(networkStr));
    inet_ntop(AF_INET, &broadcastAddress, broadcastStr, sizeof(broadcastStr));

    printf("\n--- Subnet Details ---\n");
    printSubnetDetails(networkStr, broadcastStr, totalHosts);
}

void convertToBinary(unsigned int num, char *binary) {
    for (int i = 31; i >= 0; i--) {
        binary[i] = (num & 1) ? '1' : '0';
        num >>= 1;
    }
    binary[32] = '\0'; // Null-terminate the string
}

void printSubnetDetails(char *networkAddress, char *broadcastAddress, int totalHosts) {
    printf("Network Address: %s\n", networkAddress);
    printf("Broadcast Address: %s\n", broadcastAddress);
    printf("Total Number of Usable Hosts: %d\n", totalHosts);
}