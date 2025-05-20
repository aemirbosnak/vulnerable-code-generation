//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#define MAX_ADDR_LEN 16
#define MAX_SUBNET_LEN 3

void printBinary(uint32_t num);
uint32_t convertToDecimal(const char *ip);
void calculateSubnet(const char *ip, const char *subnetMask);
void parseSubnetMask(const char *mask, uint32_t *maskBinary, uint32_t *subnetSize);
uint32_t getBroadcastAddress(uint32_t ipDecimal, uint32_t maskDecimal);
uint32_t getNetworkAddress(uint32_t ipDecimal, uint32_t maskDecimal);
void convertToDottedDecimal(uint32_t num, char *buffer);

int main() {
    char ip[MAX_ADDR_LEN];
    char subnetMask[MAX_SUBNET_LEN];

    printf("C Subnet Calculator\n");
    printf("===================\n");

    printf("Enter IP Address (e.g., 192.168.1.1): ");
    fgets(ip, sizeof(ip), stdin);
    ip[strcspn(ip, "\n")] = 0; // Remove newline

    printf("Enter Subnet Mask (e.g., 255.255.255.0): ");
    fgets(subnetMask, sizeof(subnetMask), stdin);
    subnetMask[strcspn(subnetMask, "\n")] = 0; // Remove newline

    calculateSubnet(ip, subnetMask);
    
    return 0;
}

void printBinary(uint32_t num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 8 == 0 && i != 0) printf(" ");
    }
    printf("\n");
}

uint32_t convertToDecimal(const char *ip) {
    uint32_t decimal = 0;
    int octet;
    
    for (int i = 0; i < 4; i++) {
        if (sscanf(ip, "%d.", &octet) != 1)
            return 0; // error in IP format
        decimal = (decimal << 8) | (octet & 0xFF);
        ip = strchr(ip, '.') ? strchr(ip, '.') + 1 : NULL; // Move to next part
    }
    return decimal;
}

void calculateSubnet(const char *ip, const char *subnetMask) {
    uint32_t ipDecimal = convertToDecimal(ip);
    uint32_t maskDecimal;
    uint32_t subnetSize;
    
    parseSubnetMask(subnetMask, &maskDecimal, &subnetSize);
    
    uint32_t networkAddress = getNetworkAddress(ipDecimal, maskDecimal);
    uint32_t broadcastAddress = getBroadcastAddress(ipDecimal, maskDecimal);
    
    char networkBuffer[MAX_ADDR_LEN];
    char broadcastBuffer[MAX_ADDR_LEN];
    
    convertToDottedDecimal(networkAddress, networkBuffer);
    convertToDottedDecimal(broadcastAddress, broadcastBuffer);
    
    printf("\nResults:\n");
    printf("Network Address: %s\n", networkBuffer);
    printf("Broadcast Address: %s\n", broadcastBuffer);
    printf("Subnet Size: /%d\n", subnetSize);
    
    printf("\nIP in Binary: ");
    printBinary(ipDecimal);
    printf("Subnet Mask in Binary: ");
    printBinary(maskDecimal);
    printf("Network Address in Binary: ");
    printBinary(networkAddress);
    printf("Broadcast Address in Binary: ");
    printBinary(broadcastAddress);
}

void parseSubnetMask(const char *mask, uint32_t *maskBinary, uint32_t *subnetSize) {
    if (sscanf(mask, "%u.%u.%u.%u", &maskBinary[0], &maskBinary[1], &maskBinary[2], &maskBinary[3]) != 4) {
        *maskBinary = 0; // error in subnet format
        *subnetSize = 0;
        return;
    }

    *maskBinary = convertToDecimal(mask);
    *subnetSize = 0;

    while (*maskBinary) {
        (*maskBinary) >>= 1;
        (*subnetSize)++;
    }
}

uint32_t getBroadcastAddress(uint32_t ipDecimal, uint32_t maskDecimal) {
    return (ipDecimal & maskDecimal) | ~maskDecimal;
}

uint32_t getNetworkAddress(uint32_t ipDecimal, uint32_t maskDecimal) {
    return ipDecimal & maskDecimal;
}

void convertToDottedDecimal(uint32_t num, char *buffer) {
    sprintf(buffer, "%u.%u.%u.%u",
            (num >> 24) & 0xFF,
            (num >> 16) & 0xFF,
            (num >> 8) & 0xFF,
            num & 0xFF);
}