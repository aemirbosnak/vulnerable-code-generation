//MISTRAL-7B DATASET v1.0 Category: Subnet Calculator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char byte1;
    unsigned char byte2;
    unsigned char byte3;
    unsigned char byte4;
} IPv4Address;

void printIPv4Address(IPv4Address ipAddress) {
    printf("%u.%u.%u.%u", ipAddress.byte1, ipAddress.byte2, ipAddress.byte3, ipAddress.byte4);
}

IPv4Address stringToIPv4Address(char* ipAddressString) {
    IPv4Address ipAddress;
    sscanf(ipAddressString, "%hhu.%hhu.%hhu.%hhu", &ipAddress.byte1, &ipAddress.byte2, &ipAddress.byte3, &ipAddress.byte4);
    return ipAddress;
}

IPv4Address subnetMaskToNetworkAddress(char* subnetMaskString) {
    IPv4Address networkAddress;
    unsigned char ones = 0;

    memset(&networkAddress, 0xFF, sizeof(IPv4Address));

    sscanf(subnetMaskString, "%hhu.%hhu.%hhu.%hhu", &ones, &ones, &ones, &ones);

    networkAddress.byte1 &= ~(0xFF << (8 * (3 - (subnetMaskString[0] > '0'))));
    networkAddress.byte2 &= ~(0xFF << (8 * (3 - (subnetMaskString[4] > '0'))));
    networkAddress.byte3 &= ~(0xFF << (8 * (3 - (subnetMaskString[7] > '0'))));
    networkAddress.byte4 &= ~(0xFF << (8 * (3 - (subnetMaskString[10] > '0'))));

    return networkAddress;
}

IPv4Address calculateSubnetAddress(IPv4Address ipAddress, IPv4Address subnetMask) {
    IPv4Address subnetAddress;

    subnetAddress.byte1 = ipAddress.byte1 & subnetMask.byte1;
    subnetAddress.byte2 = ipAddress.byte2 & subnetMask.byte2;
    subnetAddress.byte3 = ipAddress.byte3 & subnetMask.byte3;
    subnetAddress.byte4 = ipAddress.byte4 & subnetMask.byte4;

    return subnetAddress;
}

void printSubnet(IPv4Address subnetAddress, IPv4Address subnetMask) {
    printf("Subnet Address: ");
    printIPv4Address(subnetAddress);
    printf("\nSubnet Mask: ");
    printIPv4Address(subnetMask);
    printf("\n");
}

int main() {
    char ipAddressString[16], subnetMaskString[16];

    printf("Enter IPv4 address: ");
    scanf("%s", ipAddressString);
    IPv4Address ipAddress = stringToIPv4Address(ipAddressString);

    printf("Enter Subnet Mask: ");
    scanf("%s", subnetMaskString);
    IPv4Address subnetMask = subnetMaskToNetworkAddress(subnetMaskString);

    IPv4Address subnetAddress = calculateSubnetAddress(ipAddress, subnetMask);

    printSubnet(subnetAddress, subnetMask);

    return 0;
}