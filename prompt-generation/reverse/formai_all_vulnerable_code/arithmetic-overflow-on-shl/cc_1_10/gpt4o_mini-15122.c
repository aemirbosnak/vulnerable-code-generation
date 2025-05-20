//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#define MAX_SUBNET_MASK 30
#define MAX_OCTETS 4

void calculateSubnet(uint32_t ip, uint32_t subnetMask, uint32_t *subnet, uint32_t *broadcast, uint32_t *firstHost, uint32_t *lastHost) {
    uint32_t subnetMaskBinary = ~(((1 << (32 - subnetMask)) - 1));
    *subnet = (ip & subnetMaskBinary);
    *broadcast = *subnet | ((1 << (32 - subnetMask)) - 1);
    *firstHost = *subnet + 1;
    *lastHost = *broadcast - 1;
}

void printBinary(uint32_t num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 8 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}

void ipToDecimal(const char *ipStr, uint32_t *ip) {
    int octets[MAX_OCTETS];
    sscanf(ipStr, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]);
    *ip = (octets[0] << 24) | (octets[1] << 16) | (octets[2] << 8) | octets[3];
}

void decimalToIp(uint32_t ip, char *ipStr) {
    sprintf(ipStr, "%u.%u.%u.%u", (ip >> 24) & 0xFF, (ip >> 16) & 0xFF, (ip >> 8) & 0xFF, ip & 0xFF);
}

void displayResults(uint32_t ip, uint32_t subnetMask, uint32_t subnet, uint32_t broadcast, uint32_t firstHost, uint32_t lastHost) {
    char ipStr[16], subnetStr[16], broadcastStr[16], firstHostStr[16], lastHostStr[16];

    decimalToIp(ip, ipStr);
    decimalToIp(subnet, subnetStr);
    decimalToIp(broadcast, broadcastStr);
    decimalToIp(firstHost, firstHostStr);
    decimalToIp(lastHost, lastHostStr);

    printf("IP Address:         %s\n", ipStr);
    printf("Subnet Mask CIDR:   /%u\n", subnetMask);
    printf("Subnet Address:     %s\n", subnetStr);
    printf("Broadcast Address:  %s\n", broadcastStr);
    printf("First Host:        %s\n", firstHostStr);
    printf("Last Host:         %s\n", lastHostStr);
}

int main() {
    char ipStr[16];
    uint32_t ip, subnet, broadcast, firstHost, lastHost;
    int subnetMask;

    printf("Welcome to the C Subnet Calculator!\n");
    printf("Please enter an IP address (e.g. 192.168.1.1): ");
    fgets(ipStr, sizeof(ipStr), stdin);
    ipStr[strcspn(ipStr, "\n")] = 0; // Remove the newline character 

    printf("Please enter a subnet mask (CIDR notation, e.g. 24): ");
    scanf("%d", &subnetMask);
    
    if (subnetMask < 1 || subnetMask > MAX_SUBNET_MASK) {
        fprintf(stderr, "Error: Subnet mask must be between 1 and %d.\n", MAX_SUBNET_MASK);
        return EXIT_FAILURE;
    }

    ipToDecimal(ipStr, &ip);
    calculateSubnet(ip, subnetMask, &subnet, &broadcast, &firstHost, &lastHost);
    displayResults(ip, subnetMask, subnet, broadcast, firstHost, lastHost);
    
    printf("\nBinary Representation:\n");
    printf("IP Address:         ");
    printBinary(ip);
    printf("Subnet Mask:        ");
    printBinary(~(((1 << (32 - subnetMask)) - 1)));
    printf("Subnet Address:     ");
    printBinary(subnet);
    printf("Broadcast Address:  ");
    printBinary(broadcast);
    printf("First Host:        ");
    printBinary(firstHost);
    printf("Last Host:         ");
    printBinary(lastHost);

    return EXIT_SUCCESS;
}