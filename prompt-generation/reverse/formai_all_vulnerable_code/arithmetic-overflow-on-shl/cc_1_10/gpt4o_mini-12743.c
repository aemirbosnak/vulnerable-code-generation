//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Function Declarations
void calculateSubnet(const char* ip, const char* cidr);
void printBinary(uint32_t num);
void ipToBinary(const char* ip, uint32_t* binary);
void binaryToIp(uint32_t binary, char* ip);
void calculateNetworkAddress(uint32_t ipBinary, uint32_t maskBinary, uint32_t* network);
void calculateBroadcastAddress(uint32_t networkBinary, uint32_t maskBinary, uint32_t* broadcast);
void calculateUsableHosts(uint32_t maskBinary);

int main() {
    char ip[16];
    char cidr[4];

    printf("Welcome to the C Subnet Calculator!\n");
    printf("Please enter an IP address (e.g. 192.168.1.1): ");
    fgets(ip, sizeof(ip), stdin);
    ip[strcspn(ip, "\n")] = 0; // Remove newline character

    printf("Please enter the CIDR notation (e.g. 24): ");
    fgets(cidr, sizeof(cidr), stdin);
    cidr[strcspn(cidr, "\n")] = 0; // Remove newline character

    calculateSubnet(ip, cidr);

    return 0;
}

void calculateSubnet(const char* ip, const char* cidr) {
    uint32_t ipBinary = 0;
    uint32_t maskBinary = 0xFFFFFFFF << (32 - atoi(cidr));
    uint32_t networkAddress = 0;
    uint32_t broadcastAddress = 0;

    ipToBinary(ip, &ipBinary);
    calculateNetworkAddress(ipBinary, maskBinary, &networkAddress);
    calculateBroadcastAddress(networkAddress, maskBinary, &broadcastAddress);

    char networkIP[16], broadcastIP[16];
    binaryToIp(networkAddress, networkIP);
    binaryToIp(broadcastAddress, broadcastIP);

    printf("Subnet Information:\n");
    printf("IP Address: %s\n", ip);
    printf("CIDR Notation: /%s\n", cidr);
    printf("Subnet Mask: ", cidr);
    printBinary(maskBinary);
    printf("Network Address: %s\n", networkIP);
    printf("Broadcast Address: %s\n", broadcastIP);
    calculateUsableHosts(maskBinary);
}

void printBinary(uint32_t num) {
    for (int i = 31; i >= 0; i--) {
        printf("%c", (num & (1 << i)) ? '1' : '0');
        if (i % 8 == 0) {
            printf(" "); // Add space every byte for clarity
        }
    }
    printf("\n");
}

void ipToBinary(const char* ip, uint32_t* binary) {
    uint8_t bytes[4];
    sscanf(ip, "%hhu.%hhu.%hhu.%hhu", &bytes[0], &bytes[1], &bytes[2], &bytes[3]);
    *binary = (bytes[0] << 24) | (bytes[1] << 16) | (bytes[2] << 8) | bytes[3];
}

void binaryToIp(uint32_t binary, char* ip) {
    sprintf(ip, "%u.%u.%u.%u",
        (binary >> 24) & 0xFF,
        (binary >> 16) & 0xFF,
        (binary >> 8) & 0xFF,
        binary & 0xFF);
}

void calculateNetworkAddress(uint32_t ipBinary, uint32_t maskBinary, uint32_t* network) {
    *network = ipBinary & maskBinary;
}

void calculateBroadcastAddress(uint32_t networkBinary, uint32_t maskBinary, uint32_t* broadcast) {
    *broadcast = networkBinary | ~maskBinary;
}

void calculateUsableHosts(uint32_t maskBinary) {
    uint32_t hostBits = 32 - __builtin_popcount(maskBinary);
    uint32_t usableHosts = (1 << hostBits) - 2; // Subtracting 2 for network and broadcast addresses
    printf("Usable Hosts: %u\n", usableHosts);
}