//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_SUBNETS 16
#define IP_LENGTH 16
#define MAX_PREFIX_LENGTH 32

typedef struct {
    uint8_t address[4];
    uint8_t netmask;
} Subnet;

void displaySubnetInfo(Subnet subnet, int subnetIndex) {
    printf("Subnet %d:\n", subnetIndex + 1);
    printf("  - IP Address: %d.%d.%d.%d\n", subnet.address[0], subnet.address[1], subnet.address[2], subnet.address[3]);
    printf("  - Subnet Mask: ");
    for (int i = 0; i < 4; i++) {
        if (i > 0) printf(".");
        printf("%d", (subnet.netmask == 32) ? 255 : (subnet.netmask == 31) ? 255 : (subnet.netmask == 30) ? 255 :
               (subnet.netmask >= 29) ? 255 - (1 << (32 - subnet.netmask)) * (i - 1) :
               (subnet.netmask >= 28) ? 255 - (1 << (32 - subnet.netmask)) * (i - 2) :
               (subnet.netmask >= 27) ? 255 - (1 << (32 - subnet.netmask)) * (i - 3) : 
               0);
    }
    printf("\n");
}

uint32_t ipToDecimal(const char *ipStr) {
    uint32_t ipDecimal = 0;
    uint8_t octets[4];
    sscanf(ipStr, "%hhu.%hhu.%hhu.%hhu", &octets[0], &octets[1], &octets[2], &octets[3]);
    for (int i = 0; i < 4; i++) {
        ipDecimal = (ipDecimal << 8) | octets[i];
    }
    return ipDecimal;
}

void decimalToIp(uint32_t ipDecimal, char *ipStr) {
    sprintf(ipStr, "%d.%d.%d.%d", 
            (ipDecimal >> 24) & 0xFF, 
            (ipDecimal >> 16) & 0xFF, 
            (ipDecimal >> 8) & 0xFF, 
            ipDecimal & 0xFF);
}

void calculateSubnets(const char *ipInput, uint8_t netmask) {
    Subnet subnets[MAX_SUBNETS];
    uint32_t baseIpDecimal = ipToDecimal(ipInput);

    for (int i = 0; i < MAX_SUBNETS; i++) {
        subnets[i].netmask = netmask;
        subnets[i].address[0] = (baseIpDecimal >> 24) & 0xFF;
        subnets[i].address[1] = (baseIpDecimal >> 16) & 0xFF;
        subnets[i].address[2] = (baseIpDecimal >> 8) & 0xFF;
        subnets[i].address[3] = baseIpDecimal & 0xFF;

        // Example logic to increment the subnet for simplicity
        baseIpDecimal += (1 << (32 - netmask));
    }

    for (int i = 0; i < MAX_SUBNETS; i++) {
        displaySubnetInfo(subnets[i], i);
    }
}

void getInputAndCalculate() {
    char ip[IP_LENGTH];
    uint8_t prefixLength;

    printf("Enter the network IP address (e.g. 192.168.1.0): ");
    fgets(ip, IP_LENGTH, stdin);
    ip[strcspn(ip, "\n")] = 0;  // Remove newline character

    printf("Enter the subnet prefix length (e.g. 24): ");
    scanf("%hhu", &prefixLength);

    if (prefixLength > MAX_PREFIX_LENGTH) {
        printf("Invalid prefix length!\n");
        exit(EXIT_FAILURE);
    }

    calculateSubnets(ip, prefixLength);
}

int main() {
    printf("Welcome to the C Subnet Calculator!\n");
    getInputAndCalculate();
    return 0;
}