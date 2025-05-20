//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayGreeting() {
    printf("🎉 Hello there! Welcome to the Happy Subnet Calculator! 🎉\n");
    printf("✨ Let's make some magic happen with your network! ✨\n\n");
}

void displayInstructions() {
    printf("🔧 Instructions:\n");
    printf("1. Enter an IPv4 address (e.g. 192.168.1.1)\n");
    printf("2. Enter the subnet mask in CIDR notation (e.g. /24)\n");
    printf("Let's go! 🌈\n");
}

unsigned int ipToDecimal(const char* ip) {
    unsigned int decimal = 0;
    int octet[4] = {0};
    sscanf(ip, "%u.%u.%u.%u", &octet[0], &octet[1], &octet[2], &octet[3]);
    decimal = (octet[0] << 24) + (octet[1] << 16) + (octet[2] << 8) + octet[3];
    return decimal;
}

void decimalToIp(unsigned int decimal, char* ip) {
    sprintf(ip, "%u.%u.%u.%u",
        (decimal >> 24) & 0xFF,
        (decimal >> 16) & 0xFF,
        (decimal >> 8) & 0xFF,
        decimal & 0xFF);
}

void calculateSubnet(const char* ip, int cidr) {
    unsigned int decimalIp = ipToDecimal(ip);
    unsigned int mask = (0xFFFFFFFF << (32 - cidr)) & 0xFFFFFFFF;
    unsigned int network = decimalIp & mask;
    unsigned int broadcast = network | ~mask;

    char networkIp[16], broadcastIp[16], subnetMask[16];
    
    decimalToIp(network, networkIp);
    decimalToIp(broadcast, broadcastIp);
    decimalToIp(mask, subnetMask);
    
    int usableHosts = (1 << (32 - cidr)) - 2; // Total hosts minus network and broadcast

    printf("\nHere are your happy results! 🎊\n");
    printf("🌍 Network Address: %s\n", networkIp);
    printf("🎈 Broadcast Address: %s\n", broadcastIp);
    printf("🎉 Subnet Mask: %s\n", subnetMask);
    printf("🕺 Number of Usable Hosts: %d\n", usableHosts);
}

int main() {
    displayGreeting();
    displayInstructions();

    char ip[16];
    char cidrStr[3];
    int cidr;

    printf("\nPlease enter the IPv4 Address: ");
    fgets(ip, sizeof(ip), stdin);
    ip[strcspn(ip, "\n")] = 0; // Remove newline character

    printf("Please enter the Subnet Mask (CIDR notation, e.g. 24): ");
    fgets(cidrStr, sizeof(cidrStr), stdin);
    cidr = atoi(cidrStr);

    if (cidr < 0 || cidr > 32) {
        printf("🚫 Oh no! That CIDR is out of range! Please give a number between 0 and 32 🙁.\n");
        return 1;
    }
    
    calculateSubnet(ip, cidr);

    printf("\nThank you for using the Happy Subnet Calculator! 🎈✨\n");
    printf("Have a wonderful day! 🌻😊\n");
    
    return 0;
}