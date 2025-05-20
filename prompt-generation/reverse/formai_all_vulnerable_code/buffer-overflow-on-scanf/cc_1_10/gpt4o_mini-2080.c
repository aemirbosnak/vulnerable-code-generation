//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_SUBNET_BITS 32
#define DEFAULT_NETMASK 24
#define IP_SIZE 4

void printBinary(uint32_t num) {
    for (int i = MAX_SUBNET_BITS - 1; i >= 0; i--) {
        printf("%u", (num >> i) & 1);
        if (i % 8 == 0) printf(" ");
    }
    printf("\n");
}

uint32_t ipToDecimal(uint8_t ip[IP_SIZE]) {
    uint32_t decimal = 0;
    for (int i = 0; i < IP_SIZE; i++) {
        decimal = (decimal << 8) + ip[i];
    }
    return decimal;
}

void decimalToIp(uint32_t decimal, uint8_t ip[IP_SIZE]) {
    for (int i = IP_SIZE - 1; i >= 0; i--) {
        ip[i] = decimal & 0xFF;
        decimal >>= 8;
    }
}

void calculateSubnet(uint32_t ip, uint32_t mask, uint32_t *network, uint32_t *broadcast) {
    *network = ip & mask;
    *broadcast = *network | ~mask;
}

void displayResults(uint32_t ip, uint32_t mask, uint32_t network, uint32_t broadcast) {
    uint8_t ipArray[IP_SIZE] = {0}, maskArray[IP_SIZE] = {0};
    uint8_t netArray[IP_SIZE] = {0}, broaArray[IP_SIZE] = {0};

    decimalToIp(ip, ipArray);
    decimalToIp(mask, maskArray);
    decimalToIp(network, netArray);
    decimalToIp(broadcast, broaArray);

    printf("IP Address: %d.%d.%d.%d\n", ipArray[0], ipArray[1], ipArray[2], ipArray[3]);
    printf("Subnet Mask: %d.%d.%d.%d\n", maskArray[0], maskArray[1], maskArray[2], maskArray[3]);
    printf("Network Address: %d.%d.%d.%d\n", netArray[0], netArray[1], netArray[2], netArray[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broaArray[0], broaArray[1], broaArray[2], broaArray[3]);
}

void getSubnetInfo() {
    uint8_t ipArray[IP_SIZE] = {0};
    uint32_t subnetBits;
    uint32_t ip, mask = 0xFFFFFFFF << (MAX_SUBNET_BITS - DEFAULT_NETMASK);
    uint32_t network, broadcast;

    printf("Enter the IP Address (e.g., 192.168.1.1): ");
    scanf("%hhu.%hhu.%hhu.%hhu", &ipArray[0], &ipArray[1], &ipArray[2], &ipArray[3]);
    ip = ipToDecimal(ipArray);

    printf("You can specify the subnet mask in bits (default is %d): ", DEFAULT_NETMASK);
    scanf("%u", &subnetBits);
    if (subnetBits > 0 && subnetBits <= MAX_SUBNET_BITS) {
        mask = 0xFFFFFFFF << (MAX_SUBNET_BITS - subnetBits);
    } else {
        printf("Invalid subnet bits, using default subnet mask of %d\n", DEFAULT_NETMASK);
    }

    calculateSubnet(ip, mask, &network, &broadcast);
    displayResults(ip, mask, network, broadcast);
}

int main() {
    int running = 1;

    while (running) {
        printf("---- Subnet Calculator ----\n");
        getSubnetInfo();

        char choice;
        printf("Do you want to calculate another subnet? (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y' && choice != 'Y') {
            running = 0;
        }
    }
    printf("Thank you for using the Subnet Calculator!\n");
    return 0;
}