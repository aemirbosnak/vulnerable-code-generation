//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_MASK 32

typedef struct _IPAddress {
    unsigned int octet1;
    unsigned int octet2;
    unsigned int octet3;
    unsigned int octet4;
} IPAddress;

void printIPAddress(IPAddress ip) {
    printf("%u.%u.%u.%u", ip.octet1, ip.octet2, ip.octet3, ip.octet4);
}

void printNetmask(IPAddress mask) {
    unsigned int maskOctets[4];
    maskOctets[0] = mask.octet1;
    maskOctets[1] = mask.octet2;
    maskOctets[2] = mask.octet3;
    maskOctets[3] = mask.octet4;

    int maskLength = 0;
    for (int i = 0; i < 4; i++) {
        int bits = 8;
        while (maskOctets[i] != 0 && bits > 0) {
            maskOctets[i] <<= 1;
            bits--;
            maskLength++;
        }
    }

    printIPAddress(mask);
    printf(" (%d)", maskLength);
}

IPAddress getNetmask(int length) {
    IPAddress mask = {0};
    int remainingBits = length;

    while (remainingBits > 0) {
        if (remainingBits >= 8) {
            mask.octet1 = 255;
            remainingBits -= 8;
        } else {
            unsigned int octetMask = (unsigned int) pow(2, remainingBits) - 1;
            octetMask <<= (8 - remainingBits);
            switch (remainingBits) {
                case 7:
                    mask.octet1 = octetMask;
                    break;
                case 6:
                    mask.octet2 = octetMask;
                    break;
                case 5:
                    mask.octet3 = octetMask;
                    break;
                case 4:
                    mask.octet4 = octetMask;
                    break;
            }
            remainingBits = 0;
        }
    }

    return mask;
}

IPAddress getNetworkAddress(IPAddress ip, IPAddress mask) {
    IPAddress network = {0};

    network.octet1 = ip.octet1 & mask.octet1;
    network.octet2 = ip.octet2 & mask.octet2;
    network.octet3 = ip.octet3 & mask.octet3;
    network.octet4 = ip.octet4 & mask.octet4;

    return network;
}

int main() {
    // Get input from user
    char inputIP[16];
    int inputMaskLength;
    printf("Enter IP address in dotted decimal format: ");
    scanf("%15s", inputIP);
    printf("Enter CIDR mask length (1-%d): ", MAX_MASK);
    scanf("%d", &inputMaskLength);

    // Parse input IP
    IPAddress ip = {0};
    sscanf(inputIP, "%u.%u.%u.%u", &ip.octet1, &ip.octet2, &ip.octet3, &ip.octet4);

    // Calculate netmask and network address
    IPAddress mask = getNetmask(inputMaskLength);
    IPAddress network = getNetworkAddress(ip, mask);

    // Print output
    printf("IP address: ");
    printIPAddress(ip);
    printf("\n");
    printf("Netmask: ");
    printNetmask(mask);
    printf("\n");
    printf("Network address: ");
    printIPAddress(network);
    printf("\n");

    return 0;
}