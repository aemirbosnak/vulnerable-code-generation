//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LENGTH 16
#define MAX_SUBNET_LENGTH 3

int isValidIpAddress(char *ipAddress) {
    int count = 0;
    char *token = strtok(ipAddress, ".");
    while (token != NULL) {
        int num = atoi(token);
        if (num < 0 || num > 255) {
            return 0;
        }
        count++;
        token = strtok(NULL, ".");
    }
    if (count != 4) {
        return 0;
    }
    return 1;
}

int isValidSubnet(char *subnet) {
    int count = 0;
    char *token = strtok(subnet, "/");
    while (token != NULL) {
        int num = atoi(token);
        if (num < 0 || num > 32) {
            return 0;
        }
        count++;
        token = strtok(NULL, "/");
    }
    if (count != 2) {
        return 0;
    }
    return 1;
}

int countBits(int num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int main() {
    char ipAddress[MAX_IP_LENGTH];
    char subnet[MAX_SUBNET_LENGTH];
    printf("Enter IP address: ");
    scanf("%s", ipAddress);
    printf("Enter subnet: ");
    scanf("%s", subnet);
    if (!isValidIpAddress(ipAddress) || !isValidSubnet(subnet)) {
        printf("Invalid input!\n");
        return -1;
    }
    int ip[4];
    sscanf(ipAddress, "%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
    int subnetLength;
    sscanf(subnet, "%*d/%d", &subnetLength);
    int mask = 0xffffffff << (32 - subnetLength);
    int network[4];
    for (int i = 0; i < 4; i++) {
        network[i] = ip[i] & (mask >> 8 * (3 - i));
    }
    printf("Network address: %d.%d.%d.%d\n", network[0], network[1], network[2], network[3]);
    int hosts = 1 << (32 - subnetLength) - 2;
    printf("Number of hosts: %d\n", hosts);
    int maxSubnets = 1 << subnetLength;
    printf("Number of subnets: %d\n", maxSubnets);
    int minSubnetMask = 0;
    int minSubnetBits = 0;
    for (int i = 1; i < maxSubnets; i <<= 1) {
        if ((i & mask) == i) {
            minSubnetMask = i;
            minSubnetBits = countBits(minSubnetMask);
        } else {
            break;
        }
    }
    printf("Minimum subnet mask: /%d\n", subnetLength + minSubnetBits);
    return 0;
}