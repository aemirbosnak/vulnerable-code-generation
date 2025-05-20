//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IP 32

int charToInt(char c) {
    return (c - '0');
}

int validateIP(const char *ip) {
    int parts[4] = {0, 0, 0, 0}; // initialize ints to 0
    int partCount = 0;

    char ch;

    while ((ch = *ip++)) {
        if (ch >= '0' && ch <= '9') {
            parts[partCount] = parts[partCount] * 10 + charToInt(ch);
        } else if (ch == '.') {
            ++partCount;
        } else {
            return 0;
        }
    }

    if (partCount != 3) {
        return 0;
    }

    for (int i = 0; i < 4; ++i) {
        if (parts[i] < 0 || parts[i] > 255) {
            return 0;
        }
    }

    return 1;
}

int calculateSubnetMask(int mask) {
    int subnetMask = 0;
    for (int i = 0; i < mask; ++i) {
        subnetMask |= 1 << (MAX_IP - i - 1);
    }
    return subnetMask;
}

int main() {
    char ipStr[16];
    int mask;

    printf("Enter an IP address: ");
    scanf("%15s", ipStr);

    if (!validateIP(ipStr)) {
        printf("Invalid IP address entered.\n");
        return 1;
    }

    printf("Enter the subnet mask (in bits): ");
    scanf("%d", &mask);

    if (mask < 0 || mask > MAX_IP) {
        printf("Invalid subnet mask entered. Please enter a value between 0 and 32 (inclusive).\n");
        return 1;
    }

    int subnetMask = calculateSubnetMask(mask);

    printf("Subnet mask: %d.%d.%d.%d\n", subnetMask >> 24, (subnetMask >> 16) & 255, (subnetMask >> 8) & 255, subnetMask & 255);

    return 0;
}