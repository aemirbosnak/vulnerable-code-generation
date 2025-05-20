//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Dennis Ritchie
#include <stdio.h>

typedef struct {
    unsigned int address;
    unsigned int subnetMask;
    unsigned int networkAddress;
    unsigned int broadcastAddress;
    unsigned int totalHosts;
} SubnetInfo;

unsigned int promptForIP(char *message);
unsigned int promptForMask(char *message);
void printSubnetInfo(SubnetInfo subnet);

int main()
{
    printf("Welcome to the Subnet Calculator!\n\n");

    unsigned int ipAddress = promptForIP("Enter IP Address: ");
    unsigned int subnetMask = promptForMask("Enter Subnet Mask: ");

    SubnetInfo subnet = {
        ipAddress,
        subnetMask,
        ipAddress & subnetMask,
        (ipAddress & subnetMask) | ~subnetMask,
        ~subnetMask
    };

    printSubnetInfo(subnet);

    return 0;
}

unsigned int promptForIP(char *message)
{
    unsigned int ip;
    printf("%s", message);
    scanf("%u", &ip);
    return ip;
}

unsigned int promptForMask(char *message)
{
    unsigned int mask;
    printf("%s", message);
    scanf("%u", &mask);
    return mask;
}

void printSubnetInfo(SubnetInfo subnet)
{
    printf("Address: %u\n", subnet.address);
    printf("Subnet Mask: %u\n", subnet.subnetMask);
    printf("Network Address: %u\n", subnet.networkAddress);
    printf("Broadcast Address: %u\n", subnet.broadcastAddress);
    printf("Total Hosts: %u\n", subnet.totalHosts);
}