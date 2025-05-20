//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_IP_ADDRESS_LEN 16

typedef struct {
    int octet1;
    int octet2;
    int octet3;
    int octet4;
} IPAddress;

typedef struct {
    IPAddress networkAddress;
    IPAddress subnetMask;
    IPAddress firstHostAddress;
    IPAddress lastHostAddress;
    unsigned int hostsPerSubnet;
} SubnetInfo;

IPAddress inputIPAddress() {
    char ipAddress[MAX_IP_ADDRESS_LEN];

    printf("Enter IP address: ");
    scanf("%s", ipAddress);

    IPAddress ip;
    sscanf(ipAddress, "%d.%d.%d.%d", &ip.octet1, &ip.octet2, &ip.octet3, &ip.octet4);
    return ip;
}

int getPrefixLength() {
    int prefixLength;

    printf("Enter prefix length: ");
    scanf("%d", &prefixLength);

    return prefixLength;
}

void printIPAddress(IPAddress ip) {
    printf("%d.%d.%d.%d", ip.octet1, ip.octet2, ip.octet3, ip.octet4);
}

void printSubnetInfo(SubnetInfo info) {
    printf("Network address: ");
    printIPAddress(info.networkAddress);
    printf("\n");

    printf("Subnet mask: ");
    printIPAddress(info.subnetMask);
    printf("\n");

    printf("First host address: ");
    printIPAddress(info.firstHostAddress);
    printf("\n");

    printf("Last host address: ");
    printIPAddress(info.lastHostAddress);
    printf("\n");

    printf("Number of hosts: %u", info.hostsPerSubnet);
    printf("\n");
}

void calculateSubnetInfo(IPAddress ipAddress, int prefixLength, SubnetInfo *info) {
    unsigned int subnetMask = 0xFFFFFFFF << (32 - prefixLength);

    info->networkAddress.octet1 = ipAddress.octet1 & (subnetMask >> 24);
    info->networkAddress.octet2 = ipAddress.octet2 & (subnetMask >> 16);
    info->networkAddress.octet3 = ipAddress.octet3 & (subnetMask >> 8);
    info->networkAddress.octet4 = ipAddress.octet4 & subnetMask;

    info->subnetMask.octet1 = (subnetMask >> 24) & 0xFF;
    info->subnetMask.octet2 = (subnetMask >> 16) & 0xFF;
    info->subnetMask.octet3 = (subnetMask >> 8) & 0xFF;
    info->subnetMask.octet4 = subnetMask & 0xFF;

    info->hostsPerSubnet = (1 << (32 - prefixLength)) - 2;

    info->firstHostAddress = info->networkAddress;
    info->firstHostAddress.octet4 += 1;

    info->lastHostAddress = info->networkAddress;
    info->lastHostAddress.octet4 += info->hostsPerSubnet + 1;
}

int main() {
    IPAddress ipAddress;
    int prefixLength;
    SubnetInfo info;

    ipAddress = inputIPAddress();
    prefixLength = getPrefixLength();

    calculateSubnetInfo(ipAddress, prefixLength, &info);

    printf("\nSubnet Information:\n");
    printSubnetInfo(info);

    return 0;
}