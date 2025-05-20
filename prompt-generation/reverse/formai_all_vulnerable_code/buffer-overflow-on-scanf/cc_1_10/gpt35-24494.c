//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isValidIpAddress(char *ipAddress) {
    int num, dotCount = 0;
    char *ptr, *start;

    if (ipAddress == NULL) {
        return 0;
    }

    ptr = ipAddress;
    start = ipAddress;
    while (*ptr != '\0') {
        if (*ptr == '.') {
            dotCount++;
            if (dotCount > 3) {
                return 0;
            }
            *ptr = '\0';
            num = atoi(start);
            if (num < 0 || num > 255) {
                return 0;
            }
            start = ptr + 1;
        }
        ptr++;
    }
    num = atoi(start);
    if (num < 0 || num > 255 || dotCount != 3) {
        return 0;
    }
    return 1;
}

int getSubnetMask(int bitCount) {
    int subnetMask = 0x80000000;
    while (bitCount > 0) {
        subnetMask = (subnetMask >> 1) | 0x80000000;
        bitCount--;
    }
    return subnetMask;
}

int getNetworkBits(int subnetMask) {
    int networkBits = 0;
    while (subnetMask != 0) {
        if ((subnetMask & 0x80000000) == 0) {
            break;
        }
        networkBits++;
        subnetMask <<= 1;
    }
    return networkBits;
}

int getHostBits(int subnetMask) {
    int hostBits = 0;
    while (subnetMask != 0) {
        if ((subnetMask & 0x80000000) != 0) {
            break;
        }
        hostBits++;
        subnetMask <<= 1;
    }
    return hostBits;
}

void printBinary(int num, int bitCount) {
    int mask = 0x80000000;
    while (bitCount > 0) {
        if (num & mask) {
            printf("1");
        }
        else {
            printf("0");
        }
        mask >>= 1;
        bitCount--;
    }
    printf("\n");
}

int main() {
    char ipAddress[20];
    int subnetMask, networkBits, hostBits;

    printf("Enter IP Address: ");
    scanf("%s", ipAddress);
    if (!isValidIpAddress(ipAddress)) {
        printf("Invalid IP Address!\n");
        return 1;
    }

    printf("Enter Subnet Mask Bit Count: ");
    scanf("%d", &subnetMask);
    if (subnetMask < 0 || subnetMask > 32) {
        printf("Invalid Subnet Mask Bit Count!\n");
        return 1;
    }

    subnetMask = getSubnetMask(subnetMask);
    printf("Subnet Mask (Binary): ");
    printBinary(subnetMask, 32);
    printf("Subnet Mask (Decimal): %d.%d.%d.%d\n", 
        (subnetMask >> 24) & 0xFF, (subnetMask >> 16) & 0xFF, 
        (subnetMask >> 8) & 0xFF, subnetMask & 0xFF);

    networkBits = getNetworkBits(subnetMask);
    printf("Network Bits: %d\n", networkBits);

    hostBits = getHostBits(subnetMask);
    printf("Host Bits: %d\n", hostBits);

    return 0;
}