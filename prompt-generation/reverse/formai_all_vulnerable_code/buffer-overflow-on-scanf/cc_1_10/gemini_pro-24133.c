//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to check if the given IP address is valid
int isValidIP(char *ip) {
    int octets[4];
    int octetCount = 0;
    char *token = strtok(ip, ".");
    while (token != NULL) {
        octets[octetCount++] = atoi(token);
        token = strtok(NULL, ".");
    }
    if (octetCount != 4) {
        return 0;
    }
    for (int i = 0; i < 4; i++) {
        if (octets[i] < 0 || octets[i] > 255) {
            return 0;
        }
    }
    return 1;
}

// Function to calculate the subnet mask
int calculateSubnetMask(int prefixLength) {
    int mask = 0xFFFFFFFF;
    mask = mask << (32 - prefixLength);
    return mask;
}

// Function to calculate the network address
int calculateNetworkAddress(int ip, int mask) {
    return ip & mask;
}

// Function to calculate the broadcast address
int calculateBroadcastAddress(int networkAddress, int mask) {
    return networkAddress | ~mask;
}

// Function to print the results
void printResults(int ip, int mask, int prefixLength, int networkAddress, int broadcastAddress) {
    printf("IP Address: %d.%d.%d.%d\n", (ip >> 24) & 0xFF, (ip >> 16) & 0xFF, (ip >> 8) & 0xFF, ip & 0xFF);
    printf("Subnet Mask: %d.%d.%d.%d\n", (mask >> 24) & 0xFF, (mask >> 16) & 0xFF, (mask >> 8) & 0xFF, mask & 0xFF);
    printf("Prefix Length: %d\n", prefixLength);
    printf("Network Address: %d.%d.%d.%d\n", (networkAddress >> 24) & 0xFF, (networkAddress >> 16) & 0xFF, (networkAddress >> 8) & 0xFF, networkAddress & 0xFF);
    printf("Broadcast Address: %d.%d.%d.%d\n", (broadcastAddress >> 24) & 0xFF, (broadcastAddress >> 16) & 0xFF, (broadcastAddress >> 8) & 0xFF, broadcastAddress & 0xFF);
}

int main() {
    char ip[16];
    int prefixLength;
    printf("Enter the IP address: ");
    scanf("%s", ip);
    if (!isValidIP(ip)) {
        printf("Invalid IP address!\n");
        return 1;
    }
    printf("Enter the prefix length: ");
    scanf("%d", &prefixLength);
    if (prefixLength < 0 || prefixLength > 32) {
        printf("Invalid prefix length!\n");
        return 1;
    }
    int ipAsInteger = inet_addr(ip);
    int mask = calculateSubnetMask(prefixLength);
    int networkAddress = calculateNetworkAddress(ipAsInteger, mask);
    int broadcastAddress = calculateBroadcastAddress(networkAddress, mask);
    printResults(ipAsInteger, mask, prefixLength, networkAddress, broadcastAddress);
    return 0;
}