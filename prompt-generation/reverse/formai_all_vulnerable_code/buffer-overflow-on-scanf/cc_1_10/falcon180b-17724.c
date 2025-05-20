//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to validate IP address
int validateIP(char* ip) {
    int i = 0, j = strlen(ip) - 1;
    while (i < j) {
        if (ip[i] == '.' && ip[j]!= '.') {
            return 0;
        }
        if (ip[i]!= '.' && ip[j] == '.') {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

// function to calculate subnet mask
void subnetCalc(char* ip, char* mask) {
    int i = 0, j = 0;
    while (ip[i]!= '.') {
        i++;
    }
    while (mask[j]!= '.') {
        j++;
    }
    int firstOctet = atoi(ip);
    int subnetBits = atoi(mask);
    int subnetMask = 0;
    int hostBits = 32 - subnetBits;
    int subnet = firstOctet & ~((1 << subnetBits) - 1);
    int broadcast = subnet + (1 << hostBits) - 1;
    printf("Subnet mask: %s\n", mask);
    printf("Subnet IP: %d.%d.%d.%d\n", (subnet >> 24) & 0xFF, (subnet >> 16) & 0xFF, (subnet >> 8) & 0xFF, subnet & 0xFF);
    printf("Broadcast IP: %d.%d.%d.%d\n", (broadcast >> 24) & 0xFF, (broadcast >> 16) & 0xFF, (broadcast >> 8) & 0xFF, broadcast & 0xFF);
}

int main() {
    char ip[16], mask[16];
    printf("Enter IP address: ");
    scanf("%s", ip);
    printf("Enter subnet mask: ");
    scanf("%s", mask);
    if (validateIP(ip) && validateIP(mask)) {
        subnetCalc(ip, mask);
    }
    return 0;
}