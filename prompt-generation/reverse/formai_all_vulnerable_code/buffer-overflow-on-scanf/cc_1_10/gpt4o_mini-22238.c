//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_SUBNETS 100

void printBinary(int num) {
    for (int i = 7; i >= 0; i--) {
        putchar((num & (1 << i)) ? '1' : '0');
    }
}

void calculateSubnet(char *ip, int subnetBits) {
    struct in_addr ipAddr;
    inet_pton(AF_INET, ip, &ipAddr);

    unsigned char *ipBytes = (unsigned char *)&ipAddr;
    unsigned char subnetMask[4] = {0};

    for (int i = 0; i < 4; i++) {
        if (subnetBits >= 8) {
            subnetMask[i] = 255;
            subnetBits -= 8;
        } else {
            subnetMask[i] = (unsigned char)(255 << (8 - subnetBits));
            subnetBits = 0;
        }
    }

    unsigned char networkAddress[4] = {0};
    unsigned char broadcastAddress[4] = {0};

    for (int i = 0; i < 4; i++) {
        networkAddress[i] = ipBytes[i] & subnetMask[i];
        broadcastAddress[i] = networkAddress[i] | ~subnetMask[i];
    }

    printf("\nSubnet Information:\n");
    printf("IP Address: %s\n", ip);
    printf("Subnet Mask: %d.%d.%d.%d\n", subnetMask[0], subnetMask[1], subnetMask[2], subnetMask[3]);
    printf("Network Address: %d.%d.%d.%d\n", networkAddress[0], networkAddress[1], networkAddress[2], networkAddress[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcastAddress[0], broadcastAddress[1], broadcastAddress[2], broadcastAddress[3]);

    printf("Binary Representation:\n");
    printf("IP Address: ");
    for (int i = 0; i < 4; i++) {
        printBinary(ipBytes[i]);
        putchar(' ');
    }
    putchar('\n');

    printf("Subnet Mask: ");
    for (int i = 0; i < 4; i++) {
        printBinary(subnetMask[i]);
        putchar(' ');
    }
    putchar('\n');

    printf("Network Address: ");
    for (int i = 0; i < 4; i++) {
        printBinary(networkAddress[i]);
        putchar(' ');
    }
    putchar('\n');

    printf("Broadcast Address: ");
    for (int i = 0; i < 4; i++) {
        printBinary(broadcastAddress[i]);
        putchar(' ');
    }
    putchar('\n');
}

int main() {
    char ip[16];
    int subnetBits;

    printf("C Subnet Calculator\n");
    printf("Enter an IPv4 address (e.g., 192.168.1.1): ");
    scanf("%15s", ip);
    
    printf("Enter the subnet mask in bits (e.g., 24 for 255.255.255.0): ");
    scanf("%d", &subnetBits);

    if (subnetBits < 0 || subnetBits > 32) {
        printf("Invalid subnet mask. It must be between 0 and 32.\n");
        return 1;
    }

    calculateSubnet(ip, subnetBits);

    return 0;
}