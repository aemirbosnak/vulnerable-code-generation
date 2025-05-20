//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void calculateSubnet(char *ipAddress, char *subnetMask);
void splitIP(char *ipAddress, int *octets);
void printResult(char *ipAddress, char *subnetMask, int *subnetAddr, int *broadcastAddr, int *usableStartAddr, int *usableEndAddr);

int main() {
    char ipAddress[16];
    char subnetMask[16];

    // Get user input
    printf("Welcome to the C Subnet Calculator!\n");
    printf("Enter the IP Address (e.g., 192.168.1.1): ");
    scanf("%s", ipAddress);
    printf("Enter the Subnet Mask (e.g., 255.255.255.0): ");
    scanf("%s", subnetMask);

    // Call the subnet calculation function
    calculateSubnet(ipAddress, subnetMask);
    
    return 0;
}

void calculateSubnet(char *ipAddress, char *subnetMask) {
    int ipOctets[4], subnetOctets[4];
    int subnetAddr[4], broadcastAddr[4], usableStartAddr[4], usableEndAddr[4];
    
    // Split the IP Address and Subnet Mask into their octets
    splitIP(ipAddress, ipOctets);
    splitIP(subnetMask, subnetOctets);

    // Calculate the subnet address
    for (int i = 0; i < 4; i++) {
        subnetAddr[i] = ipOctets[i] & subnetOctets[i];
        broadcastAddr[i] = subnetAddr[i] | (~subnetOctets[i] & 0xFF);
    }

    // Calculate usable IP addresses (first and last in the subnet)
    for (int i = 0; i < 4; i++) {
        usableStartAddr[i] = subnetAddr[i];
        usableEndAddr[i] = broadcastAddr[i];
    }

    usableStartAddr[3] += 1; // Increment for usable start
    usableEndAddr[3] -= 1; // Decrement for usable end

    // Print the results
    printResult(ipAddress, subnetMask, subnetAddr, broadcastAddr, usableStartAddr, usableEndAddr);
}

void splitIP(char *ipAddress, int *octets) {
    char *token;
    int index = 0;

    // Get each octet from the IP address
    token = strtok(ipAddress, ".");
    while (token != NULL && index < 4) {
        octets[index++] = atoi(token);
        token = strtok(NULL, ".");
    }
}

void printResult(char *ipAddress, char *subnetMask, int *subnetAddr, int *broadcastAddr, int *usableStartAddr, int *usableEndAddr) {
    printf("\n--- Subnet Calculation Results ---\n");
    printf("IP Address: %s\n", ipAddress);
    printf("Subnet Mask: %s\n", subnetMask);
    
    printf("Subnet Address: %d.%d.%d.%d\n", subnetAddr[0], subnetAddr[1], subnetAddr[2], subnetAddr[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcastAddr[0], broadcastAddr[1], broadcastAddr[2], broadcastAddr[3]);
    printf("Usable Addresses: %d.%d.%d.%d - %d.%d.%d.%d\n",
        usableStartAddr[0], usableStartAddr[1], usableStartAddr[2], usableStartAddr[3],
        usableEndAddr[0], usableEndAddr[1], usableEndAddr[2], usableEndAddr[3]);
    
    printf("----------------------------------\n");
}