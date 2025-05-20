//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert IP address to decimal format
long convertIPtoDecimal(char *ipAddress) {
    int a, b, c, d;
    sscanf(ipAddress, "%d.%d.%d.%d", &a, &b, &c, &d);
    long decimal = (a << 24) + (b << 16) + (c << 8) + d;
    return decimal;
}

// Function to convert decimal format to IP address
void convertDecimaltoIP(long decimal, char *ipAddress) {
    sprintf(ipAddress, "%d.%d.%d.%d", (int)((decimal >> 24) & 255), (int)((decimal >> 16) & 255), (int)((decimal >> 8) & 255), (int)(decimal & 255));
}

// Function to calculate subnet mask based on prefix length
long calculateSubnetMask(int prefixLength) {
    long mask = 0xffffffff;
    mask <<= (32 - prefixLength);
    return mask;
}

int main() {
    char ipAddress[16], subnetMask[16], networkAddress[16], broadcastAddress[16];
    int prefixLength;

    // Get input from user
    printf("Enter IP address: ");
    fgets(ipAddress, 16, stdin);
    ipAddress[strlen(ipAddress) - 1]='\0'; // Remove newline character from input
    printf("Enter prefix length: ");
    scanf("%d", &prefixLength);

    // Calculate subnet mask, network address, and broadcast address
    long decimalIP = convertIPtoDecimal(ipAddress);
    long decimalSubnetMask = calculateSubnetMask(prefixLength);
    long decimalNetworkAddress = decimalIP & decimalSubnetMask;
    long decimalBroadcastAddress = decimalNetworkAddress | ~decimalSubnetMask;

    // Convert decimal format to IP address format
    convertDecimaltoIP(decimalSubnetMask, subnetMask);
    convertDecimaltoIP(decimalNetworkAddress, networkAddress);
    convertDecimaltoIP(decimalBroadcastAddress, broadcastAddress);

    // Print results
    printf("Subnet mask: %s\n", subnetMask);
    printf("Network address: %s\n", networkAddress);
    printf("Broadcast address: %s\n", broadcastAddress);

    return 0;
}