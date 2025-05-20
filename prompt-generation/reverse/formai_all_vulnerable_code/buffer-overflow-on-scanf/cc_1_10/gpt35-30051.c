//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate subnet mask based on prefix length
void calculateSubnetMask(int prefixLength, char *subnetMask) {
    int i, j, k, value;
    char part[8] = "11111111";

    for (i = 0; i < 4; i++) {
        if (prefixLength >= 8) {
            prefixLength -= 8;
            subnetMask[i] = 255;
        } else {
            for (j = 0; j < prefixLength; j++) {
                part[j] = '1';
            }
            value = strtol(part, NULL, 2);
            subnetMask[i] = (unsigned char) value;
            prefixLength = 0;
        }
    }
}

// Function to calculate network address based on IP address and subnet mask
void calculateNetworkAddress(char *ipAddress, char *subnetMask, char *networkAddress) {
    int i;
    char octetIpAddress[4][4];
    char octetSubnetMask[4][4];
    char octetNetworkAddress[4][4];

    // Split IP address into octets
    sscanf(ipAddress, "%[^'.'].%[^'.'].%[^'.'].%[^'.']", octetIpAddress[0], octetIpAddress[1], octetIpAddress[2], octetIpAddress[3]);

    // Split subnet mask into octets
    sscanf(subnetMask, "%[^'.'].%[^'.'].%[^'.'].%[^'.']", octetSubnetMask[0], octetSubnetMask[1], octetSubnetMask[2], octetSubnetMask[3]);

    // Calculate network address by ANDing IP address with subnet mask
    for (i = 0; i < 4; i++) {
        octetNetworkAddress[i][0] = (char) ((unsigned char) strtol(octetIpAddress[i], NULL, 10) & (unsigned char) strtol(octetSubnetMask[i], NULL, 10));
    }

    sprintf(networkAddress, "%d.%d.%d.%d", (int) octetNetworkAddress[0][0], (int) octetNetworkAddress[1][0], (int) octetNetworkAddress[2][0], (int) octetNetworkAddress[3][0]);
}

// Function to calculate maximum number of hosts based on prefix length
int calculateMaxHosts(int prefixLength) {
    return (1 << (32 - prefixLength)) - 2;
}

int main() {
    char ipAddress[16], subnetMask[16], networkAddress[16];
    int prefixLength, maxHosts;

    printf("Enter IP address: ");
    fgets(ipAddress, 16, stdin);
    ipAddress[strcspn(ipAddress, "\r\n")] = 0;

    printf("Enter prefix length: ");
    scanf("%d", &prefixLength);

    // Calculate subnet mask
    memset(subnetMask, 0, 16);
    calculateSubnetMask(prefixLength, subnetMask);
    printf("Subnet mask: %s\n", subnetMask);

    // Calculate network address
    memset(networkAddress, 0, 16);
    calculateNetworkAddress(ipAddress, subnetMask, networkAddress);
    printf("Network address: %s\n", networkAddress);

    // Calculate maximum number of hosts
    maxHosts = calculateMaxHosts(prefixLength);
    printf("Maximum number of hosts: %d\n", maxHosts);

    return 0;
}