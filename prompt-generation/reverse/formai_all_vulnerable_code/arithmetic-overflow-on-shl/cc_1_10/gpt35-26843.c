//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_OCTETS 4
#define MAX_OCTET_VAL 255

// Function to get decimal value of an IP address octet
int getDecimal(unsigned char octet[]) {
    return (int) strtol(octet, NULL, 10);
}

// Function to calculate subnet mask based on CIDR notation
char* calculateSubnetMask(int cidr) {
    int octet = cidr / NUM_OCTETS;
    int bits = cidr % NUM_OCTETS;
    int i;
    unsigned int mask = 0;

    // Calculate mask using bitwise left shift operations
    for (i = 0; i < bits; i++) {
        mask |= (1 << (MAX_OCTET_VAL - i));
    }
    char* subnetMask = (char*) malloc(NUM_OCTETS + 1);
    for (i = 0; i < octet; i++) {
        sprintf(subnetMask, "%s255.", subnetMask);
    }
    sprintf(subnetMask, "%s%d", subnetMask, mask >> (MAX_OCTET_VAL - bits));
    for (i = octet + 1; i < NUM_OCTETS; i++) {
        sprintf(subnetMask, "%s.0", subnetMask);
    }
    return subnetMask;
}

int main() {
    char ipAddressStr[16];
    int cidr;

    printf("Enter IP address in dotted decimal format (xxx.xxx.xxx.xxx): ");
    scanf("%s", ipAddressStr);

    // Parse IP address string into octets
    char* octetStr = strtok(ipAddressStr, ".");
    unsigned char octet[NUM_OCTETS];
    int count = 0;
    while (octetStr) {
        octet[count] = (unsigned char) getDecimal(octetStr);
        count++;
        octetStr = strtok(NULL, ".");
    }

    // Convert octets into 32-bit integer
    unsigned int ipAddress = (octet[0] << 24) | (octet[1] << 16) | (octet[2] << 8) | octet[3];

    while (cidr < 1 || cidr > 32) {
        printf("Enter subnet mask in CIDR notation (1-32): ");
        scanf("%d", &cidr);
    }

    // Calculate and print subnet mask
    char* subnetMask = calculateSubnetMask(cidr);
    printf("Subnet mask is: %s\n", subnetMask);

    // Calculate and print network address
    unsigned int networkAddress = ipAddress & (subnetMask[0] << 24 | subnetMask[2] << 16 | subnetMask[4] << 8 | subnetMask[6]);
    printf("Network address is: %d.%d.%d.%d\n", networkAddress >> 24, (networkAddress >> 16) & 0xFF, (networkAddress >> 8) & 0xFF, networkAddress & 0xFF);

    free(subnetMask);
    return 0;
}