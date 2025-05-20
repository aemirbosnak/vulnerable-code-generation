//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IP_LENGTH 15
#define MAX_SUBNET_LENGTH 2
#define MAX_NETMASK_LENGTH 20
#define MAX_BROADCAST_LENGTH 15

typedef struct {
    unsigned int octets[4];
    unsigned int subnetMask; // in CIDR format
    unsigned int networkAddress[4];
    unsigned int broadcastAddress[4];
    unsigned int hostCount;
} SubnetInfo;

void calculateSubnet(SubnetInfo *subnetInfo, const char *ip, const char *subnetMask) {
    int i;

    // Convert IP address to unsigned int array
    sscanf(ip, "%u.%u.%u.%u", &subnetInfo->octets[0], &subnetInfo->octets[1], &subnetInfo->octets[2], &subnetInfo->octets[3]);
    subnetInfo->subnetMask = atoi(subnetMask);

    // Calculate network address
    for (i = 0; i < 4; i++) {
        subnetInfo->networkAddress[i] = subnetInfo->octets[i] & (255 << (8 * (3 - i))); // subnet mask part
    }

    // Calculate broadcast address
    for (i = 0; i < 4; i++) {
        subnetInfo->broadcastAddress[i] = subnetInfo->networkAddress[i] | (255 >> (subnetInfo->subnetMask % 8)); // broadcast part
    }

    // Calculate host count based on the subnet mask
    subnetInfo->hostCount = (1 << (32 - subnetInfo->subnetMask)) - 2;
}

void printSubnetInfo(const SubnetInfo *subnetInfo) {
    printf("IP Address: %u.%u.%u.%u\n", subnetInfo->octets[0], subnetInfo->octets[1], subnetInfo->octets[2], subnetInfo->octets[3]);
    printf("Subnet Mask: /%u\n", subnetInfo->subnetMask);
    printf("Network Address: %u.%u.%u.%u\n", subnetInfo->networkAddress[0], subnetInfo->networkAddress[1], subnetInfo->networkAddress[2], subnetInfo->networkAddress[3]);
    printf("Broadcast Address: %u.%u.%u.%u\n", subnetInfo->broadcastAddress[0], subnetInfo->broadcastAddress[1], subnetInfo->broadcastAddress[2], subnetInfo->broadcastAddress[3]);
    printf("Number of Hosts: %u\n", subnetInfo->hostCount);
}

void requestUserInput(char *ip, char *subnetMask) {
    printf("Enter IP Address (e.g., 192.168.1.1): ");
    fgets(ip, MAX_IP_LENGTH + 1, stdin);
    strtok(ip, "\n"); // Remove newline character

    printf("Enter Subnet Mask (CIDR format e.g., 24): ");
    fgets(subnetMask, MAX_SUBNET_LENGTH + 1, stdin);
    strtok(subnetMask, "\n"); // Remove newline character
}

int main() {
    SubnetInfo subnetInfo;
    char ip[MAX_IP_LENGTH + 1];
    char subnetMask[MAX_SUBNET_LENGTH + 1];

    requestUserInput(ip, subnetMask);
    
    calculateSubnet(&subnetInfo, ip, subnetMask);
    printSubnetInfo(&subnetInfo);

    return 0;
}